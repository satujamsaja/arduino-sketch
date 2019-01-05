/**
 * DHT22
 * https://www.denislab.com/2018/10/arduino-reading-dht22-sensor.html
 */

// Include DHT library
#include "DHT.h"

// Define data pin.
#define DHTPIN 2

// Defind DHT type.
#define DHTTYPE DHT22

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Use serial monitor as output.
  Serial.begin(9600);

  // Begin DHT initialization.
  dht.begin();

  // Print heading.
  Serial.println("DHT22 - Humidity and Temperature Sensor");
  Serial.println("RH\t Temp (C)\t Temp (F)\t HI (C) \t HI (F)");
  
}

void loop() {
  // Set delay between sensor readings (2 seconds).
  delay(2000);

  // Read sensor data.  
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);

  // Check if sensor readings has results.
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Unable to read DHT sensor!");
    return;
  }

  // Calculate heat index.
  float hif = dht.computeHeatIndex(tempF, humidity);
  float hic = dht.computeHeatIndex(tempC, humidity, false);

  // Output it to serial monitor.
  Serial.print(humidity);
  Serial.print("%\t ");
  Serial.print(tempC);
  Serial.print("*C\t ");
  Serial.print(tempF);
  Serial.print("*F\t ");
  Serial.print(hic);
  Serial.print("*C\t ");
  Serial.print(hif);
  Serial.println("*F\t ");
}