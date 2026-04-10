#include "../include/core.hpp"
#include <iostream>

int logMessage(const std::string& message) {
    std::cout << message << std::endl;
    return 0;
}

int handleError(const std::string& errorMessage) {
    std::cerr << "Error: " << errorMessage << std::endl;
    return -1;
}

int run() {
    logMessage("Running main logic...");
    // Main logic of the application goes here
    return 0;
}