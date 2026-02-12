# Firmware: Flight Recorder

This folder contains the Arduino source code for the rocket's Black Box.

## Requirements
Before uploading, ensure you have the following libraries installed in your Arduino IDE:
* **Adafruit MPU6050** (Motion sensing)
* **Adafruit BMP085 Library** (Pressure & Altitude for BMP180)
* **Adafruit Unified Sensor** (Base driver)
* **SD** (Built-in)

## Arduino IDE Settings
To avoid upload errors (especially with Nano clones), use these settings:
* **Board:** Arduino Nano
* **Processor:** ATmega328P (Old Bootloader)
* **Port:** Select the COM port your Arduino is connected to.

## Folder Structure
* `FlightRecorder/`: Main firmware folder.
  * `FlightRecorder.ino`: The code that runs on the rocket.

## How to Upload
1. Open `FlightRecorder.ino` in Arduino IDE.
2. Install the required libraries via **Tools -> Manage Libraries**.
3. Connect your Arduino Nano via USB.
4. Press **Upload** (the arrow icon).
5. Open **Serial Monitor** at **115200 baud** to verify the sensors are working.
