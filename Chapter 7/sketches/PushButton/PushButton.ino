
#define BUTTON_ONE 12

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  pinMode(BUTTON_ONE, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(BUTTON_ONE);  
  if (val == HIGH) {         
    Serial.println("Button HIGH");
  } else {
    Serial.println("Button LOW");
  }
}
