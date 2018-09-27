#include <Servo.h>

#define SERVO0_POT 0
#define SERVO0_OUT 3

#define SERVO1_POT 1
#define SERVO1_OUT 5

#define SERVO2_POT 2
#define SERVO2_OUT 6

#define SERVO3_POT 3
#define SERVO3_OUT 9

#define SERVO4_POT 4
#define SERVO4_OUT 10


Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // put your setup code here, to run once:
  servo0.attach(SERVO0_OUT);
  servo1.attach(SERVO1_OUT);
  servo2.attach(SERVO2_OUT);
  servo3.attach(SERVO3_OUT);
  servo4.attach(SERVO4_OUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  setServo(SERVO0_POT, servo0);
  setServo(SERVO1_POT, servo1);   
  setServo(SERVO2_POT, servo2);    
  setServo(SERVO3_POT, servo3);   
  setServo(SERVO4_POT, servo4);       
  delay(15);  
}

void setServo(int pot, Servo out) {
  int servo = analogRead(pot);            
  long int servo_val = map(servo, 0, 1023, 0, 120);     
  out.write(servo_val);  
}

