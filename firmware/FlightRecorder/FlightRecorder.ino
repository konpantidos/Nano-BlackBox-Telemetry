// Code goes here

/*
 * Project: Nano-BlackBox-Telemetry
 * Author: Konpantidos
 * Hardware: Arduino Nano, MPU6050, BMP280, MicroSD Card Module
 * Description: Logs 6-DOF IMU data and Barometric Altitude to CSV.
 */

#include "Config.h"
#include "Sensors.h"
#include "Storage.h"

// --- Flight States ---
enum FlightState {
    STATE_IDLE,    // Waiting on pad
    STATE_ASCENT,  // Powered flight / Coasting up
    STATE_DESCENT, // Falling / Parachute
    STATE_LANDED   // Safe on ground
};

FlightState currentState = STATE_IDLE;
unsigned long lastLogTime = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("\n--- NANO BLACKBOX BOOT ---");

    pinMode(PIN_LED_STATUS, OUTPUT);

    // Initialize Modules
    initSensors();
    calibrateSensors();
    
    // Try to initialize SD. If it fails, blink rapidly (Error code)
    if (!initStorage()) {
        while (1) {
            digitalWrite(PIN_LED_STATUS, HIGH); delay(100);
            digitalWrite(PIN_LED_STATUS, LOW);  delay(100);
        }
    }

    // Ready signal
    digitalWrite(PIN_LED_STATUS, HIGH);
    delay(1000);
    digitalWrite(PIN_LED_STATUS, LOW);
}

void loop() {
    // 1. Read Data
    FlightData data = readSensors();

    // 2. State Machine Logic
    switch (currentState) {
        case STATE_IDLE:
            // Blink LED slowly (Heartbeat)
            if (millis() % 1000 < 100) digitalWrite(PIN_LED_STATUS, HIGH);
            else digitalWrite(PIN_LED_STATUS, LOW);

            // Detect Launch: Acceleration > Threshold
            if (data.az > LAUNCH_THRESHOLD) {
                currentState = STATE_ASCENT;
                Serial.println("[FSM] LAUNCH DETECTED! 🚀");
                digitalWrite(PIN_LED_STATUS, HIGH); // Solid LED during flight
            }
            break;

        case STATE_ASCENT:
            // Log Data fast!
            if (millis() - lastLogTime >= LOG_INTERVAL) {
                logData(data);
                lastLogTime = millis();
            }

            // Detect Apogee (simplified logic for now)
            // If altitude starts dropping... (Needs logic later)
            // For now, let's just simulate transition
            // currentState = STATE_DESCENT; 
            break;

        case STATE_DESCENT:
            // Continue logging
            if (millis() - lastLogTime >= LOG_INTERVAL) {
                logData(data);
                lastLogTime = millis();
            }
            
            // Detect Landing (Altitude constant)
            // currentState = STATE_LANDED;
            break;

        case STATE_LANDED:
            // Save file immediately
            closeStorage();
            
            // Blink specific pattern to help locate rocket
            if (millis() % 200 < 50) digitalWrite(PIN_LED_STATUS, HIGH);
            else digitalWrite(PIN_LED_STATUS, LOW);
            break;
    }
}
