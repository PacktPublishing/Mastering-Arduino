#define REDPIN 11
#define BLUEPIN 10
#define GREENPIN 9

#define COMMON_ANODE 

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  setColor(255, 0, 0); // Red 
  delay(1000);
  setColor(0, 255, 0); // Green 
  delay(1000);
  setColor(0, 0, 255); // Blue
  delay(1000);
  setColor(255, 255, 255); // White 
  delay(1000);
  setColor(255, 0, 255); // Purple 
  delay(1000);
}

void setColor(int red, int green, int blue) {
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(REDPIN, red);
  analogWrite(GREENPIN, green);
  analogWrite(BLUEPIN, blue);
}
