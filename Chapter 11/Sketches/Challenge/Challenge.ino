
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define SHIELD_PIN 13
#define MAX_PIXELS 40

int colorMode = 1;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(MAX_PIXELS, SHIELD_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pixels.show();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pixels.setBrightness(50);
  int tmpColorMode = colorMode;
  for (int i=0; i<8; i++) {
    tmpColorMode += 1;
    if (tmpColorMode > 8) {
      tmpColorMode = 0;
    }
    for (int j=0; j<5; j++) {
      int pixNum = (j*8) + i;
      pixels.setPixelColor(pixNum, colorNum((tmpColorMode * 30) & 255));
    }
    
  }
  colorMode += 1;
  if (colorMode > 8) {
    colorMode = 0;
  }
  pixels.show();
  delay(50);
}

uint32_t colorNum(int colorPos) {
  colorPos = 255 - colorPos;
  if(colorPos < 85) {
    return pixels.Color(255 - colorPos * 3, 0, colorPos * 3);
  }
  if(colorPos < 170) {
    colorPos -= 85;
    return pixels.Color(0, colorPos * 3, 255 - colorPos * 3);
  }
  colorPos -= 170;
  return pixels.Color(colorPos * 3, 255 - colorPos * 3, 0);
}


