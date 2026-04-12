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

#include "../../include/car_electric/car_ignition.hpp"

namespace car_electric {

bool Ignition::init() {
    set_state(PowerState::OFF);
    return true;
}

bool Ignition::off() {
    set_state(PowerState::OFF);
    return true;
}

bool Ignition::shortage() {
    set_state(PowerState::SHORTAGE);
    return true;
}

bool Ignition::pwr_on() {
    if (current_state == PowerState::OFF || current_state == PowerState::SHORTAGE) {
        set_state(PowerState::ON);
        return true;
    }
    return false;
}

bool Ignition::start_engine() {
    if (current_state != PowerState::ON)
        return false;

    set_state(PowerState::STARTING_ENGINE);
    return true;
}

PowerState Ignition::state() const {
    return current_state;
}

void Ignition::set_state(PowerState new_state) {
    current_state = new_state;
}

} // namespace car_electric
