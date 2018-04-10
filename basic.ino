#include <Servo.h>

Servo myservo;

//motor BACK
const int enA = 9;
const int in1 = 5;
const int in2 = 4;

//motor FRONT
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

int distCheck(int pos){
  myservo.write(pos);
  delay(15);
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
}

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

    if (distance >= range) {
      //both motors BACK
      analogWrite(enA, 10);
      analogWrite(in1, 145);
      analogWrite(in2, 0);

      //wheels turning
      analogWrite(enB, 100);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      delay(200);
     }

    else if (distance < range) {
      //motor forward
      analogWrite(enA, 10);
      analogWrite(in1, 0);
      analogWrite(in2, 145);  

      //wheels straight
      analogWrite(enB, 100);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW); 
      
      delay(300);
     }


   pos += angle;
   Serial.print("pos");
   }
   
   while(pos >= 270){
      pos -= angle;
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
   
      if (distance >= range) {
        // both motors BACK
        analogWrite(enA, 10);
        analogWrite(in1, 145);
        analogWrite(in2, 0);

        //Wheels turning
        analogWrite(enB, 100);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);

        delay(200);
      }

      else if (distance < range) {
        // motor opposite direction
        analogWrite(enA, 10);
        analogWrite(in1, 0);
        analogWrite(in2, 145);  

        //wheels straight
        analogWrite(enB, 100);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW); 
 
        delay(300);
      }
    
   }
 
}
