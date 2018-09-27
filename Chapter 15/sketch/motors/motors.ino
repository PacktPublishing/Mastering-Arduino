
#define MC_IN_1 3
#define MC_IN_2 2
#define MC_ENABLE 10


void setup() {
  // put your setup code here, to run once:
  pinMode(MC_ENABLE, OUTPUT);
  pinMode(MC_IN_1, OUTPUT);
  pinMode(MC_IN_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MC_IN_1, HIGH);
  digitalWrite(MC_IN_2, LOW);
  analogWrite(MC_ENABLE, 250);
  delay(2000);
  analogWrite(MC_ENABLE, 0);
  delay(1000);
  digitalWrite(MC_IN_1, LOW);
  digitalWrite(MC_IN_2, HIGH);
  analogWrite(MC_ENABLE, 150);
  delay(2000); 
  analogWrite(MC_ENABLE, 0);
  delay(1000);  
}
