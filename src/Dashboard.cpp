#include "Dashboard.h"

#include <iostream>
#include <iomanip>

void Dashboard::display(const MotorData& data, MotorStatus status) {

    std::cout << "\n";
    std::cout << "==========================================\n";
    std::cout << "       INDUSTRIAL MOTOR MONITOR\n";
    std::cout << "==========================================\n";

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Motor Status    : "
              << (data.motor_running ? "RUNNING" : "STOPPED") << '\n';

    std::cout << "RPM             : " << data.rpm << '\n';
    std::cout << "Temperature     : " << data.temperature << " C\n";
    std::cout << "Vibration       : " << data.vibration << " mm/s\n";
    std::cout << "Current         : " << data.current << " A\n";
    std::cout << "Conveyor Speed  : " << data.conveyor_speed << " m/s\n";

    std::cout << "Sensor Status   : "
              << (data.sensor_failure ? "FAILED" : "OK") << '\n';

    std::cout << "System Health   : ";

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

    std::cout << "==========================================\n";
}
