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

#include "../autopilot/system.hpp"

namespace ci_electric {

enum class PowerState {
    OFF,
    ON
};

enum class PinMode {
    INPUT,
    OUTPUT
};

enum class PowerStatus {
    LOW,
    HIGH
};

class Pin {
public:
    explicit Pin(int id) : id_(id) {}

    int id() const { return id_; }
    PinMode mode() const { return mode_; }

private:
    int id_;
    PinMode mode_ = PinMode::INPUT;

    friend class CiElectric;
};

class CiElectric {
public:
    bool init();

    bool pin_mode(Pin& pin, PinMode mode);
    bool digital_write(const Pin& pin, PowerStatus value);
    PowerStatus digital_read(const Pin& pin) const;

private:
    autopilot::SystemState current_system_state = autopilot::SystemState::OFF;
    PowerState current_power_state = PowerState::OFF;

    void configure_hardware_pin(int pin_id, PinMode mode);
    void write_hardware_pin(int pin_id, PowerStatus value) const;
    PowerStatus read_hardware_pin(int pin_id) const;
};

}
