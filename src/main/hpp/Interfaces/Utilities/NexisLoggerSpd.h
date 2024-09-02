#ifndef NEXIS_LOGGER_SPD_H
#define NEXIS_LOGGER_SPD_H

#include <string>
#include <NexisLogger.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "spdlog/sinks/stdout_color_sinks.h" // Für das Loggen in die Konsole


namespace nexis {

    class NexisLoggerSpd : public NexisLogger {
        private:
            std::shared_ptr<spdlog::logger> nexisLogger;
        public:
            
            NexisLoggerSpd(const std::string logName, const std::vector<std::string> logFiles, const std::string logFormat, const std::string logLevel);
            
            virtual ~NexisLoggerSpd() = default;

            // Loggt eine Nachricht auf dem TRACE-Level
            void trace(const std::string& message) override;

            // Loggt eine Nachricht auf dem DEBUG-Level
            void debug(const std::string& message) override;

            // Loggt eine Nachricht auf dem INFO-Level
            void info(const std::string& message) override;

            // Loggt eine Nachricht auf dem WARN-Level
            void warn(const std::string& message) override;

            // Loggt eine Nachricht auf dem ERROR-Level
            void err(const std::string& message) override;

            // Loggt eine Nachricht auf dem CRITICAL-Level
            void crit(const std::string& message) override;

            void setLogLevel(spdlog::level::level_enum level);

            void setPattern(const std::string& pattern);

    };
    
} // namespace nexis

#endif // NEXIS_LOGGER_SPD_H