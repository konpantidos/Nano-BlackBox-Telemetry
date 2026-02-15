#include "Storage.h"
#include "Config.h"
#include <SPI.h>
#include <SD.h>

File logFile;

bool initStorage() {
    Serial.print("[STORAGE] Initializing SD Card...");
    
    // Check if card is present
    if (!SD.begin(PIN_SD_CS)) {
        Serial.println("FAILED!");
        return false;
    }
    Serial.println("OK.");

    // Open file and write CSV Header
    logFile = SD.open(LOG_FILENAME, FILE_WRITE);
    if (logFile) {
        logFile.println("Time(ms),AccelX,AccelY,AccelZ,Altitude,Temp");
        logFile.flush(); // Ensure header is saved
        Serial.println("[STORAGE] File created: " LOG_FILENAME);
        return true;
    } else {
        Serial.println("[STORAGE] Error creating file.");
        return false;
    }
}

void logData(FlightData data) {
    if (logFile) {
        logFile.print(data.timestamp); logFile.print(",");
        logFile.print(data.ax);        logFile.print(",");
        logFile.print(data.ay);        logFile.print(",");
        logFile.print(data.az);        logFile.print(",");
        logFile.print(data.altitude);  logFile.print(",");
        logFile.println(data.temperature);
        
        // Note: We do NOT define flush() here to save speed. 
        // We only flush/close when LANDED.
    }
}

void closeStorage() {
    if (logFile) {
        logFile.close();
        Serial.println("[STORAGE] File saved and closed.");
    }
}
