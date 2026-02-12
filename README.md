# Nano-BlackBox-Telemetry
A low-cost, compact Flight Data Recorder (Black Box) for model rocketry and drones based on Arduino Nano. Logs 6-DOF IMU data and Barometric Altitude to a MicroSD card

# Arduino Flight Data Recorder (Black Box)

## Overview
This project is a custom-built **Flight Data Recorder** designed to log telemetry data for small-scale aerospace applications (Model Rockets, Drones, RC Planes). Built on the **Arduino Nano** platform, it functions as a "Black Box," capturing high-frequency sensor data to analyze flight performance and stability post-flight.

## Key Features
* **High-Speed Logging:** Records data to a MicroSD card in `.CSV` format for easy analysis in Excel/Matlab.
* **6-DOF IMU:** Uses the **MPU-6050** to track Acceleration (G-force) and Gyroscopic rotation (Roll/Pitch/Yaw).
* **Altimeter:** Uses the **BMP280** for precise barometric altitude and temperature readings.
* **Portable Power:** Powered by a standalone 9V battery for complete isolation from the vehicle's power system.

## Hardware Manifest
* **Microcontroller:** Arduino Nano V3 (ATmega328P / CH340)
* **Inertial Measurement Unit (IMU):** GY-521 (MPU-6050)
* **Barometer:** BMP280 (I2C Interface)
* **Storage:** MicroSD Card Adapter Module (SPI Interface with LVC125A Level Shifter)
* **Power Supply:** 9V Battery via VIN

## Data Log Structure (CSV)
The system logs the following data points:
`Time(ms), Accel_X, Accel_Y, Accel_Z, Gyro_X, Gyro_Y, Gyro_Z, Altitude(m), Temp(C)`

## Future Improvements
- [ ] Implement Kalman Filter for altitude smoothing.
- [ ] Add LED status indicators for "Recording" and "Error" states.
- [ ] Optimize SPI write speed for higher sampling rates.


*Created by Konstantinos Pantidos*
