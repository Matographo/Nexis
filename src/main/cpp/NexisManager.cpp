#include "NexisManager.h"

NexisManager::NexisManager(int argc, char** argv) {
    this->logger   = new nexis::NexisLoggerSpd("NexisLogger", "%v", "info");
    this->program  = new argparse::ArgumentParser("nex");
    this->userPath = std::filesystem::current_path().string();
    this->setArguments(argc, argv);
}

NexisManager::~NexisManager() {
    if(this->buildManager != nullptr) {
        delete this->buildManager;
    }
    if(this->config != nullptr) {
        delete this->config;
    }
    spdlog::shutdown();
}

void NexisManager::startMessage() {
    this->logger->info("");
    this->logger->info("------------------------------------------------------------------------");
    this->logger->setFormat("%^%v%$");
    this->logger->info(" Starting Nexis Build...");
    this->logger->setFormat("%v");
    this->logger->info("------------------------------------------------------------------------");
    this->logger->info("");
    this->logger->setFormat("%^%v%$");
}

void NexisManager::endMessage(int returnCode) {
    this->buildTime.stop = std::chrono::high_resolution_clock::now();
    this->logger->setFormat("%v");
    this->logger->setColors("info", "green");
    this->logger->setColors("err", "red");
    this->logger->info("");
    this->logger->info("------------------------------------------------------------------------");
    this->logger->setFormat("%^%v%$");
    if(returnCode == 0) {
        this->logger->info(" BUILD SUCCESSFUL ");
    } else {
        this->logger->err(" BUILD FAILED ");
    }
    this->logger->setFormat("%v");
    this->logger->info(" Total time: " + this->calcBulidTime());
    this->logger->info(" Finished at: " + this->calcEndTime());
    this->logger->info("------------------------------------------------------------------------");
    this->logger->info("");
}

std::string NexisManager::calcBulidTime() {
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(this->buildTime.stop - this->buildTime.start);
    return formatDuration(duration);
}

