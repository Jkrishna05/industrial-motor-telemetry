# Industrial Conveyor-Belt Motor Telemetry & Fault Injector

A Linux-based C++ application that simulates industrial conveyor-belt motor telemetry, injects different motor faults, detects abnormal conditions, displays real-time motor health, and maintains timestamped event logs.

The project is designed to demonstrate **C++ programming, object-oriented design, Linux-based development, software architecture, sensor simulation, fault injection, monitoring, and logging**.

---

## 1. Project Overview

Industrial conveyor-belt motors continuously generate data such as:

* RPM
* Temperature
* Vibration
* Electrical current
* Conveyor speed
* Motor running/stopped state
* Sensor health

In a real industrial system, this information is collected from physical sensors and processed by monitoring software.

This project simulates the same concept using a C++ application running on Linux.

The system:

1. Generates simulated motor telemetry.
2. Allows the user to select a fault condition.
3. Injects the selected fault into the telemetry.
4. Analyzes the motor condition.
5. Classifies the motor as `NORMAL`, `WARNING`, or `CRITICAL`.
6. Displays telemetry through a terminal dashboard.
7. Records detected conditions in a timestamped log file.
8. Continuously monitors the simulated motor.

---

## 2. Objectives

The main objectives of this project are:

* Simulate industrial motor sensor data.
* Monitor motor operating conditions.
* Detect abnormal motor behavior.
* Inject controlled faults for testing.
* Display real-time motor telemetry.
* Classify motor health.
* Maintain persistent system logs.
* Demonstrate modular C++ architecture.
* Develop and execute the application in a Linux environment.

---

## 3. System Architecture

The application follows a modular processing pipeline:

```text
┌───────────────────────┐
│   Sensor Simulator    │
└───────────┬───────────┘
            │
            ▼
     ┌──────────────┐
     │   MotorData  │
     └──────┬───────┘
            │
            ▼
┌───────────────────────┐
│    Fault Injector     │
└───────────┬───────────┘
            │
            ▼
┌───────────────────────┐
│    Motor Monitor      │
└───────────┬───────────┘
            │
       ┌────┴────┐
       ▼         ▼
┌───────────┐ ┌────────────┐
│  Logger   │ │ Dashboard  │
└───────────┘ └────────────┘
```

### Data Flow

```text
SensorSimulator
       │
       ▼
   MotorData
       │
       ▼
FaultInjector
       │
       ▼
MotorMonitor
    │       │
    ▼       ▼
 Logger   Dashboard
```

---

## 4. Project Structure

```text
industrial-motor-telemetry/
│
├── include/
│   └── motor_data.h
│
├── logs/
│   └── motor.log
│
├── src/
│   ├── Dashboard.cpp
│   ├── Dashboard.h
│   │
│   ├── FaultInjector.cpp
│   ├── FaultInjector.h
│   │
│   ├── Logger.cpp
│   ├── Logger.h
│   │
│   ├── MotorMonitor.cpp
│   ├── MotorMonitor.h
│   │
│   ├── SensorSimulator.cpp
│   ├── SensorSimulator.h
│   │
│   └── main.cpp
│
├── .gitignore
├── Makefile
└── README.md
```

---

## 5. File Description

### `include/motor_data.h`

Defines the common `MotorData` structure used throughout the application.

It stores:

```text
RPM
Temperature
Vibration
Current
Conveyor Speed
Motor Running State
Sensor Failure State
```

---

### `src/main.cpp`

The main entry point and controller of the application.

Responsibilities:

* Initialize application components.
* Display the fault-selection menu.
* Generate motor telemetry.
* Apply the selected fault.
* Check motor health.
* Display telemetry.
* Log detected conditions.
* Continuously monitor the motor.

---

### `src/SensorSimulator.h`

Header file for the sensor simulation component.

Defines the `SensorSimulator` class.

---

### `src/SensorSimulator.cpp`

Generates simulated sensor readings for the motor.

The simulator generates values for:

* RPM
* Temperature
* Vibration
* Current
* Conveyor speed
* Motor state
* Sensor state

Example normal telemetry:

```text
RPM             : 1419.00
Temperature     : 48.20 C
Vibration       : 1.30 mm/s
Current         : 7.70 A
Conveyor Speed  : 2.10 m/s
```

---

### `src/FaultInjector.h`

Defines the different fault types supported by the system.

```text
NONE
OVERHEAT
HIGH_VIBRATION
OVER_CURRENT
MOTOR_STALL
SENSOR_FAILURE
```

---

### `src/FaultInjector.cpp`

Modifies the simulated telemetry to represent different fault conditions.

Examples:

```text
Overheat       → Temperature = 95°C
High Vibration → Vibration = 9.5 mm/s
Over Current   → Current = 18 A
Motor Stall    → RPM = 0, Motor stopped
Sensor Failure → Sensor failure flag enabled
```

---

