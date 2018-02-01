const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); //sets trigPin as Output
  pinMode(echoPin, INPUT); //sets echoPin as Input
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

 Serial.print("Distance: ");
 Serial.print(distance);
 Serial.print(" cm ");
 Serial.print("\n");
}
