#include "Interfaces/Utilities/NexisLoggerSpd.h"

nexis::NexisLoggerSpd::NexisLoggerSpd(const std::string logName, const std::string logFormat, const std::string logLevel) {
    // Erstelle den Konsolen-Sink (mit Farben)
    this->nexis_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    this->nexis_sink->set_pattern(logFormat); // Setze ein anderes Pattern für die Konsole

    // Kombiniere die Sinks zu einem Logger
    std::vector<spdlog::sink_ptr> sinks {this->nexis_sink};
    this->nexisLogger = std::make_shared<spdlog::logger>(logName, sinks.begin(), sinks.end());

    // Setze das Log-Level
    this->nexisLogger->set_level(spdlog::level::from_str(logLevel));
}



void nexis::NexisLoggerSpd::trace(const std::string& message) {
    this->nexisLogger->trace(message);
}



void nexis::NexisLoggerSpd::debug(const std::string& message) {
    this->nexisLogger->debug(message);
}



void nexis::NexisLoggerSpd::info(const std::string& message) {
    this->nexisLogger->info(message);
}



void nexis::NexisLoggerSpd::warn(const std::string& message) {
    this->nexisLogger->warn(message);
}



void nexis::NexisLoggerSpd::err(const std::string& message) {
    this->nexisLogger->error(message);
}



void nexis::NexisLoggerSpd::crit(const std::string& message) {
    this->nexisLogger->critical(message);
}


void nexis::NexisLoggerSpd::setConfig(DataObject * config) {
    if(config->hasKey("level") && config->asDictionary()["level"].isString()) {
        std::string level = config->asDictionary()["level"].asString();
        if(level == "trace" || level == "debug" || level == "info" || level == "warn" || level == "error" || level == "critical") {
            this->nexisLogger->set_level(spdlog::level::from_str(level));
        } else {
            this->warn("Invalid log level: " + level);
        }
    }
    
    if(config->hasKey("format") && config->asDictionary()["format"].isString()) {
        std::string format = config->asDictionary()["format"].asString();
        try {
            this->nexisLogger->set_pattern(format);
        } catch (const spdlog::spdlog_ex &ex) {
            this->warn("Invalid log format: " + format);
        }
    }
    
    if(config->hasKey("colors") && config->asDictionary()["colors"].isDictionary()) {
        DataObject * colors = &config->asDictionary()["colors"];
        for(auto & color : colors->asDictionary()) {
            if(color.second.isString()) {
                this->setColors(color.first, color.second.asString());
            }
        }
    }
}

void nexis::NexisLoggerSpd::setLevel(const std::string& level) {
    this->nexisLogger->set_level(spdlog::level::from_str(level));
}

void nexis::NexisLoggerSpd::setFormat(const std::string& format) {
    this->nexisLogger->set_pattern(format);
}

void nexis::NexisLoggerSpd::setColors(const std::string& level, const std::string& color) {
    if(color == "black") {
        this->nexis_sink->set_color(spdlog::level::from_str(level), this->nexis_sink->black);
    } else if (color == "red") {
        this->nexis_sink->set_color(spdlog::level::from_str(level), this->nexis_sink->red);
    } else if (color == "green") {
        this->nexis_sink->set_color(spdlog::level::from_str(level), this->nexis_sink->green);
    } else if (color == "yellow") {
        this->nexis_sink->set_color(spdlog::level::from_str(level), this->nexis_sink->yellow);
    } else if (color == "blue") {
        this->nexis_sink->set_color(spdlog::level::from_str(level), this->nexis_sink->blue);
    } else if (color == "magenta") {
        this->nexis_sink->set_color(spdlog::level::from_str(level), this->nexis_sink->magenta);
    } else if (color == "cyan") {
        this->nexis_sink->set_color(spdlog::level::from_str(level), this->nexis_sink->cyan);
    } else if (color == "white") {
        this->nexis_sink->set_color(spdlog::level::from_str(level), this->nexis_sink->white);
    } else if (color == "yellow bold") {
        this->nexis_sink->set_color(spdlog::level::from_str(level), this->nexis_sink->yellow_bold);
    } else if (color == "red bold") {
        this->nexis_sink->set_color(spdlog::level::from_str(level), this->nexis_sink->red_bold);
    } else {
        this->warn("Invalid color: " + color);
    }
   
}

void nexis::NexisLoggerSpd::setColors(DataObject * config) {
    if(config->isDictionary()) {
        if(config->hasKey("colors") && config->asDictionary()["colors"].isDictionary()) {
            DataObject * colors = &config->asDictionary()["colors"];
            for(auto & color : colors->asDictionary()) {
                if(color.second.isString()) {
                    this->setColors(color.first, color.second.asString());
                }
            }
        }
    }
}