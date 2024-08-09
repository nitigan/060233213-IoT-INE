const int buzzer =  D8;

void setup() {
  pinMode(buzzer, OUTPUT);
       
}

void loop(){
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);  
}
