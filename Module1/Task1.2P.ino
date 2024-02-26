const int pirPin = 2;
const int ledPin = 13;

volatile bool motionDetected = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(pirPin), motionDetectedISR, CHANGE);

  Serial.begin(9600);
}

void loop() {
}

void motionDetectedISR() {
  motionDetected = digitalRead(pirPin);
  if (motionDetected) {
    Serial.println("Motion detected");
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
  }
}
