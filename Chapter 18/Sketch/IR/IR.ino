
#include <IRremote.h>

#define IR_PIN 2
IRrecv ir(IR_PIN);
decode_results irCode;

void setup()
{
  Serial.begin(9600);
  ir.enableIRIn(); 
}

void loop()
{
  if (ir.decode(&irCode))
    {
     Serial.println(irCode.value, HEX);
     delay(100);
     ir.resume(); 
    }
}
