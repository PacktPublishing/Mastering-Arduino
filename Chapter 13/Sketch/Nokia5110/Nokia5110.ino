#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// pin 13 - Serial clock out (SCLK)
// pin 11 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 5, 4, 3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  display.begin();
  // init done

  display.setContrast(40);

  display.display(); 
  delay(2000);
  display.clearDisplay();   

  display.drawPixel(10, 10, BLACK);
  display.drawPixel(11, 11, BLACK);
   display.drawPixel(12, 12, BLACK);
  display.display();
  delay(2000);
  display.clearDisplay();

  // draw a line
  display.drawLine(3,3,30,30, BLACK);
  display.display();
  delay(2000);
  display.clearDisplay();

  // Display text
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Hello, world!");
  // Reverse Text
  display.setTextColor(WHITE, BLACK); 
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.print("This is larger text");
  display.display();
  delay(2000);
  display.clearDisplay();

  // display rotated text
  display.setRotation(1);  // rotate 90 degrees counter clockwise, can also use values of 2 and 3 to go further.
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // draw circle
  display.drawCircle(display.width()/2, display.height()/2, 6, BLACK);
  display.display();
  delay(2000);
  display.clearDisplay();

  // draw fill circle 
  display.fillCircle(display.width()/2, display.height()/2, 6, BLACK);
  display.display();
  delay(2000);
  display.clearDisplay();

  // draw rectangle
  display.drawRect(15,15,30,15,BLACK);
  display.display();
  delay(2000);
  display.clearDisplay();

  // draw fill rectangle
  display.fillRect(15,15,30,15,BLACK);
  display.display();
  delay(2000);
  display.clearDisplay();

  // draw round rectangle
  display.drawRoundRect(15,15,30,15,4,BLACK);
  display.display();
  delay(2000);
  display.clearDisplay();

  // draw fill round rectangle
  display.fillRoundRect(15,15,30,15,8,BLACK);
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:

}
