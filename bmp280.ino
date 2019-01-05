/**
 * BMP280
 * https://www.denislab.com/2018/10/arduino-reading-bmp280-sensor.html
 * 
 */

#include "Adafruit_BMP280.h"

// Change to your location sea level pressure (Nusa Dua, Bali, Indonesia).
#define SEALEVEL_PRESSURE 1014

// Use I2C, change BMP280_ADDRESS constant at Adafruit_BMP280.h to 0x76.
Adafruit_BMP280 bmp;


void setup() {
  // Use serial monitor as output.
  Serial.begin(9600);

  if (!bmp.begin()) {
    Serial.println("Could not find BMP280 sensor. Check wiring or I2C address!");
  }

  // Print heading.
  Serial.println("BMP280 - Barometric pressure sensor");
  Serial.println("Pressure (Pa)\t Temperature (C)\tAltitude (m)");

}

void loop() {
  // Delay between sensor readings.
 delay(2000);

 // Read sensor.
 float p = bmp.readPressure() / 100;  // Converted to mb, 1mb = 100hPa
 float t = bmp.readTemperature();
 float a = bmp.readAltitude(SEALEVEL_PRESSURE);

 // Output it to serial monitor.
 Serial.print(p);
 Serial.print("mb\t ");
 Serial.print(t);
 Serial.print("*C\t\t");
 Serial.print(a);
 Serial.println("m");
}
