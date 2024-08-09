


const int trigPin = D6;
const int echoPin = D5;

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;
int heightInch;
int heightDecimal;
int heightft;
int heightInchDecimal;

void setup() {
  
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  heightInch = distanceInch;
  heightft = distanceInch / 12 ;
  heightDecimal = distanceInch -(heightft * 12) ;
  
  
  // Prints the distance on the Serial Monitor
  Serial.print("height (cm): ");
  Serial.println(distanceCm);
  //Serial.print("Distance (inch): ");
  //Serial.println(distanceInch);

  //Serial.print("Distance (inch int): ");
  //Serial.println(heightInch);

  Serial.print("height (ft int): ");
  Serial.print(heightft);
  Serial.print("' ");

  //Serial.print("Distance (inch int): ");
  Serial.print(heightDecimal);
  Serial.println("\" ");

 
  
  delay(1000);
}
