#ifndef NEXIS_LOGGER_SPD_H
#define NEXIS_LOGGER_SPD_H

#include <string>
#include <memory>
#include <NexisLogger.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "DataObject.h"
#include "spdlog/sinks/stdout_color_sinks.h" // Für das Loggen in die Konsole


namespace nexis {

    class NexisLoggerSpd : public NexisLogger {
        private:
            std::shared_ptr<spdlog::logger> nexisLogger;
            std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> nexis_sink;
        public:
            
            NexisLoggerSpd(const std::string logName, const std::string logFormat, const std::string logLevel);
            
            virtual ~NexisLoggerSpd() = default;

            void trace(const std::string& message) override;
            void debug(const std::string& message) override;
            void info(const std::string& message) override;
            void warn(const std::string& message) override;
            void err(const std::string& message) override;
            void crit(const std::string& message) override;

            void setConfig(DataObject config);
    };
    
} // namespace nexis

#endif // NEXIS_LOGGER_SPD_H