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
#include "../include/autopilot/control.hpp"
#include "../include/autopilot/navigation.hpp"
#include "../include/autopilot/sensors.hpp"
#include "../include/autopilot/telemetry.hpp"

using namespace autopilot;

int main() {
    System system;
    Sensors sensors;
    Controller controller;
    Navigator navigator;
    Telemetry telemetry;

    system.init();
    system.start();

    // Whenever the system state is running, we
    // pull data from sensors. After we have the data
    // We need to set the values.
    while (system.state() == SystemState::RUNNING) {
        auto data = sensors.read();

        ControlInput input {
            .target_speed = 10.0,
            .current_speed = data.speed,
            .heading_error = 0.1
        };

        auto output = controller.update(input);

        telemetry.send("Running...");
    }

    return 0;
}