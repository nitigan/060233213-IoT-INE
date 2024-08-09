#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
//#include <DHT.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Color definitions
#define  BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//#define DHTPIN D4     // Digital pin connected to the DHT sensor

// Uncomment the type of sensor in use:
//#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

//DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  display.begin();

  //dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  //display.fillScreen(WHITE);
}

void loop() {
  
  delay(1000);
  int val = analogRead(A0) ;
  Serial.print("Analog Value = ");
  Serial.println(val);

  //read temperature and humidity
  //float t = dht.readTemperature();
  //float h = dht.readHumidity();
  //if (isnan(h) || isnan(t)) {
  //  Serial.println("Failed to read from DHT sensor!");
  //}

  //Serial.print("Temp = ");
  //Serial.print(t);
  //Serial.print("C - Humid = ");
  //Serial.print(h);
  //Serial.println(" %");

  //clear display
  display.clearDisplay();

  // display temperature
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0,0);
  display.print("analog = : ");
  display.setTextSize(3);
  display.setCursor(0,20);
  display.print(val);
  display.print(" ");
  //display.setTextSize(1);
  //display.cp437(true);
  //display.write(167);
  //display.setTextSize(2);
  //display.print("C");
  
  // display humidity
  //display.setTextSize(1);
  //display.setCursor(0, 35);
  //display.print("Humidity: ");
  //display.setTextSize(2);
  //display.setCursor(0, 45);
  //display.print(h);
  //display.print(" %"); 
  
  display.display(); 
}
