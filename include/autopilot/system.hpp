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

namespace autopilot {

enum class SystemState {
    OFF,
    INIT,
    READY,
    RUNNING,
    ERROR
};

enum class RunMode {
    IDLE,
    ACCELERATING,
    CRUISING,
    DECELERATING,
    TURNING,
    STOPPED,
    EMERGENCY_STOP
};

class System {
public:
    bool init();
    bool start();
    void update();

    void requestStop();
    void triggerEmergencyStop();

    SystemState state() const;
    RunMode mode() const;

private:
    SystemState current_state = SystemState::INIT;
    RunMode current_mode = RunMode::IDLE;

    void setState(SystemState new_state);
    void setMode(RunMode new_mode);
};

}