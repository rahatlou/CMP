
const int LEDPIN = 13;

void setup() {
  // put your setup code here, to run once:
    pinMode(LEDPIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(LEDPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  analogWrite(LEDPIN, 250);
  delay(500);                       // wait for a second
  digitalWrite(LEDPIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
  //digitalWrite(LEDPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
   analogWrite(LEDPIN, 100);
  delay(200);                       // wait for a second
  digitalWrite(LEDPIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

}
