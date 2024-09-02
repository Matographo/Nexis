#include "NexisLoggerSpd.h"

nexis::NexisLoggerSpd::NexisLoggerSpd(const std::string logName, const std::vector<std::string> logFiles, const std::string logFormat, const std::string logLevel) {
    // Erstelle den Datei-Sink
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFiles[0], true);
    file_sink->set_pattern(logFormat); // Setze das Pattern für die Datei

    // Erstelle den Konsolen-Sink (mit Farben)
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_pattern(logFormat); // Setze ein anderes Pattern für die Konsole

    // Kombiniere die Sinks zu einem Logger
    std::vector<spdlog::sink_ptr> sinks {file_sink, console_sink};
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

void nexis::NexisLoggerSpd::setLogLevel(spdlog::level::level_enum level) {
    this->nexisLogger->set_level(level);
}

void nexis::NexisLoggerSpd::setPattern(const std::string& pattern) {
    this->nexisLogger->set_pattern(pattern);
}