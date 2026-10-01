#ifndef MOTOR_DATA_H
#define MOTOR_DATA_H

struct MotorData {
    double rpm;
    double temperature;
    double vibration;
    double current;
    double conveyor_speed;

    bool motor_running;
    bool sensor_failure;
};

#endif
