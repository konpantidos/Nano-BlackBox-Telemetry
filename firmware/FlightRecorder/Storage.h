#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>
#include "Sensors.h" // We need to know what FlightData looks like

// Function declarations
bool initStorage();
void logData(FlightData data);
void closeStorage(); // Safely save file on landing

#endif
