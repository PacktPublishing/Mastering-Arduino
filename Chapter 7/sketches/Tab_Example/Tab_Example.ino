#include "led.h"
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_ONE, OUTPUT);
  pinMode(LED_TWO, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blink_led(LED_ONE);
  delay(1000);
  blink_led(LED_TWO);
}
