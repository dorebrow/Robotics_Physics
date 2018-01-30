int forward = 11;
int reverse = 10;
int left = 5;
int right = 9;

void setup() {
  digitalWrite(2, HIGH);

}

void loop() {
  analogWrite(forward, 150);
  delay(2000);
  analogWrite(forward, 0);
  delay(1000);
  analogWrite(reverse, 150);
  delay(2000);
  analogWrite(reverse, 0);
  delay(1000);
  

}
