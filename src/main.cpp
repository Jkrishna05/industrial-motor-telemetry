#include <iostream>
#include <thread>
#include <chrono>

#include "SensorSimulator.h"
#include "FaultInjector.h"
#include "MotorMonitor.h"
#include "Logger.h"
#include "Dashboard.h"

int main() {

    SensorSimulator simulator;
    FaultInjector injector;
    MotorMonitor monitor;
    Logger logger;
    Dashboard dashboard;

    int choice;

    std::cout << "\n==========================================\n";
    std::cout << "   INDUSTRIAL MOTOR TELEMETRY SYSTEM\n";
    std::cout << "==========================================\n";

    std::cout << "\nSelect Fault Mode:\n";
    std::cout << "1. Normal Operation\n";
    std::cout << "2. Overheat\n";
    std::cout << "3. High Vibration\n";
    std::cout << "4. Over Current\n";
    std::cout << "5. Motor Stall\n";
    std::cout << "6. Sensor Failure\n";
    std::cout << "7. Exit\n";

    std::cout << "\nEnter choice: ";
    std::cin >> choice;

    if (choice == 7) {
        std::cout << "Exiting system...\n";
        return 0;
    }

    FaultType selectedFault = FaultType::NONE;

    switch (choice) {

        case 1:
            selectedFault = FaultType::NONE;
            break;

        case 2:
            selectedFault = FaultType::OVERHEAT;
            break;

        case 3:
            selectedFault = FaultType::HIGH_VIBRATION;
            break;

        case 4:
            selectedFault = FaultType::OVER_CURRENT;
            break;

        case 5:
            selectedFault = FaultType::MOTOR_STALL;
            break;

        case 6:
            selectedFault = FaultType::SENSOR_FAILURE;
            break;

        default:
            std::cout << "Invalid choice.\n";
            return 1;
    }

    std::cout << "\nStarting motor monitoring...\n";
    std::cout << "Press Ctrl+C to stop.\n";

    while (true) {

        // Generate sensor data
        MotorData data = simulator.generateData();

        // Inject selected fault
        injector.injectFault(data, selectedFault);

        // Monitor motor
        MotorStatus status = monitor.checkStatus(data);

        // Display telemetry
        dashboard.display(data, status);

        // Log system status
        switch (status) {

            case MotorStatus::NORMAL:
                logger.log("NORMAL: Motor operating normally.");
                break;

            case MotorStatus::WARNING:
                logger.log("WARNING: Abnormal motor condition detected.");
                break;

            case MotorStatus::CRITICAL:

                if (data.sensor_failure) {
                    logger.log("CRITICAL: Sensor failure detected.");
                }
                else if (!data.motor_running || data.rpm == 0) {
                    logger.log("CRITICAL: Motor stall detected.");
                }
                else if (data.temperature > 80.0) {
                    logger.log("CRITICAL: OVERHEAT detected.");
                }
                else if (data.vibration > 7.0) {
                    logger.log("CRITICAL: HIGH VIBRATION detected.");
                }
                else if (data.current > 15.0) {
                    logger.log("CRITICAL: OVER CURRENT detected.");
                }

                break;
        }

        // Wait for 1 second
        std::this_thread::sleep_for(
            std::chrono::seconds(1)
        );
    }

    return 0;
}
