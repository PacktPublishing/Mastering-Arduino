#include <SoftwareSerial.h>
SoftwareSerial HM10(10, 11); // RX | TX
bool addNewLine = false;

void setup()
{
 //Attempt to change settings like the connection interval to show how
  Serial.begin(9600);
  HM10.begin(9600);   
  Serial.println("Connected to HM-10.  Try connecting from any device or issue AT commands");
 
}
 
void loop()
{
  if (HM10.available()) {
    if (addNewLine) {
      Serial.write("\r\n");
      addNewLine = false;
    }
    Serial.write(HM10.read());
  } 
 
  if (Serial.available()) {
    HM10.write(Serial.read());
    addNewLine = true;
  }
}
