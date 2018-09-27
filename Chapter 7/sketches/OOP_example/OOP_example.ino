#include "led.h"
Led led(LED_ONE, 1000, 500);
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  led.blinkLed();
}
