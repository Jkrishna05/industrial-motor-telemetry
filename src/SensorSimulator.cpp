#include "SensorSimulator.h"

#include <cstdlib>
#include <ctime>

MotorData SensorSimulator::generateData() {
    MotorData data;

    data.rpm = 1400 + rand() % 201;
    data.temperature = 45 + (rand() % 101) / 10.0;
    data.vibration = 1.0 + (rand() % 31) / 10.0;
    data.current = 7.0 + (rand() % 31) / 10.0;
    data.conveyor_speed = 2.0 + (rand() % 11) / 10.0;

    data.motor_running = true;
    data.sensor_failure = false;

    return data;
}
