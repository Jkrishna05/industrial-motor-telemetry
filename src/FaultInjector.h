#ifndef FAULT_INJECTOR_H
#define FAULT_INJECTOR_H

#include "motor_data.h"

enum class FaultType {
    NONE,
    OVERHEAT,
    HIGH_VIBRATION,
    OVER_CURRENT,
    MOTOR_STALL,
    SENSOR_FAILURE
};

class FaultInjector {
public:
    void injectFault(MotorData& data, FaultType fault);
};

#endif
