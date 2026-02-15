# Flight Computer Firmware

This folder contains the C++ source code for the Arduino Nano.
The firmware is built using a **Modular Architecture** and a **Finite State Machine (FSM)**.

## Code Structure
The code is split into logical modules for easier maintenance:

* **`flight_recorder.ino`**: The main entry point. Contains the `setup()`, `loop()`, and the State Machine logic.
* **`Config.h`**: All settings (Pins, Thresholds, Timers) are defined here. **Edit this file to tune your rocket!**
* **`Sensors.cpp/h`**: Handles communication with MPU6050 and BMP280.
* **`Storage.cpp/h`**: Handles SD Card logging (CSV format).

## Flight Logic (State Machine)
The computer automatically transitions between these states:

1. **IDLE:** Waiting on the pad. (LED Blinking slowly).
   * *Transition:* Acceleration > `LAUNCH_THRESHOLD` (2G).
2. **ASCENT:** Rocket is flying up. Logging data at max speed.
   * *Transition:* Altitude decreases (Apogee detection).
3. **DESCENT:** Rocket is falling under parachute.
   * *Transition:* Altitude constant for `LANDING_TIMER` (5s).
4. **LANDED:** Safe on ground. File saved/closed. (LED Off/Blinking fast).

## 🛠 Dependencies
To compile this code, install these libraries in Arduino IDE:
* `Adafruit MPU6050`
* `Adafruit BMP280`
* `Adafruit Unified Sensor`
