cmake_minimum_required(VERSION 3.10)

project(OpenPilot)

set(CMAKE_CXX_STANDARD 17)

add_executable(OpenPilot
    src/main.cpp
    src/core.cpp
    src/system.cpp
    src/control.cpp
    src/sensors.cpp
    src/telemetry.cpp
    src/navigation.cpp
    src/car_electric/ignition.cpp
    src/ci_electric/power.cpp
)
target_include_directories(OpenPilot PRIVATE ./include)