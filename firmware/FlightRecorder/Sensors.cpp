#include "Sensors.h"
#include "Config.h"

// TODO: Include Adafruit Libraries here later
// #include <Adafruit_MPU6050.h>
// #include <Adafruit_BMP280.h>

void initSensors() {
    Serial.println("[SENSORS] Initializing MPU6050 & BMP280...");
    // Hardware initialization code will go here
    delay(100); 
    Serial.println("[SENSORS] Sensors Ready.");
}

FlightData readSensors() {
    FlightData data;

    // --- TEMPORARY DUMMY DATA (For Testing Logic) ---
    // In the future, this will be: data.ax = mpu.getAccelerationX();
    data.timestamp = millis();
    data.ax = 0.05; // Resting on table
    data.ay = 0.02;
    data.az = 1.00; // 1G (Gravity)
    data.altitude = 0.0;
    data.temperature = 25.0;

    return data;
}

void calibrateSensors() {
    Serial.println("[SENSORS] Calibrating...");
    // Calibration logic goes here
    delay(500);
}
