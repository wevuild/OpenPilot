/*
 * Open-source auto-pilot software for robotics and vehicles.
 * Control with precision, build with confidence.
 *
 * Copyright (C) 2026 WeVuild, Be
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "../include/autopilot/telemetry.hpp"
#include <iostream>
#include <chrono>
#include <ctime>

namespace autopilot {

static const char* levelStr(LogLevel l) {
    switch (l) {
        case LogLevel::WARN:  return "WARN ";
        case LogLevel::ERROR: return "ERROR";
        default:              return "INFO ";
    }
}

void Telemetry::send(const std::string& message, LogLevel level) {
    auto now  = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%H:%M:%S", std::localtime(&time));
    std::cout << "[" << buf << "][" << levelStr(level) << "] " << message << "\n";
}

} // namespace autopilot