#include "NexisLoggerSpd.h"

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


void nexis::NexisLoggerSpd::setConfig(DataObject config) {
    if(config.isDictionary() && config.hasKey("logger")) {
        DataObject * loggerConfig = &config.asDictionary()["logger"];
        if(loggerConfig->isDictionary()) {

            if(loggerConfig->hasKey("level") && loggerConfig->asDictionary()["level"].isString()) {
                std::string level = loggerConfig->asDictionary()["level"].asString();
                if(level == "trace" || level == "debug" || level == "info" || level == "warn" || level == "error" || level == "critical") {
                    this->nexisLogger->set_level(spdlog::level::from_str(level));
                } else {
                    this->warn("Invalid log level: " + level);
                }
            }
            
            if(loggerConfig->hasKey("format") && loggerConfig->asDictionary()["format"].isString()) {
                std::string format = loggerConfig->asDictionary()["format"].asString();
                try {
                    this->nexisLogger->set_pattern(format);
                } catch (const spdlog::spdlog_ex &ex) {
                    this->warn("Invalid log format: " + format);
                }
            }
        }
    }
}