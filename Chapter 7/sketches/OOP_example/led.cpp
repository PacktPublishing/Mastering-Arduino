#include "Arduino.h"
#include "led.h"

Led::Led(int pin, long on, long off) {
  ledPin = pin;
  pinMode(ledPin, OUTPUT);     
    
  onTime = on;
  offTime = off;
}

void Led::blinkLed() {
  this->turnOn();
  delay(onTime);                       
  this->turnOff();   
  delay(offTime); 
}

void Led::turnOn() {
  digitalWrite(ledPin, HIGH);  
}

void Led::turnOff(){
  digitalWrite(ledPin, LOW); 
}



