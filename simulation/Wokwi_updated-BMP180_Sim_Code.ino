/*
 * Project: Arduino Flight Data Recorder (BMP180 Edition)
 * Hardware: Arduino Nano, MPU6050, BMP180, MicroSD Card Module
 */

#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_BMP085.h> // <-- Changed Library

// --- PIN SETTINGS ---
const int chipSelect = 10; 

// --- OBJECTS ---
File logFile;
Adafruit_MPU6050 mpu;
Adafruit_BMP085 bmp; // <-- Changed Object Type

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10); 

  Serial.println(F("\n--- FLIGHT RECORDER STARTING (BMP180) ---"));

  // 1. Initialize SD Card
  Serial.print(F("Initializing SD card..."));
  if (!SD.begin(chipSelect)) {
    Serial.println(F("❌ FAILED!"));
    while (1); 
  }
  Serial.println(F("✅ OK"));

  // 2. Prepare CSV File
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

  // 3. Initialize MPU6050
  Serial.print(F("Initializing MPU6050..."));
  if (!mpu.begin()) {
    Serial.println(F("❌ NOT FOUND!"));
    while (1);
  }
  Serial.println(F("✅ OK"));

  // 4. Initialize BMP180
  Serial.print(F("Initializing BMP180..."));
  if (!bmp.begin()) { // BMP180 usually finds its address automatically
    Serial.println(F("❌ NOT FOUND!"));
    while (1);
  }
  Serial.println(F("✅ OK"));
  
  Serial.println(F("🚀 SYSTEM READY! RECORDING..."));
  delay(1000);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  // BMP180 uses slightly different function names
  float altitude = bmp.readAltitude(); 
  float temperature = bmp.readTemperature();
  unsigned long currentTime = millis();

  logFile = SD.open("datalog.csv", FILE_WRITE);
  
  if (logFile) {
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
    
    logFile.close(); 
    
    Serial.print("T:"); Serial.print(currentTime);
    Serial.print(" | Alt:"); Serial.print(altitude);
    Serial.print(" | AccZ:"); Serial.println(a.acceleration.z);
  } else {
    Serial.println(F("❌ SD Error!"));
  }

  delay(30); 
}
