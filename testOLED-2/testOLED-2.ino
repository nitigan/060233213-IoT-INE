#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Adafruit_SSD1306 display(OLED_RESET);
//Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &WIRE);
int value;
void setup() {
  Serial.begin(9600);
  display.clearDisplay();
  display.setTextColor(WHITE);
}
void loop() {

  int val = analogRead(A0) ;

  Serial.print("Analog Value = ");
  Serial.println(val);


  display.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  display.setTextSize(1); // กำหนดขนาดตัวอักษร
  display.setTextColor(WHITE);

  display.setCursor(0,0); // 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(" Analog Value ");

  display.setCursor(0,32);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(val);
  display.display(); 
  
  delay(1000);
  
}
