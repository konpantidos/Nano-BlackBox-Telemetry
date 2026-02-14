# Project Documentation

This folder contains all technical documentation, datasheets, and visual references for the Nano BlackBox Flight Computer.

## Contents
* **Datasheets:** Specifications for all sensors and ICs used.
* **Pinout Maps:** Visual guides for connecting the Arduino Nano.
* **Images:** 3D renders and real-world photos of the PCB.
* **Mechanical:** Dimensions and mounting hole specifications.

## Pinout Reference
| Module       | Interface | Arduino Pin | Description         |
|--------------|-----------|-------------|---------------------|
| **MPU6050** | I2C       | A4 (SDA)    | Gyro/Accel Data     |
| **MPU6050** | I2C       | A5 (SCL)    | Clock Line          |
| **BMP280** | I2C       | A4 (SDA)    | Pressure/Temp Data  |
| **BMP280** | I2C       | A5 (SCL)    | Clock Line          |
| **SD Card** | SPI       | D11 (MOSI)  | Master Out Slave In |
| **SD Card** | SPI       | D12 (MISO)  | Master In Slave Out |
| **SD Card** | SPI       | D13 (SCK)   | Serial Clock        |
| **SD Card** | SPI       | D10 (CS)    | Chip Select         |

## I2C Addresses
* **MPU6050:** `0x68` (Default)
* **BMP280:** `0x76` (or `0x77` depending on SDO pin)


