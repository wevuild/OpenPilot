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

#include "../include/core.hpp"
#include <iostream>

int logMessage(const std::string& message) {
    std::cout << message << "\n";
    return 0;
}

int handleError(const std::string& errorMessage) {
    std::cerr << "[ERROR] " << errorMessage << "\n";
    return -1;
}

int setup() {
    return logMessage("[core] Setup complete.");
}

int cleanup() {
    return logMessage("[core] Cleanup complete.");
}

int run() {
    setup();
    logMessage("[core] Running main logic...");
    cleanup();
    return 0;
}