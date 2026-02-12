// Code goes here

/*
 * Project: Nano-BlackBox-Telemetry
 * Author: Konpantidos
 * Hardware: Arduino Nano, MPU6050, BMP280, MicroSD Card Module
 * Description: Logs 6-DOF IMU data and Barometric Altitude to CSV.
 */

#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_BMP280.h>

// --- PIN SETTINGS ---
const int chipSelect = 10; // CS Pin for SD Card Module

// --- OBJECTS ---
File logFile;
Adafruit_MPU6050 mpu;
Adafruit_BMP280 bmp; // I2C Interface

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10); 

  Serial.println(F("\n--- FLIGHT RECORDER STARTING ---"));

  // 1. Initialize SD Card
  Serial.print(F("Initializing SD card..."));
  if (!SD.begin(chipSelect)) {
    Serial.println(F("❌ FAILED!"));
    while (1); 
  }
  Serial.println(F("✅ OK"));

  logFile = SD.open("datalog.csv", FILE_WRITE);
  if (logFile) {
    if (logFile.size() == 0) {
      logFile.println(F("Time(ms),AccelX,AccelY,AccelZ,GyroX,GyroY,GyroZ,Altitude(m),Temp(C)"));
      Serial.println(F("✅ Header written to CSV"));
    }
    logFile.close();
  } else {
    Serial.println(F("❌ Error creating file!"));
  }

  // 2. Initialize MPU6050
  Serial.print(F("Initializing MPU6050..."));
  if (!mpu.begin()) {
    Serial.println(F("❌ NOT FOUND!"));
    while (1);
  }
  Serial.println(F("✅ OK"));

  // 3. Initialize BMP280
  Serial.print(F("Initializing BMP280..."));
  if (!bmp.begin(0x76)) { 
    Serial.println(F("❌ NOT FOUND!"));
    while (1);
  }
  Serial.println(F("✅ OK"));
  
  Serial.println(F("🚀 SYSTEM READY! RECORDING..."));
  delay(1000);
}
void loop() {
  // --- READ SENSORS ---
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  // Read Altitude (1013.25 is standard sea level pressure)
  float altitude = bmp.readAltitude(1013.25); 
  float temperature = bmp.readTemperature();
  unsigned long currentTime = millis();

  // --- LOG TO SD CARD ---
  logFile = SD.open("datalog.csv", FILE_WRITE);
  
  if (logFile) {
    // Format: Time,Ax,Ay,Az,Gx,Gy,Gz,Alt,Temp
    logFile.print(currentTime);
    logFile.print(",");
    logFile.print(a.acceleration.x);
    logFile.print(",");
    logFile.print(a.acceleration.y);
    logFile.print(",");
    logFile.print(a.acceleration.z);
    logFile.print(",");
    logFile.print(g.gyro.x);
    logFile.print(",");
    logFile.print(g.gyro.y);
    logFile.print(",");
    logFile.print(g.gyro.z);
    logFile.print(",");
    logFile.print(altitude);
    logFile.print(",");
    logFile.println(temperature);
    
    logFile.close(); // CRITICAL: Close to save data!
    
    // --- DEBUGGING (Serial Monitor) ---
    Serial.print("T:"); Serial.print(currentTime);
    Serial.print(" | Alt:"); Serial.print(altitude);
    Serial.print(" | AccZ:"); Serial.println(a.acceleration.z);
  } else {
    Serial.println("❌ Error writing to SD!");
  }

  // Sampling Rate Control (approx. 30Hz)
  delay(30); 
}
