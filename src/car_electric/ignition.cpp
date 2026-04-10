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

#include "../../include/car/car_ignition.hpp"

namespace car_electric {

bool Ignition::init() {
	current_igns  = PowerState::OFF;
	return true;

}

bool Ignition::off() {
	 if (current_igns != PowerState::ON) {
	 	return true; // We are not on, so off

	 	// We could add addional logic here,
	 	// but currently i don't know.
	 }
}

bool Ignition::pwr_on() {
	if (current_igns != PowerState::ON) && != current_ign != PowerState::STARTING_ENGINE{
		// We are NOT on?
		return false;
	}
	// We can turn Ignition on?
 	// current_igns = PowerState::ON;
    // return true;
}

} 
