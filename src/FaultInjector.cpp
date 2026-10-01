#include "FaultInjector.h"

void FaultInjector::injectFault(MotorData& data, FaultType fault) {

    switch (fault) {

        case FaultType::OVERHEAT:
            data.temperature = 95.0;
            break;

        case FaultType::HIGH_VIBRATION:
            data.vibration = 9.5;
            break;

        case FaultType::OVER_CURRENT:
            data.current = 18.0;
            break;

        case FaultType::MOTOR_STALL:
            data.rpm = 0;
            data.motor_running = false;
            break;

        case FaultType::SENSOR_FAILURE:
            data.sensor_failure = true;
            break;

        case FaultType::NONE:
            break;
    }
}
