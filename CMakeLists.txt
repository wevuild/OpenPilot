cmake_minimum_required(VERSION 3.10)

project(OpenPilot)

set(CMAKE_CXX_STANDARD 17)

find_package(Lua REQUIRED)

# Prefer Lua 5.4 (compatible with sol2 v3.3)
if(LUA_VERSION_MAJOR EQUAL 5 AND LUA_VERSION_MINOR GREATER_EQUAL 5)
    set(LUA_INCLUDE_DIR /opt/homebrew/opt/lua@5.4/include/lua)
    set(LUA_LIBRARIES   /opt/homebrew/opt/lua@5.4/lib/liblua.dylib)
endif()

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
    src/lua_engine.cpp
)

target_include_directories(OpenPilot PRIVATE ./include ${LUA_INCLUDE_DIR})
target_link_libraries(OpenPilot PRIVATE ${LUA_LIBRARIES})
