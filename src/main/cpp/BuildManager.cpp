#include "BuildManager.h"

BuildManager::BuildManager() {
    this->buildTime.start = std::chrono::high_resolution_clock::now();
    this->projectPath     = std::filesystem::current_path().string();
    this->logger          = new nexis::NexisLoggerSpd("NexisLogger", "%v", "info");
    this->plugins         = new PluginStruct();
}

BuildManager::~BuildManager() {
}

void BuildManager::startMessage() {
    this->logger->info("");
    this->logger->info("------------------------------------------------------------------------");
    this->logger->setFormat("%^%v%$");
    this->logger->info(" Starting Nexis Build...");
    this->logger->setFormat("%v");
    this->logger->info("------------------------------------------------------------------------");
    this->logger->info("");
    this->logger->setFormat("%^%v%$");
}

void BuildManager::endMessage(int returnCode) {
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

std::string BuildManager::calcBulidTime() {
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(this->buildTime.stop - this->buildTime.start);
    return formatDuration(duration);
}

std::string BuildManager::calcEndTime() {
    std::time_t now = std::chrono::system_clock::to_time_t(this->buildTime.stop);
    std::tm * ptm = std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(ptm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

int BuildManager::loadBuildFile() {
    if(!std::filesystem::exists(this->projectPath + "/build.yaml")) {
        this->logger->err("build.yaml could not be found");
        this->logger->err("Please make sure that you are in the root directory of your project.");
        return 1;
    }
    try {
        DataObject * configuation = new DataObject(parseYaml(this->projectPath + "/build.yaml"));
        this->config = configuation;
        if(this->config == nullptr) {
            this->logger->err("build.yaml could not be loaded");
            return 1;
        }
        return 0;
    } catch (std::runtime_error & e) {
        logger->err("build.yaml could not be loaded");
        return 1;
    }
}

int BuildManager::processConfigs() {
    if(this->checkConfig() != 0) {
        this->logger->err("Invalid Configurations");
        return 1;
    }
    this->loadLoggerConfig();
    this->loadAttributes();
    return 0;
}

int BuildManager::checkConfig() {
    if(!this->config->isDictionary()) {
        this->logger->err("build.yaml is not a valid configuration file");
        return 1;
    }
    if(!this->config->hasKey("type") || !this->config->asDictionary()["type"].isString()) {
        this->logger->err("Project type is not defined in build.yaml");
        return 1;
    }
    if(!this->config->hasKey("language")) {
        this->logger->err("Language is not defined in build.yaml");
        return 1;
    }
    return 0;
}

void BuildManager::loadAttributes() {
    this->config->addToDictionary("projectPath", DataObject::createString(this->projectPath));
    if(this->config->hasKey("type") && this->config->asDictionary()["type"].isString()) {
        this->projectType = this->config->asDictionary()["type"].asString();
    }
    this->loadExecuterConfig();
    this->loadPluginsConfig();
}

void BuildManager::loadPluginsConfig() {
    if(!this->config->hasKey("plugins")) {
        return;
    }

    DataObject * pluginsConfig = &this->config->asDictionary()["plugins"];
    if(!pluginsConfig->isDictionary()) {
        this->logger->err("Invalid plugins configuration");
        return;
    }
    
    std::vector<std::tuple<std::string, DataObject>> pluginConfigList;
    
    std::vector<DataObject> languageList;
    
    if(this->config->asDictionary()["language"].isString()) {
        languageList.push_back(this->config->asDictionary()["language"]);
    } else if(this->config->asDictionary()["language"].isList()) {
        languageList = this->config->asDictionary()["language"].asList();
    } else {
        this->logger->err("Invalid language configuration");
        return;
    }
    
    for(auto& language : languageList) {
        if(!pluginsConfig->hasKey(language.asString())) {
            return;
        }
        DataObject * languageConfig = &pluginsConfig->asDictionary()[language.asString()];
        if(!languageConfig->isList()) {
            this->logger->err("Invalid language configuration");
            return;
        }
        
        for(auto& plugin : languageConfig->asList()) {
            if(!plugin.isDictionary()) {
                this->logger->err("Invalid plugin configuration");
                return;
            }
            if(!plugin.hasKey("name") || !plugin.hasKey("version")) {
                this->logger->err("Plugin Name or Version not defined");
                return;
            }
            pluginConfigList.push_back(std::make_tuple(language.asString(), plugin));
        }

    }
    
    for(auto& pluginLanguage : languageList) {
        DataObject * plugins = &pluginsConfig->asDictionary()[pluginLanguage.asString()];
        if(!plugins->isList()) {
            this->logger->err("Invalid plugin configuration");
            return;
        }
        
        for(auto& plugin : plugins->asList()) {
            if(!plugin.isDictionary()) {
                this->logger->err("Invalid plugin configuration");
                return;
            }
            if(!plugin.hasKey("name") || !plugin.hasKey("version")) {
                this->logger->err("Plugin Name or Version not defined");
                return;
            }
            std::string pluginName = plugin.asDictionary()["name"].asString();
            std::string pluginVersion = plugin.asDictionary()["version"].asString();
            std::string homePath = std::getenv("HOME");
            std::string pluginPath = homePath + "/.nexis/plugins/" + this->projectType + "/" + pluginLanguage.asString() + "/" + pluginName + "/" + pluginVersion + "/" + pluginName + ".so";
            this->pluginPaths.push_back(std::make_tuple(pluginPath, &plugin));
        }
        

    }
}

void BuildManager::loadExecuterConfig() {
    DataObject * executerConfig;
    if(this->config->hasKey("executer")) {
        executerConfig = &this->config->asDictionary()["executer"];
    } else if(this->config->hasKey("compiler")) {
        executerConfig = &this->config->asDictionary()["compiler"];
    } else {
        return;
    }
    if(!executerConfig->isDictionary()) {
        this->logger->err("Invalid executer configuration");
        return;
    }
    std::vector<std::tuple<std::string, DataObject>> executerConfigList;
    
    std::vector<DataObject> languageList;
    
    if(this->config->asDictionary()["language"].isString()) {
        languageList.push_back(this->config->asDictionary()["language"]);
    } else if(this->config->asDictionary()["language"].isList()) {
        languageList = this->config->asDictionary()["language"].asList();
    } else {
        this->logger->err("Invalid language configuration");
        return;
    }
    
    for(auto& language : languageList) {
        if(!executerConfig->hasKey(language.asString())) {
            this->logger->err("Executer configuration for " + language.asString() + " is not defined");
            return;
        }
        DataObject * languageConfig = &executerConfig->asDictionary()[language.asString()];
        if(!languageConfig->isDictionary()) {
            this->logger->err("Invalid language configuration");
            return;
        }
        if(!languageConfig->hasKey("name") || !languageConfig->hasKey("version")) {
            this->logger->err("Executer Name or Version is not defined");
            return;
        }
        executerConfigList.push_back(std::make_tuple(language.asString(), *languageConfig));
    }
    
    for(auto& language : executerConfigList) {
        std::string executerName = std::get<1>(language).asDictionary()["name"].asString();
        std::string executerVersion = std::get<1>(language).asDictionary()["version"].asString();
        std::string homePath = std::getenv("HOME");
        std::string executerPath = homePath + "/.nexis/executer/" + this->projectType + "/" + std::get<0>(language) + "/" + executerName + "/" + executerVersion + "/" + executerName + ".so";
        
        DataObject * uniqueConfig = &std::get<1>(language);
        this->pluginPaths.push_back(std::make_tuple(executerPath, uniqueConfig));
    }
}

void BuildManager::loadLoggerConfig() {
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

int BuildManager::loadPlugins() {
    nexis::NexisLogger * pluginLogger = this->logger;
    PluginCaster pluginCaster(pluginLogger, this->plugins);
    for(std::tuple<std::string, DataObject*>& pluginTuple : this->pluginPaths) {
        std::string pluginPath = std::get<0>(pluginTuple);
        const DataObject * pluginConfig = std::get<1>(pluginTuple);
        NexisPlugin* plugin = loadDynamicLibrary(pluginPath, pluginLogger, this->config);
        
        if(plugin == nullptr) {
            this->logger->err("Could not load Plugin: " + pluginPath);
        }
        this->pluginsS.push_back(new NexisPlugin(*plugin));
        
        if(pluginCaster.castPlugin(plugin) != 0) {
            this->logger->err("Could not cast Plugin: " + pluginPath);
            return 1;
        }
    }
    return 0;
}

int BuildManager::loadDependencies() {
    return 0;
}

int BuildManager::executeTasks(int lifecycleTasks) {
    LifecycleExecuter lifecycleExecuter(this->plugins, this->logger);
    int result = lifecycleExecuter.startLifecycle(lifecycleTasks);
    if(result != 0) {
        this->logger->err("There Occurred an Error in Build Cycle");
    }
    return result;
}

std::string BuildManager::getProjectType() {
    return this->projectType;
}