std::string NexisManager::calcEndTime() {
    std::time_t now = std::chrono::system_clock::to_time_t(this->buildTime.stop);
    std::tm * ptm = std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(ptm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void NexisManager::setArguments(int argc, char** argv) {
    
    argparse::ArgumentParser* phases         = new argparse::ArgumentParser("phase");
    argparse::ArgumentParser* projectBuilder = new argparse::ArgumentParser("init");

    phases->add_argument("action")
        .help("Lifecycle action to perform")
        .choices("validate", "compile", "test", "package", "deploy", "clean", "run", "install")
        .nargs(argparse::nargs_pattern::at_least_one);
    
    phases->add_argument("-x", "--debug")
        .help("Enable debug mode")
        .flag();
    
    phases->add_argument("-X", "--trace")
        .help("Enable trace mode")
        .flag();

    phases->add_argument("-q", "--quiet")
        .help("Quiet output, only show errors")
        .flag();
    
    phases->add_argument("-w", "--warn")
        .help("Warn output, show warnings and errors")
        .flag();
    
    projectBuilder->add_argument("-n", "--name")
        .help("Project name");
    
    projectBuilder->add_argument("-l", "--language")
        .help("Project language(s)")
        .nargs(argparse::nargs_pattern::any);
    
    projectBuilder->add_argument("-t", "--type")
        .help("Project type for the output")
        .default_value("program");
    
    projectBuilder->add_argument("-D", "--directory")
        .help("Project directory to create");
    
    projectBuilder->add_argument("-h", "--help")
        .help("Show help message for project initialization")
        .flag();
    
    projectBuilder->add_argument("-T", "--template")
        .help("Project template to use")
        .default_value("default");
    
    this->program->add_description("Nexis build tool");
    this->program->add_subparser(*phases);
    this->program->add_subparser(*projectBuilder);
    
    this->phases         = phases;
    this->projectBuilder = projectBuilder;
    
    try {
        this->program->parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        throw new std::runtime_error(err.what());
        return;
    }

}

int NexisManager::makeChoice() {
    if(this->program->is_subcommand_used("init")) {
        return this->createProject();
    } 
    
    this->startMessage();
    
    this->loadConfig();
    this->processConfig();
    
    int result = 0;
    
    if(this->program->is_subcommand_used("phase")) {
        result = this->executeLifecycle();
    }
    
    this->endMessage(result);
    
    return 0;
}

void NexisManager::loadConfig() {
    if(!std::filesystem::exists(this->userPath + "/build.yaml")) {
        this->logger->err("build.yaml could not be found");
        this->logger->err("Please make sure that you are in the root directory of your project.");
        throw std::runtime_error("build.yaml could not be found");
    }
    try {
        DataObject * configuation = new DataObject(parseYaml(this->userPath + "/build.yaml"));
        this->config = configuation;
        return;
    } catch (std::runtime_error & e) {
        logger->err(e.what());
        throw std::runtime_error("build.yaml could not be loaded");
    }
}

void NexisManager::processConfig() {
    if(!this->config->isDictionary()) {
        throw new std::runtime_error("build.yaml is not a valid configuration file");
    }
    if(!this->config->hasKey("type") || !this->config->asDictionary()["type"].isString()) {
        throw new std::runtime_error("Project type is not defined in build.yaml");
    }
    if(!this->config->hasKey("language")) {
        throw new std::runtime_error("Project language is not defined in build.yaml");
    }
    
    if(!this->config->hasKey("logger") || !this->config->asDictionary().at("logger").isDictionary()) {
        return;
    }

    DataObject * loggerConfig = &this->config->asDictionary().at("logger");

    if(loggerConfig->hasKey("format") && loggerConfig->asDictionary()["format"].isString()) {
        std::string format = loggerConfig->asDictionary()["format"].asString();
        try {
            this->logger->setFormat(format);
        } catch (const spdlog::spdlog_ex &ex) {
            this->logger->warn("Invalid log format: " + format);
        }
    }
    
    if(loggerConfig->hasKey("colors") && loggerConfig->asDictionary()["colors"].isDictionary()) {
        DataObject * colors = &loggerConfig->asDictionary()["colors"];
        for(auto & color : colors->asDictionary()) {
            if(color.second.isString()) {
                this->logger->setColors(color.first, color.second.asString());
            }
        }
    }

    if(loggerConfig->hasKey("level") && loggerConfig->asDictionary()["level"].isString()) {
        std::string level = loggerConfig->asDictionary()["level"].asString();
        if(level == "trace" || level == "debug" || level == "info" || level == "warn" || level == "error" || level == "critical") {
            this->logger->setLevel(level);
        } else {
            this->logger->warn("Invalid log level: " + level);
        }
    }

}

int NexisManager::createProject() {
    if(this->projectBuilder->is_used("help")) {
        std::cout << this->projectBuilder->help().str();
        return 0;
    }
    std::string projectName = "";
    std::string projectType = "";
    std::vector<std::string> projectLanguage;
    std::string projectDirectory = "";
    std::string projectTemplate = "";

    if(this->projectBuilder->is_used("name")) {
        projectName = this->projectBuilder->get<std::string>("name");
    }
    if(this->projectBuilder->is_used("template")) {
        projectTemplate = this->projectBuilder->get<std::string>("template");
        std::string home = std::getenv("HOME");
        projectTemplate = home + "/.nexis/templates/" + projectTemplate;
        if(!std::filesystem::exists(projectTemplate) || !std::filesystem::is_directory(projectTemplate)) {
            std::cout << "Template not found" << std::endl;
            return 1;
        } 
    }
    if(this->projectBuilder->is_used("type") && projectTemplate == "") {
        projectType = this->projectBuilder->get<std::string>("type");
    }
    if(this->projectBuilder->is_used("language") && projectTemplate == "") {
        projectLanguage = this->projectBuilder->get<std::vector<std::string>>("language");
    }
    if(this->projectBuilder->is_used("directory")) {
        projectDirectory = this->projectBuilder->get<std::string>("directory");
    }
    
    


    if(projectName == "") {
        std::cout << "Project name: ";
        std::getline(std::cin, projectName);
    }

    if(projectTemplate == "") {
        std::cout << "Do you want to use a project template? (y/n): ";
        std::string choice;
        std::getline(std::cin, choice);
        if(choice == "y") {
            std::cout << "Project template: ";
            std::getline(std::cin, projectTemplate);
            std::string home = std::getenv("HOME");
            projectTemplate = home + "/.nexis/templates/" + projectTemplate;
            if(!std::filesystem::exists(projectTemplate) || !std::filesystem::is_directory(projectTemplate)) {
                std::cout << "Template not found" << std::endl;
                return 1;
            } 

        } 
    }
    
    
    if(projectType == "" && projectTemplate == "") {
        std::cout << "project types are: program, library" << std::endl;
        std::cout << "Project type: ";
        std::getline(std::cin, projectType);
    }
    
    if(projectLanguage.empty() && projectTemplate == "") {
        std::cout << "Project language: ";
        std::string lang;
        std::getline(std::cin, lang);
        projectLanguage.push_back(lang);
    }
    
    if(projectDirectory == "") {
        std::cout << "Do you want to create the project in the current directory? (y/n): ";
        std::string choice;
        std::getline(std::cin, choice);
        if(choice == "n") {
            std::cout << "Project directory: ";
            std::getline(std::cin, projectDirectory);
        } else if(choice == "y") {
            projectDirectory = this->userPath;
        } else {
            std::cout << "Invalid choice" << std::endl;
            return 1;
        }
    }
    ProjectCreator projectCreator(this->logger);
    projectCreator.createProject(projectName, projectDirectory, projectType, projectLanguage, projectTemplate);
    return 0;
}

int NexisManager::executeLifecycle() {
    std::vector<std::string> actions = this->phases->get<std::vector<std::string>>("action");
    bool debug = this->phases->get<bool>("debug");
    bool trace = this->phases->get<bool>("trace");
    bool quiet = this->phases->get<bool>("quiet");
    bool warn  = this->phases->get<bool>("warn");
    
    if(debug + trace + quiet + warn > 1) {
        this->logger->warn("Multiple output flags for the Logger are set, only one can be used at a time");
        return 1;
    }
    if(debug) {
        this->logger->setLevel("debug");
    } else if(trace) {
        this->logger->setLevel("trace");
    } else if(quiet) {
        this->logger->setLevel("error");
    } else if(warn) {
        this->logger->setLevel("warn");
    }
    
    std::vector<int> actionsExec;
    
    for(auto & action : actions) {
        int actionExec = this->getLifecycle(action);
        if(actionExec == -1) {
            return 1;
        }
        actionsExec.push_back(actionExec);
    }
    
    int returnCode = 0;
    this->buildManager = new BuildManager();
    if(returnCode == 0) returnCode = this->buildManager->loadBuildFile();
    if(returnCode == 0) returnCode = this->buildManager->processConfigs();
    if(returnCode == 0) returnCode = this->buildManager->loadPlugins();
    if(returnCode == 0) returnCode = this->buildManager->loadDependencies();
    
    for(auto & action : actionsExec) {
        if(returnCode == 0) returnCode = this->buildManager->executeTasks(action);
    }

    return returnCode;
}

int NexisManager::getLifecycle(std::string phase) {
    if(phase == "validate") {
        return 4;
    } else if(phase == "compile") {
        return 12;
    } else if(phase == "test") {
        return 28;
    } else if(phase == "package") {
        return 60;
    } else if(phase == "deploy") {
        return 124;
    } else if(phase == "clean") {
        return 1;
    } else if(phase == "run") {
        return 2;
    } else if(phase == "install") {
        logger->err("Install is not yet implemented");
        return -1;
    } else {
        logger->err("Invalid lifecycle action: " + phase);
        return -1;
    }
}