#ifndef LED_H
#define LED_H

#define LED_ONE 3
#define LED_TWO 11

class Led{
  int ledPin;
  long onTime;
  long offTime;
  public:
    Led(int pin, long on, long off);
    void blinkLed();
    void turnOn();
    void turnOff();
};

#endif
