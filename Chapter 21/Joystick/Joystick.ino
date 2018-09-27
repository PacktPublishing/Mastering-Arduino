#define SW_PIN 2 // digital pin 
#define X_PIN 0 // analog pin 
#define Y_PIN 1 // analog pin

void setup() {
  pinMode(SW_PIN, INPUT);
  digitalWrite(SW_PIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_PIN));
  Serial.print(" - ");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_PIN));
  Serial.print(" - ");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_PIN));
  Serial.print("\n");
  delay(500);
}
