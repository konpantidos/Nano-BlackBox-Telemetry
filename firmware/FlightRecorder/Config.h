#ifndef CONFIG_H
#define CONFIG_H

// --- Hardware Pin Definitions ---
#define PIN_LED_STATUS  2     // Status LED (Indicates flight state)
#define PIN_BUZZER      3     // Piezo Buzzer (Optional)
#define PIN_SD_CS       10    // Chip Select pin for SD Card Module

// --- Flight Thresholds ---
#define LAUNCH_THRESHOLD 2.0  // Acceleration (G) required to detect liftoff
#define LANDING_TIMER    5000 // Time (ms) of no motion to detect landing
#define SEA_LEVEL_PRESSURE 1013.25 // Standard pressure (adjust based on location)

// --- Data Logging ---
#define LOG_FILENAME "flight.csv" // Name of the log file
#define LOG_INTERVAL 50           // Log every 50ms (20Hz)

#endif
