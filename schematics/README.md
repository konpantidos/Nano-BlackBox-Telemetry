# Hardware & Wiring Diagrams

This folder contains the electrical schematics and simulation files for the Flight Recorder project.

## Components List
* **Microcontroller:** Arduino Nano
* **IMU Sensor:** MPU6050 (Accelerometer & Gyroscope)
* **Barometric Sensor:** BMP280 (Altitude & Temperature)
* **Storage:** MicroSD Card Module
* **Power:** 9V Battery (connected to VIN)

## Pin Mapping

### I2C Sensors (MPU6050 & BMP280)
| Sensor Pin | Arduino Pin | Description |
|------------|-------------|-------------|
| VCC        | 5V          | Power Supply|
| GND        | GND         | Ground      |
| SDA        | A4          | Data Line   |
| SCL        | A5          | Clock Line  |

### MicroSD Card Module (SPI)
| Module Pin | Arduino Pin | Description |
|------------|-------------|-------------|
| VCC        | 5V          | Power Supply|
| GND        | GND         | Ground      |
| CS         | D10         | Chip Select |
| MOSI       | D11         | Data In     |
| MISO       | D12         | Data Out    |
| SCK        | D13         | Clock       |

## Simulation
(Simulation with BMP180 instead of BMP280 due to lack of sensor in Wokwi Library)
You can run the live simulation of this circuit on Wokwi here:
https://wokwi.com/projects/455776933446111233

## Files
* `wokwi_diagram.json`: The simulation source file.
* `wokwi_circuit_layout.png`: A visual representation of the wiring.

