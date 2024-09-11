#include "TimeCalc.h"

std::string formatDuration(std::chrono::nanoseconds duration) {
    const long long ns_per_ms   = 1e6;        // Nanosekunden pro Millisekunde
    const long long ns_per_s    = 1e9;         // Nanosekunden pro Sekunde
    const long long ns_per_min  = ns_per_s * 60;   // Nanosekunden pro Minute
    const long long ns_per_hour = ns_per_min * 60; // Nanosekunden pro Stunde
    const long long ns_per_day  = ns_per_hour * 24; // Nanosekunden pro Tag
                                                    // 
    auto durationCount = duration.count();

    // Hilfsvariablen für die Einheiten
    double ms = (durationCount / ns_per_ms) % 1000;
    double s = durationCount / ns_per_s % 60;

    int min = durationCount / ns_per_min % 60;
    int sec = durationCount / ns_per_s % 60;
    int hours = durationCount / ns_per_hour % 24;
    int days = durationCount / ns_per_day;

    std::ostringstream result;

    // Wenn die Zeit 10 Tage oder mehr beträgt, gib nur die Tage zurück
    if (days >= 10) {
        result << std::fixed << std::setprecision(3) << days << " d";
        return result.str();
    }


    // Ausgabe formatieren
    if (days >= 1) {
        result << std::fixed << std::setprecision(3) << days << "d, "
               << std::fixed << std::setprecision(3) << hours << "h";
    } else if (hours >= 1) {
        result << std::fixed << std::setprecision(3) << hours << "h, "
               << std::fixed << std::setprecision(3) << min << "m";
    } else if (min >= 1) {
        result << std::fixed << std::setprecision(3) << min << "m, "
               << std::fixed << std::setprecision(3) << sec << "s";
    } else if (s >= 1) {
        result << std::fixed << std::setprecision(3) << s << "s";
    } else {
        result << std::fixed << std::setprecision(3) << ms << "ms";
    }

    return result.str();
}