#include "MotorMonitor.h"

#include <iostream>

MotorStatus MotorMonitor::checkStatus(const MotorData& data) {

    if (data.sensor_failure) {
        return MotorStatus::CRITICAL;
    }

    if (!data.motor_running || data.rpm == 0) {
        return MotorStatus::CRITICAL;
    }

    if (data.temperature > 80.0 ||
        data.vibration > 7.0 ||
        data.current > 15.0) {
        return MotorStatus::CRITICAL;
    }

    if (data.temperature > 70.0 ||
        data.vibration > 5.0 ||
        data.current > 12.0) {
        return MotorStatus::WARNING;
    }

    return MotorStatus::NORMAL;
}

void MotorMonitor::printStatus(const MotorData& data) {

    MotorStatus status = checkStatus(data);

    std::cout << "\nMotor Status: ";

    switch (status) {

        case MotorStatus::NORMAL:
            std::cout << "NORMAL";
            break;

        case MotorStatus::WARNING:
            std::cout << "WARNING";
            break;

        case MotorStatus::CRITICAL:
            std::cout << "CRITICAL";
            break;
    }

    std::cout << '\n';
}
