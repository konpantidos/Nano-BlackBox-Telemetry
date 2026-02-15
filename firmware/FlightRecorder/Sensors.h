#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

// Structure to hold all sensor data in one neat package
struct FlightData {
    float ax, ay, az;   // Acceleration (G)
    float gx, gy, gz;   // Gyroscope (deg/s)
    float altitude;     // Altitude (meters)
    float temperature;  // Temperature (C)
    unsigned long timestamp; // Time since boot (ms)
};

// Function declarations
void initSensors();
FlightData readSensors();
void calibrateSensors(); // Optional: Call on startup to zero gyro

#endif
