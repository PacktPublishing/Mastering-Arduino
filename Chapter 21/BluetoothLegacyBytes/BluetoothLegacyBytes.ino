#include <SoftwareSerial.h>
SoftwareSerial HC05(10, 11); // RX | TX
bool newMessage = true;

void setup()
{
  Serial.begin(9600);
  pinMode(9,OUTPUT); 
  digitalWrite(9,HIGH);
  HC05.begin(9600);   
  Serial.println("Connected to HC-05. ");
}
 
void loop()
{
  if (HC05.available()) {
    byte val = HC05.read();
    Serial.write(val);
    if (val == 0x04) {
      Serial.write("\r\n");
    }  
  } 
 
  if (Serial.available()) {
    if (newMessage) {
      HC05.write(0x01);
      newMessage = false;
    }
    char val = Serial.read();
    if (val == '~') {
      HC05.write(0x04);
      newMessage = true;
    } else {
      HC05.write(val);
    }
  }
}
