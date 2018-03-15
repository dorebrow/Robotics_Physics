
//motor A
const int enA = 9;
const int in1 = 5;
const int in2 = 4;

//motor B
const int enB = 6;
const int in3 = 8;
const int in4 = 7;

//ultrasonic
const int trigPin = 10;
const int echoPin = 11;

//determining distance
long duration;
int distance;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600); //starts serial communication
}

void loop () {
  //both motors forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);

  delay(2000);

  //motor opposite direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
 
  delay(2000);

  //turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
 //duration = pulseIn(echoPin, HIGH);

 //distance = duration*0.034/2;

  //digitalWrite(in1, HIGH);
  //digitalWrite(in2, LOW);
  // Set Motor B backward
  //digitalWrite(in3, HIGH);
  //digitalWrite(in4, LOW);
 
}
