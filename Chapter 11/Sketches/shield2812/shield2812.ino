
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define SHIELD_PIN 13
#define MAX_PIXELS 40

int num = 0;
boolean color = true;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(MAX_PIXELS, SHIELD_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.show();
  pixels.setBrightness(50);
}

void loop() {
  num++;
  if (num > 39) {
    num = 0;
    color = !color;
  }
  if (color) {
    pixels.setPixelColor(num, 170, 255, 10);
  } else {
    pixels.setPixelColor(num, 10, 255, 170);
  }
  pixels.show();
  delay(500);
}
