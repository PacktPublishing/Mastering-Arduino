#include <SoftwareSerial.h>
#define LED_PIN 5
SoftwareSerial HM10(10, 11); // RX | TX

void setup()
{
  pinMode(LED_PIN, OUTPUT);  
  Serial.begin(9600);
  HM10.begin(9600);
  Serial.println("Connected to HM-10"); 
}
 
void loop()
{
  if (HM10.available()) {
    char val = HM10.read();
    if(val == '1') {
      digitalWrite(LED_PIN, HIGH);
    } else if(val == '0') {
      digitalWrite(LED_PIN, LOW);
    }  
  }
}

