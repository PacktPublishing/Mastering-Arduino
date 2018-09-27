
void blink_led(int led) {
  digitalWrite(led, HIGH);   
  delay(500);                       
  digitalWrite(led, LOW);    
  delay(500); 
}

