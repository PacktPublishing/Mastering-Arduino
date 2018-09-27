#include <DHT.h>
#include <MOVIShield.h>

#define DHT_PIN 3
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);
MOVI movi(false);

char answer[21];

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  movi.init();
  movi.callSign("buddy"); 
  movi.addSentence("temp"); 
  movi.train();  
}

void loop() {
  // put your main code here, to run repeatedly:
  signed int res=movi.poll();
  if (res == 1) {
    float fahreheit = dht.readTemperature(true);
    int tmp = (int)fahreheit;
    sprintf(answer, "The temperature is %02d", tmp);
    movi.say(answer);
  }
}
