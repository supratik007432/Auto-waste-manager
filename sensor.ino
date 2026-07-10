// Define the pins connected to the sensor and LED
const int echo=2,trig=3;
const int LED1=10;
const int LED2=11;
const int LED3=12;
const int moistPin = A0;
const int servoPin = 9;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
}

void loop() {

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
  }

  Serial.println(distance);
}