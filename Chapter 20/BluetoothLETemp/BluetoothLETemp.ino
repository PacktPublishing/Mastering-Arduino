#include <DHT.h>
#include <SoftwareSerial.h>

#define DHT_PIN 3
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

SoftwareSerial HM10(10, 11); // RX | TX
void setup()
{
  Serial.begin(9600);
  HM10.begin(9600);  
  Serial.println("Connected to HM-10"); 
}
 
void loop()
{
  if (HM10.available()) {
    char val = HM10.read();
    if(val == 'f') {
      float fahreheit = dht.readTemperature(true);
      HM10.println(fahreheit);
    } else if(val == 'c') {
      float celsius = dht.readTemperature();
      HM10.println(celsius);
    }  else if(val == 'h') {
      float humidity = dht.readHumidity();
      HM10.println(humidity);
    } else if(val == 'F') {
      float fahreheit = dht.readTemperature(true);
      float humidity = dht.readHumidity();
      float hif = dht.computeHeatIndex(fahreheit, humidity);
      HM10.println(hif);
    } else if(val == 'C') {
      float celsius = dht.readTemperature();
      float humidity = dht.readHumidity();
      float hic = dht.computeHeatIndex(celsius, humidity, false);
      HM10.println(hic);
    }  
  }
}

