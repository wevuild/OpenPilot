-- mission.lua
-- Example OpenPilot mission script.
-- on_tick(dt) is called every control loop iteration (~20 Hz).

local elapsed = 0.0

-- Called once when the script is loaded
autopilot.log("Mission script loaded.")
autopilot.set_target(150.0, 300.0, 45.0)

-- Called every tick with delta-time in seconds
function on_tick(dt)
    elapsed = elapsed + dt

    local sensors = autopilot.read_sensors()
    local target  = autopilot.get_target()

    -- Simple example: log position every 5 seconds
    if math.fmod(elapsed, 5.0) < dt then
        autopilot.log(string.format(
            "pos=(%.1f, %.1f) speed=%.2f target=(%.1f, %.1f)",
            sensors.x, sensors.y, sensors.speed,
            target.x,  target.y
        ))
    end

    -- Example: update target after 30 seconds
    if elapsed >= 30.0 and elapsed - dt < 30.0 then
        autopilot.set_target(0.0, 0.0, 0.0)
        autopilot.log("Waypoint reached. Returning to origin.")
    end
end
