#include <SoftwareSerial.h>
#define SW_PIN 2 // digital pin Joystick
#define BT_PIN 9 // digital pin Bluetooth
#define X_PIN 0 // analog pin 
#define Y_PIN 1 // analog pin

SoftwareSerial HC05(10, 11); // RX | TX


void setup()
{
  pinMode(BT_PIN,OUTPUT); 
  digitalWrite(BT_PIN,HIGH);
  pinMode(SW_PIN,OUTPUT); 
  digitalWrite(SW_PIN,HIGH); 
  HC05.begin(9600);  
  Serial.begin(9600);
  Serial.println("Connected to HC05.");
}
 
void loop()
{
  int xpos = analogRead(X_PIN) / 4;
  int ypos = analogRead(Y_PIN) / 4;
  HC05.write(0x01);
  HC05.write(xpos);
  HC05.write(ypos);
  HC05.write(0x04);
  delay(500);
  byte bytes[] = {0x01, xpos, ypos, 0x04};
  Serial.println(checksum(bytes, 4));
}

byte checksum(byte *bytes, int buf_size) {
  byte checksum = 0;
  for (int i=0; i< buf_size; i++) {
    checksum += bytes[i];
  }
  return checksum;
}

