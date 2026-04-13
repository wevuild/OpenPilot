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
#include "../include/autopilot/lua_engine.hpp"
#include <string>
#include <thread>
#include <chrono>

using namespace autopilot;

int main() {
    System system;
    Sensors sensors;
    Controller controller;
    Navigator navigator;
    Telemetry telemetry;

    system.init();
    system.start();

    LuaEngine lua(navigator, sensors, controller, telemetry);
    lua.load_script("../scripts/mission.lua");

    navigator.set_target(Position{ .x = 100.0, .y = 200.0, .heading = 0.0 });
    telemetry.send("System started. Target set.", LogLevel::INFO);

    constexpr double dt = 0.05; // 20 Hz
    while (system.state() == SystemState::RUNNING) {
        auto data = sensors.read();

        ControlInput input {
            .target_speed  = 10.0,
            .current_speed = data.speed,
            .heading_error = data.heading
        };

        auto output = controller.update(input);
        system.update();

        lua.tick(dt);

        telemetry.send(
            "throttle=" + std::to_string(output.throttle) +
            " steering=" + std::to_string(output.steering),
            LogLevel::INFO
        );

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    telemetry.send("System stopped.", LogLevel::WARN);
    return 0;
}