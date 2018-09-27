#include <SoftwareSerial.h>
SoftwareSerial HC05(10, 11); // RX | TX
bool addNewLine = false;

void setup()
{
 //Attempt to change settings like the connection interval to show how
  Serial.begin(9600);
  pinMode(9,OUTPUT); 
  digitalWrite(9,HIGH);
  HC05.begin(38400);   
  Serial.println("Connected to HC-05.  Try connecting from any device or issue AT commands");
}
 
void loop()
{
  if (HC05.available()) {
    if (addNewLine) {
      Serial.write("\r\n");
      addNewLine = false;
    }
    Serial.write(HC05.read());
  } 
 
  if (Serial.available()) {
    HC05.write(Serial.read());
    addNewLine = true;
  }
}