### `src/MotorMonitor.h`

Defines the motor health states:

```text
NORMAL
WARNING
CRITICAL
```

and the monitoring interface.

---

### `src/MotorMonitor.cpp`

Analyzes the telemetry and determines the current motor health.

### Critical conditions

The system reports `CRITICAL` when:

```text
Sensor failure is detected
OR
Motor is stopped / RPM = 0
OR
Temperature > 80°C
OR
Vibration > 7 mm/s
OR
Current > 15 A
```

### Warning conditions

The system reports `WARNING` when:

```text
Temperature > 70°C
OR
Vibration > 5 mm/s
OR
Current > 12 A
```

Otherwise, the motor is considered:

```text
NORMAL
```

---

### `src/Logger.h`

Defines the logging interface.

---

### `src/Logger.cpp`

Writes timestamped monitoring events to:

```text
logs/motor.log
```

Example:

```text
[2026-10-01 12:42:23] CRITICAL: HIGH VIBRATION detected.
[2026-10-01 12:42:32] CRITICAL: Motor stall detected.
[2026-10-01 12:43:07] CRITICAL: Sensor failure detected.
[2026-10-01 12:43:58] CRITICAL: OVER CURRENT detected.
```

---

### `src/Dashboard.h`

Defines the terminal dashboard interface.

---

### `src/Dashboard.cpp`

Displays the current motor telemetry and system health in a structured terminal interface.

Example:

```text
==========================================
       INDUSTRIAL MOTOR MONITOR
==========================================
Motor Status    : RUNNING
RPM             : 1419.00
Temperature     : 95.00 C
Vibration       : 1.30 mm/s
Current         : 7.70 A
Conveyor Speed  : 2.10 m/s
Sensor Status   : OK
System Health   : CRITICAL
==========================================
```

---

### `Makefile`

Provides the build configuration for compiling the C++ application.

---

### `.gitignore`

Prevents generated files such as compiled binaries and other unnecessary files from being committed to the Git repository.

---

### `logs/motor.log`

Stores runtime monitoring and fault-detection events.

The log is generated and updated while the application is running.

---

## 6. Technologies Used

| Technology | Purpose                               |
| ---------- | ------------------------------------- |
| C++        | Core application development          |
| C++17      | Language standard                     |
| Linux      | Development and execution environment |
| G++        | C++ compiler                          |
| Make       | Build automation                      |
| File I/O   | Persistent event logging              |
| OOP        | Modular application design            |

---

## 7. Requirements

### Operating System

Linux is required for the project environment.

The project can be developed using:

* Ubuntu
* Ubuntu on WSL2
* Native Linux
* Ubuntu Virtual Machine

### Compiler

A C++17-compatible compiler is required.

Check the compiler:

```bash
g++ --version
```

---

## 8. Build

Clone the repository:

```bash
git clone <repository-url>
```

Enter the project directory:

```bash
cd industrial-motor-telemetry
```

Build using the Makefile:

```bash
make
```

Alternatively, compile manually:

```bash
g++ -std=c++17 -Iinclude \
src/main.cpp \
src/SensorSimulator.cpp \
src/FaultInjector.cpp \
src/MotorMonitor.cpp \
src/Logger.cpp \
src/Dashboard.cpp \
-o motor_monitor
```

---

## 9. Run

After compilation:

```bash
./motor_monitor
```

The application displays:

```text
==========================================
   INDUSTRIAL MOTOR TELEMETRY SYSTEM
==========================================

Select Fault Mode:
1. Normal Operation
2. Overheat
3. High Vibration
4. Over Current
5. Motor Stall
6. Sensor Failure
7. Exit

Enter choice:
```

---

## 10. Fault Scenarios

### 1. Normal Operation

Select:

```text
1
```

The simulator generates normal motor telemetry.

Expected health:

```text
System Health   : NORMAL
```

---

### 2. Overheat

Select:

```text
2
```

The fault injector sets the motor temperature to:

```text
95°C
```

Expected result:

```text
System Health   : CRITICAL
```

---

### 3. High Vibration

Select:

```text
3
```

The vibration value is increased to:

```text
9.5 mm/s
```

Expected result:

```text
System Health   : CRITICAL
```

---

### 4. Over Current

Select:

```text
4
```

The current is increased to:

```text
18 A
```

Expected result:

```text
System Health   : CRITICAL
```

---

### 5. Motor Stall

Select:

```text
5
```

The motor is simulated as stopped:

```text
RPM             : 0
Motor Status    : STOPPED
```

Expected result:

```text
System Health   : CRITICAL
```

---

### 6. Sensor Failure

Select:

```text
6
```

The sensor failure state is enabled.

Expected result:

```text
Sensor Status   : FAILED
System Health   : CRITICAL
```

---

### 7. Exit

Select:

```text
7
```

The application terminates.

---

## 11. Real-Time Monitoring

