# Nano-BlackBox-Telemetry

**An Open Source, Arduino-based Flight Computer for Model Rocketry.**
Designed to log high-speed telemetry (Acceleration, Gyro, Altitude) to an SD Card for post-flight analysis.

![Project Render](docs/images/render.png)

## 🌟 Key Features
* **Core:** Arduino Nano v3.0 (ATmega328P)
* **IMU:** MPU6050 (6-DOF Gyro + Accelerometer)
* **Barometer:** BMP280 (Altitude & Temperature)
* **Storage:** MicroSD Card (SPI, CSV format)
* **Logic:** Finite State Machine (Idle -> Ascent -> Descent -> Landed)

## 📂 Project Structure
This repository is organized into modular folders:

| Folder | Description |
| :--- | :--- |
| **[`/hardware`](./hardware)** | PCB Design files (KiCad 8.0), Schematics, and Gerbers. |
| **[`/firmware`](./firmware)** | Source code for the Arduino Nano (C++). |
| **[`/analysis`](./analysis)** | Python scripts to visualize flight data (Graphs). |
| **[`/simulation`](./simulation)** | Wokwi simulation files for logic testing. |
| **[`/docs`](./docs)** | Datasheets, Pinouts, and Assembly guides. |

## 🚀 Quick Start
1. **Hardware:** Order the PCB using the Gerber files in `/hardware/gerbers`.
2. **Firmware:** Open `/firmware/flight_recorder` in Arduino IDE and upload to Nano.
3. **Analysis:** Run the Python scripts in `/analysis` to plot your `flight.csv`.

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
