#include<servo.h>
const int echo=2,trig=3,LED1=10,LED2=11,LED3=12;
const int speaker=8;
const int moistPin = A0,servoPin = 9;
const int dryThreshold = 700,wetThreshold = 400;
long duration;
int distance;
Servo dierectservo;

void setup(){
  Serial.begin(9600);
  directionServo.attach(servoPin);
  // Set initial servo position to the center (90 degrees)
  directionServo.write(90);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(speaker, OUTPUT);
}
void loop(){
  int moistureValue = analogRead(moistPin);
  // Print the value to the Serial Monitor
  Serial.print("Soil Moisture: ");
  Serial.print(moistureValue);
  // Case 1: Soil is DRY
  if (moistureValue >= dryThreshold) {
    Serial.println(" - Status: NON-BIO WASTE");
    directionServo.write(0);
  } 
  
  // Case 2: Soil is PERFECT/MODERATE
  else if (moistureValue < dryThreshold && moistureValue > wetThreshold) {
    Serial.println(" - Status: MODERATE");
    directionServo.write(90);
  } 
  
  // Case 3: Soil is WET
  else if (moistureValue <= wetThreshold) {
    Serial.println(" - Status: BIO-WASTE");
    directionServo.write(180);
  }
  digitalWrite(trig,LOW);
  delay(100);
  digitalWrite(trig,HIGH);
  delay(1000);
  digitalWrite(trig,LOW);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);

  duration=pulseIn(echo,HIGH);
  distance= duration*0.0343/2;

  if (distance<=15 && distance>13){
    digitalWrite(LED1,HIGH);
  }
  else if (distance<=7.5 && distance>5){
    digitalWrite(LED2,HIGH);  
  }
  else if(distance<=2 && distance>0){
    digitalWrite(LED3,HIGH);
    tone(speaker, 1000, 500);
  }

}