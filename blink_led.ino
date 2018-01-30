int LED = 2;
int x;

void setup() {
  pinMode(LED, OUTPUT);

}

void loop() {
  x = random(200, 3000);
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(x); 
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(x); 
}
