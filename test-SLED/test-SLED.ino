#include "ESP8266WiFi.h"
#include "AXWIFI.h"

const int btn = 12;

void setup() {
    Serial.begin(9600);
    ax.begin();
    ax.SledTypeRGB();
    ax.SledShow(0, 0, 0, 0);
    ax.SledShow(1, 0, 0, 0);

    pinMode(btn, INPUT);
}

void loop() {
    Serial.println("Hello, world!");
    Serial.println(digitalRead(btn));

    delay(1000);
}