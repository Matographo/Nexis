#ifndef TIME_CALC_H
#define TIME_CALC_H

#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>

std::string formatDuration(std::chrono::nanoseconds duration);

#endif // TIME_CALC_H