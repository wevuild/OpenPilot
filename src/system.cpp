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


#include "../include/autopilot/system.hpp"
// #include "../include/car/car_ignition.hpp"


namespace autopilot {

bool System::init() {
    current_state = SystemState::READY;
    current_mode  = RunMode::IDLE;
    return true;
}

bool System::start() {
    if (current_state != SystemState::READY)
        return false;

    current_state = SystemState::RUNNING;
    return true;
}

void System::update() {
    if (current_state != SystemState::RUNNING) {
        return;
    }

    switch (current_mode) {

    case RunMode::IDLE:
        // Wait for command.
        break;  

    case RunMode::ACCELERATING:
        current_mode = RunMode::CRUISING;
        break;
    case RunMode::DECELERATING:
        current_mode = RunMode::IDLE;
        break;
    case RunMode::STOPPED:
        current_mode = RunMode::STOPPED;
        break;
    case RunMode::EMERGENCY_STOP:
        // Cut engine, lights, etc
        break;
    }
}

SystemState System::state() const {
    return current_state;
}

RunMode System::mode() const {
    return current_mode;
}

}