#include <SoftwareSerial.h>
#define MAXBUF 255
SoftwareSerial HC05(10, 11); // RX | TX
bool newMessage = true;
byte buf[MAXBUF];

void setup()
{
//Attempt to change settings like the connection interval to show how
 Serial.begin(9600);
 pinMode(9,OUTPUT);
 digitalWrite(9,HIGH);
 HC05.begin(9600);
 Serial.println("Connected to HM-10.  Try connecting from any device
or issue AT commands");

}

void loop()
{
 memset(buf, 0, MAXBUF);
 bool cont = true;
 int counter = 0;
 while (cont && counter < MAXBUF) {
   if (HC05.available()) {
     byte val = HC05.read();
     buf[counter] = val;
     counter++;
     if (val == 0x04) {
       cont = false;
     }
   }

 }
 for(int i=0; i<counter; i++) {
   Serial.print(buf[i]);
   Serial.print(" ");
 }
 Serial.println(" ");
}
