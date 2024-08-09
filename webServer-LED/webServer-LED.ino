#include "ESP8266WiFi.h"
#include "AXWIFI.h"

const char* ssid = "OatTrue"; // Your Wi-Fi Name
const char* password = "152372231"; // Wi-Fi Password

int LED = D0;
WiFiServer server(80);

void setup() {

    Serial.begin(115200);

    ax.begin();
    ax.SledTypeRGB();
    ax.SledShow(0, 0, 0, 0);
    ax.SledShow(1, 0, 0, 0);

    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    Serial.print("Connecting to the Newtork");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }

    Serial.println("WiFi connected");
    server.begin(); // Starts the Server
    Serial.println("Server started");
    Serial.print("IP Address of network: "); // will IP address on Serial Monitor
    Serial.println(WiFi.localIP());
    Serial.print("Copy and paste the following URL: https://"); // Will print IP address in URL format
    Serial.print(WiFi.localIP());
    Serial.println("/");


}

void loop() {
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");
  
  while(!client.available())
  {
    delay(1);
  }
  
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  int value = LOW;
  if(request.indexOf("/LED=ON") != -1)
  {
    digitalWrite(LED, HIGH); // Turn LED ON
    value = HIGH;
  }
  if(request.indexOf("/LED=OFF") != -1)
  {
    digitalWrite(LED, LOW); // Turn LED OFF
    value = LOW;
  }

  //*------------------HTML Page Code---------------------*//
  client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print(" <h1> CONTROL LED: </h1>");
  if(value == HIGH)
  {
    client.print("<h1> LED ON </h1>");
  }
  else
  {
    client.print("<h1> LED OFF </h1>");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button><h1>ON</h1></button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button><h1>OFF</h1></button></a><br />");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}