#include "Logger.h"

#include <fstream>
#include <iostream>
#include <ctime>

void Logger::log(const std::string& message) {

    std::ofstream logFile("logs/motor.log", std::ios::app);

    if (!logFile.is_open()) {
        std::cerr << "Error: Unable to open log file.\n";
        return;
    }

    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    char timeBuffer[20];

    std::strftime(
        timeBuffer,
        sizeof(timeBuffer),
        "%Y-%m-%d %H:%M:%S",
        localTime
    );

    logFile << "[" << timeBuffer << "] "
            << message << '\n';

    logFile.close();
}
