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

#include "autopilot/lua_engine.hpp"
#include <iostream>

namespace autopilot {

LuaEngine::LuaEngine(Navigator& nav, Sensors& sensors, Controller& ctrl, Telemetry& telemetry) {
    lua_.open_libraries(sol::lib::base, sol::lib::math, sol::lib::string);
    register_api(nav, sensors, ctrl, telemetry);
}

void LuaEngine::register_api(Navigator& nav, Sensors& sensors, Controller& ctrl, Telemetry& telemetry) {
    sol::table ap = lua_.create_named_table("autopilot");

    ap["log"] = [&telemetry](const std::string& msg) {
        telemetry.send(msg, LogLevel::INFO);
    };

    ap["set_target"] = [&nav](double x, double y, double heading) {
        nav.set_target(Position{ x, y, heading });
    };

    ap["get_target"] = [&nav, this]() {
        auto t = nav.get_target();
        sol::table tbl = lua_.create_table();
        tbl["x"] = t.x; tbl["y"] = t.y; tbl["heading"] = t.heading;
        return tbl;
    };

    ap["read_sensors"] = [&sensors, this]() {
        auto d = sensors.read();
        sol::table tbl = lua_.create_table();
        tbl["speed"] = d.speed; tbl["heading"] = d.heading;
        tbl["x"] = d.x;        tbl["y"] = d.y;
        return tbl;
    };

    ap["control"] = [&ctrl, this](double ts, double cs, double he) {
        auto out = ctrl.update(ControlInput{ ts, cs, he });
        sol::table tbl = lua_.create_table();
        tbl["throttle"] = out.throttle; tbl["steering"] = out.steering;
        return tbl;
    };
}

bool LuaEngine::load_script(const std::string& path) {
    auto result = lua_.load_file(path);
    if (!result.valid()) {
        sol::error err = result;
        std::cerr << "[LuaEngine] Failed to load " << path << ": " << err.what() << "\n";
        return false;
    }
    auto run = result();
    if (!run.valid()) {
        sol::error err = run;
        std::cerr << "[LuaEngine] Error running " << path << ": " << err.what() << "\n";
        return false;
    }
    return true;
}

void LuaEngine::tick(double dt) {
    sol::protected_function on_tick = lua_["on_tick"];
    if (!on_tick.valid()) return;
    auto result = on_tick(dt);
    if (!result.valid()) {
        sol::error err = result;
        std::cerr << "[LuaEngine] on_tick error: " << err.what() << "\n";
    }
}

} // namespace autopilot
