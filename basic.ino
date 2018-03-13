const int in1 = 7;
const int in2 = 6;
const int in3 = 8;
const int in4 = 9;
const int trigPin = 10;
const int echoPin = 11;

//long duration;
//int distance;

void setup() {
  pinMode(trigPin, OUTPUT); //sets trigPin as Output
  pinMode(echoPin, INPUT); //sets echoPin as Input
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600); //starts serial communication
}

void loop () {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
   
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

 duration = pulseIn(echoPin, HIGH);

 distance = duration*0.034/2;

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Set Motor B backward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
}
