#include <Servo.h>

Servo myservo;

//motor A
const int enA = 9;
const int in1 = 5;
const int in2 = 4;

//motor B
const int enB = 6;
const int in3 = 8;
const int in4 = 7;

//ultrasonic
const int trigPin = 11;
const int echoPin = 10;

//determining distance
long duration;
int distance;

//variable to store the servo position
int pos = 0;

//range variable
int range = 60;

//scanning angle
int angle = 45;

void setup() {
  myservo.attach(3);
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); //starts serial communication
}

void loop () {
  while(pos < 270){
    myservo.write(pos);
    delay(15);
    
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;

    Serial.print("Distance: "); 
    Serial.println(distance); 
    delay(15); 

   Serial.print(pos);

    if (distance < range) {
      //both motors forward
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 100);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 100);

      delay(100);
     }

    else if (distance >= range) {
      //motor opposite direction
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);  
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH); 
 
      delay(100);
     }
  
   //turn off motors
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);  
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);


   pos += angle;
   }
   
   while(pos >= 0){
      Serial.print(pos);
      pos -= angle;
      myservo.write(pos);
      delay(15);
      
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
   
      if (distance < range) {
        // both motors forward
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(enA, 100);

        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enB, 100);

        delay(100);
      }

      else if (distance >= range) {
        // motor opposite direction
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);  
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH); 
 
        delay(100);
      }
  
    //turn off motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
   }
 
}
