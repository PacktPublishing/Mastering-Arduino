
#define COLLISION_SWITCH 4
#define IR_SENSOR 3
#define RANGE_SENSOR A1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(COLLISION_SWITCH, INPUT);
  pinMode(IR_SENSOR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int collisionValue = digitalRead(COLLISION_SWITCH);
  if (isnan(collisionValue)) {
    Serial.println(" Failed to read collision sensor");
    return;
  }
  if (collisionValue == LOW) {
    Serial.println("Collision Detected");
  }

  int irValue = digitalRead(IR_SENSOR);
  if (isnan(irValue)) {
    Serial.println(" Failed to read infrared sensor");
    return;
  }
  if (irValue == LOW) {
    Serial.println("IR Detected");
  }

  int anVolt = analogRead(RANGE_SENSOR);
  if (isnan(anVolt)) {
    Serial.println(" Failed to read range sensor");
    return;
  }
  int mm = anVolt*5; 
  float inch = mm/25.4;
  Serial.print("MM:      ");
  Serial.println(mm);
  Serial.print("Inches:  ");
  Serial.println(inch);
  Serial.println("---------------------------");
  delay(1000);
}
