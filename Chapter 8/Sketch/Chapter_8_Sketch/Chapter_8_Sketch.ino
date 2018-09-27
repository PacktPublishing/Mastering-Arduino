
#define MOTION_SENSOR 3

void setup() {
  pinMode(MOTION_SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(MOTION_SENSOR);
  if (sensorValue == HIGH) {
    Serial.println("Motion Detected");
  }
  delay(500);
}
