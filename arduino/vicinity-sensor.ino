
// pins being used
#define trigPin 9
#define echoPin 10
#define ledPin 13
#define variableLedPin 11
#define speakerPin 3


// speed of sound: 340 m/s = 0.034 cm/us
#define soundSpeed 0.034

void setup() {
  // define input and output pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(variableLedPin, OUTPUT);

  // establish serial port connection for data transfer
  Serial.begin(9600);
  
}

void loop() {

  // turn off  LED and prepare trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(ledPin, LOW);


  // send trigger signal of 10 us to start acquisition with ultrasonic sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // travel time (roundtrip) in micro seconds
  long duration = pulseIn(echoPin, HIGH);

  // distance in cm
  long distance = soundSpeed * duration/2.;

  // turn on LED for a time proportional to the duration
  digitalWrite(ledPin, HIGH); 
  delayMicroseconds(duration*1000*5);
  digitalWrite(ledPin, LOW); 

  // turn on another LED with brightness inversely proportional to distance
  // emit sound with frequency inversely propotional to distance
  unsigned int bright = 0;
  unsigned int freq = 0;

  // define min and max values -- they can be moved out of loop
  const unsigned int minDist = 5;
  const unsigned int maxDist = 65;

  const unsigned int minFreq = 31;
  const unsigned int maxFreq = 4900;
  
  if(distance<=minDist) {
      bright = 255;
      freq = maxFreq;
  } else if(distance<=maxDist) {
    bright = 255-5.67*(distance-minDist);
    freq = maxFreq - (distance-minDist)*(maxFreq)/(maxDist-minDist) + minFreq;
  }
  
  analogWrite(variableLedPin, bright);
  tone(speakerPin, freq,100);

   // write to output
 // Serial.print("Distance (cm): \t"); 
  //Serial.print(distance);
  //Serial.print("\t frequency (Hz): \t"); 
  //Serial.println(freq);

  Serial.println(distance);
  delay(300);
  
}
