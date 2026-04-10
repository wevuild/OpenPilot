#pragma once
#include <iostream>

int run(void);              // Function declaration for the main logic of the application
int setup(void);            // Function declaration for setup tasks before running the main logic
int cleanup(void);          // Function declaration for cleanup tasks after running the main logic
int handleError(const std::string& errorMessage); // Function declaration for handling errors
int logMessage(const std::string& message);       // Function declaration for logging messages