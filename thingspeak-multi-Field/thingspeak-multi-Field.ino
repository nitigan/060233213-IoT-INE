#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "OatTrue";
const char* password = "152372231";

WiFiClient client;

unsigned long myChannelNumber = 2614704;
const char * myWriteAPIKey = "HPHA78KC9I649RT4";

unsigned long lastTime = 0;
unsigned long timerDelay = 15000;

int num1,temp,humid;
String myStatus = "";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  
}

void loop() {
  if((millis() - lastTime) > timerDelay){
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attemping to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password);
        delay(15000);  
      }
      Serial.println("\nConnected.");
    }

    num1 = random(10,90);
    temp = random(20,40);
    humid = random(40,99);
    Serial.print("Random Number = ");
    Serial.println(num1);
    Serial.print("temp = ");
    Serial.println(temp);
    Serial.print("humid = ");
    Serial.println(humid);

    ThingSpeak.setField(1, num1);
    ThingSpeak.setField(2, temp);
    ThingSpeak.setField(3, humid);

    //ThingSpeak.writeField(myChannelNumber, 1,num1,myWriteAPIKey);
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

    
    lastTime = millis();
  }
}
