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

#pragma once
#include <string>
#include "sol/sol.hpp"
#include "autopilot/navigation.hpp"
#include "autopilot/sensors.hpp"
#include "autopilot/telemetry.hpp"
#include "autopilot/control.hpp"

namespace autopilot {

class LuaEngine {
public:
    LuaEngine(Navigator& nav, Sensors& sensors, Controller& ctrl, Telemetry& telemetry);

    // Load and execute a Lua script file
    bool load_script(const std::string& path);

    // Call the Lua on_tick(dt) function if defined
    void tick(double dt);

private:
    sol::state lua_;
    void register_api(Navigator& nav, Sensors& sensors, Controller& ctrl, Telemetry& telemetry);
};

} // namespace autopilot
