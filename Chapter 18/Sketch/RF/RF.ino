
#define BUTTON_A 10
#define BUTTON_B 8
#define BUTTON_C 11
#define BUTTON_D 9

void setup() {
  pinMode(BUTTON_A, INPUT); 
  pinMode(BUTTON_B, INPUT); 
  pinMode(BUTTON_C, INPUT); 
  pinMode(BUTTON_D, INPUT); 
  Serial.begin(9600);
}

void loop() {
  int valA = digitalRead(BUTTON_A);
  if (valA == HIGH) {
    Serial.println("Button A");
  }

  int valB = digitalRead(BUTTON_B);
  if (valB == HIGH) {
    Serial.println("Button B");
  }

  int valC = digitalRead(BUTTON_C);
  if (valC == HIGH) {
    Serial.println("Button C");
  }

  int valD = digitalRead(BUTTON_D);
  if (valD == HIGH) {
    Serial.println("Button D");
  }
  delay(100);
}
