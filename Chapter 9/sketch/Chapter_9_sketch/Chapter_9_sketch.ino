#include "DHT.h"

#define DHT_PIN 3
#define RAIN_PIN A2
#define DHT_TYPE DHT11
#define RAIN_SENSOR_MAX 1024
#define RAIN_SENSOR_MIN 0
#define RAIN_OUT_MAX 20
#define RAIN_OUT_MIN 0

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float celsius = dht.readTemperature();
  float fahreheit = dht.readTemperature(true);

  if (isnan(humidity) || isnan(celsius) || isnan(fahreheit)) {
    Serial.println("Read Failed");
    return;
  }

 // float hif = dht.computeHeatIndex(fahreheit, humidity);
 // float hic = dht.computeHeatIndex(celsius, humidity, false);

  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" *C ");
  Serial.print(fahreheit);
  Serial.println(" *F");

  int rain = analogRead(RAIN_PIN);
  if (isnan(rain)) {
    Serial.println("Read Failed");
    return;
  }
  int range = map(rain, RAIN_SENSOR_MIN, RAIN_SENSOR_MAX, RAIN_OUT_MAX, RAIN_OUT_MIN);
  Serial.print("Rain: ");
  Serial.println(range);

  Serial.println("-------------------------");
  delay(3000);
  /*
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.println(" *C ");
  Serial.print(hif);
  Serial.printlnln(" *F");
  */

}
