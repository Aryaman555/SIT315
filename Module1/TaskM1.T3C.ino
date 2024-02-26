const int pirPin1 = 2;
const int pirPin2 = 3;
const int ledPin1 = 13;
const int ledPin2 = 12;

volatile bool motionDetected1 = false;
volatile bool motionDetected2 = false;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, INPUT);
  attachInterrupt(digitalPinToInterrupt(pirPin1), motionDetectedISR1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pirPin2), motionDetectedISR2, CHANGE);

  Serial.begin(9600);
}

void loop() {
}

void motionDetectedISR1() {
  motionDetected1 = digitalRead(pirPin1);
  if (motionDetected1) {
    Serial.println("Motion detected on PIR1");
    digitalWrite(ledPin1, HIGH);
    delay(1000);
    digitalWrite(ledPin1, LOW);
  }
}

void motionDetectedISR2() {
  motionDetected2 = digitalRead(pirPin2);
  if (motionDetected2) {
    Serial.println("Motion detected on PIR2");
    digitalWrite(ledPin2, HIGH);
    delay(1000);
    digitalWrite(ledPin2, LOW);
  }
}