After selecting a mode, the application continuously generates telemetry at one-second intervals.

Example:

```text
Reading 1
   ↓
Generate telemetry
   ↓
Inject selected fault
   ↓
Analyze motor health
   ↓
Display dashboard
   ↓
Write log
   ↓
Wait 1 second
   ↓
Reading 2
   ↓
Repeat
```

The monitoring system can be stopped using:

```bash
Ctrl + C
```

---

## 12. Logging

To view the latest monitoring events:

```bash
tail -30 logs/motor.log
```

Example:

```text
[2026-10-01 12:40:47] CRITICAL: OVERHEAT detected.
[2026-10-01 12:42:23] CRITICAL: HIGH VIBRATION detected.
[2026-10-01 12:42:32] CRITICAL: Motor stall detected.
[2026-10-01 12:43:07] CRITICAL: Sensor failure detected.
[2026-10-01 12:43:58] CRITICAL: OVER CURRENT detected.
```

---

## 13. Testing

The implemented fault scenarios have been tested individually.

| Test Case             | Expected Result           | Status |
| --------------------- | ------------------------- | ------ |
| Normal operation      | `NORMAL`                  | PASS   |
| Overheat              | `CRITICAL`                | PASS   |
| High vibration        | `CRITICAL`                | PASS   |
| Over current          | `CRITICAL`                | PASS   |
| Motor stall           | `CRITICAL`                | PASS   |
| Sensor failure        | `CRITICAL`                | PASS   |
| Continuous monitoring | Repeated telemetry        | PASS   |
| Event logging         | Timestamped log entries   | PASS   |
| Dashboard display     | Correct telemetry display | PASS   |

---

## 14. Software Architecture

The application follows a modular architecture where each component has a specific responsibility.

```text
SensorSimulator
      │
      │ Generates telemetry
      ▼
   MotorData
      │
      │ Telemetry structure
      ▼
FaultInjector
      │
      │ Introduces faults
      ▼
MotorMonitor
      │
      ├───────────────┐
      ▼               ▼
   Logger          Dashboard
      │               │
      ▼               ▼
motor.log       Terminal Output
```

This separation makes the system easier to understand, test, maintain, and extend.

---

## 15. Linux and Systems Concepts

The project is developed and executed in a Linux environment and demonstrates several systems-oriented concepts:

* Linux command-line development
* C++ compilation using G++
* Make-based build process
* File I/O
* Continuous monitoring
* Sensor and hardware simulation
* Fault detection
* Modular system architecture

### Future Linux Device Integration

The project architecture can be extended with a Linux character-device driver so that the monitoring application can communicate with a simulated or physical motor sensor through a device interface such as:

```text
/dev/motor_sensor
```

A future driver-based architecture would look like:

```text
C++ Monitoring Application
           │
           ▼
   /dev/motor_sensor
           │
           ▼
Linux Character Device Driver
           │
           ▼
 Motor / Sensor Interface
```

The current repository focuses on the user-space C++ telemetry and monitoring implementation.

---

## 16. Future Enhancements

Possible future improvements include:

* Linux character-device driver integration.
* Communication between the C++ application and `/dev/motor_sensor`.
* Real industrial sensor integration.
* Multithreaded telemetry processing.
* Thread-safe shared telemetry buffer.
* Configurable fault thresholds.
* Historical telemetry analysis.
* Circular telemetry buffer.
* CSV telemetry export.
* Automatic fault recovery.
* Alarm and notification mechanisms.
* Hardware-in-the-loop testing.

---

## 17. Project Status

### Implemented

```text
[✓] C++17 application
[✓] Linux development environment
[✓] Motor telemetry simulation
[✓] RPM simulation
[✓] Temperature simulation
[✓] Vibration simulation
[✓] Current simulation
[✓] Conveyor speed simulation
[✓] Fault injection
[✓] Overheat detection
[✓] High vibration detection
[✓] Over current detection
[✓] Motor stall detection
[✓] Sensor failure detection
[✓] Normal/Warning/Critical classification
[✓] Continuous monitoring
[✓] Terminal dashboard
[✓] Timestamped logging
[✓] Fault scenario testing
```

### Planned

```text
[ ] Linux character-device driver
[ ] Driver-to-application communication
[ ] Hardware/sensor integration
```

---

## 18. Conclusion

The **Industrial Conveyor-Belt Motor Telemetry & Fault Injector** is a Linux-based C++ monitoring system that simulates industrial motor telemetry and demonstrates how abnormal motor conditions can be detected and logged.

The modular design separates sensor simulation, fault injection, monitoring, logging, and visualization into independent components.

The project provides a foundation for future integration with Linux device drivers and real industrial hardware.

---

## Author

**Jay Krishna Rout**

B.Tech – Computer Science & Information Technology

ITER, Siksha 'O' Anusandhan (SOA) University

Odisha, India

GitHub: **Jkrishna05**
