#ifndef NEXIS_LOGGER_H
#define NEXIS_LOGGER_H

#include <string>
#include <iostream>
#include <memory>

namespace nexis {

    class NexisLogger {
    public:
        virtual ~NexisLogger() = default;

        // Loggt eine Nachricht auf dem TRACE-Level
        virtual void trace(const std::string& message) = 0;

        // Loggt eine Nachricht auf dem DEBUG-Level
        virtual void debug(const std::string& message) = 0;

        // Loggt eine Nachricht auf dem INFO-Level
        virtual void info(const std::string& message) = 0;

        // Loggt eine Nachricht auf dem WARN-Level
        virtual void warn(const std::string& message) = 0;

        // Loggt eine Nachricht auf dem ERROR-Level
        virtual void err(const std::string& message) = 0;

        // Loggt eine Nachricht auf dem CRITICAL-Level
        virtual void crit(const std::string& message) = 0;
    };

} // namespace nexis

#endif // NEXIS_LOGGER_H