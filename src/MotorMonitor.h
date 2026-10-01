#ifndef MOTOR_MONITOR_H
#define MOTOR_MONITOR_H

#include "motor_data.h"

enum class MotorStatus {
    NORMAL,
    WARNING,
    CRITICAL
};

class MotorMonitor {
public:
    MotorStatus checkStatus(const MotorData& data);
    void printStatus(const MotorData& data);
};

#endif
