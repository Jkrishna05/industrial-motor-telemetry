#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "motor_data.h"
#include "MotorMonitor.h"

class Dashboard {
public:
    void display(const MotorData& data, MotorStatus status);
};

#endif
