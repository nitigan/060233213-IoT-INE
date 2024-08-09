#include "AXWIFI.h"
int R = D1;
int G = D2;
int B = D0;
int rNum;
int gNum;
int bNum;

void setup() {
  ax.begin();
  ax.SledTypeGRB();
  ax.SledShow(0,0,0,0);
  ax.SledShow(1,0,0,0);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(9600);
}
void loop() {

  rNum = random(256);
  gNum = random(256);
  bNum = random(256);
      
  analogWrite(R, rNum);
  analogWrite(G, gNum);
  analogWrite(B, bNum);
  delay(2000);

  Serial.print("rNumber = ");
  Serial.print(rNum );
  Serial.print(" : gNumber = ");
  Serial.print(gNum );
  Serial.print(" : bNumber = ");
  Serial.println(bNum );

}
