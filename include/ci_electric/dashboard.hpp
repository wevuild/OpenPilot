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

#include <string.h>
#include "check.hpp"
#include "pin.hpp"

enum class DashboardStatus {
    OK,
    WARNING,
    ERROR,
    STARTUP
};

enum class DashboardEvent {
    POWER_FAILURE,
    SENSOR_FAILURE,
    SYSTEM_HEALTH
};

enum class DashboardAlertLevel {
    INFO,
    WARNING,
    CRITICAL
};

enum class DashboardAlertType {
    POWER,
    SENSOR,
    SYSTEM
};

enum class DashboardLights {
    ENGINE,
    POWER,
    CHECK_ENGINE,
    BATTERY,
    OIL,
    BRAKE,
    AIRBAG,
    ABS,
    TRACTION_CONTROL,
    STABILITY_CONTROL,
    TIRE_PRESSURE,
    DOOR,
    SEATBELT,
    FUEL,
};

class Dashboard {
    public:

    bool initialize() {
        // Initialize dashboard components
        status_ = DashboardStatus::STARTUP;
        return true;
    }

    bool update() {
        // Update dashboard status based on checks and sensor data
        // For example, we could check the power system and update the status accordingly
        // This is a placeholder implementation
        status_ = DashboardStatus::OK;
        return true;
    }

    bool dashboard_alert(DashboardAlertType type, DashboardAlertLevel level, const std::string& message) {
        // Handle dashboard alerts based on type and level
        // For example, we could log the alert or update the dashboard display
        // This is a placeholder implementation
        return true;
    }

    bool set_light(DashboardLights light, bool on) {
        // Set the state of a dashboard light
        // This is a placeholder implementation
        return true;
    }

    bool clear_light(DashboardLights light) {
        // Clear the state of a dashboard light
        // This is a placeholder implementation
        return true;
    }

    bool trigger_event(DashboardEvent event) {
        // Trigger a dashboard event
        // This is a placeholder implementation
        return true;
    }

    bool clear_event(DashboardEvent event) {
        // Clear a dashboard event
        // This is a placeholder implementation
        return true;
    }

    Dashboard() : status_(DashboardStatus::STARTUP) {}
    DashboardStatus status() const { return status_; }

private:
    DashboardStatus status_;
};