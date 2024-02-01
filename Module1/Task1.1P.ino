const int motionSensorPin = 2;  // Motion sensor connected to digital pin 2
const int ledPin = 13;          // Built-in LED connected to digital pin 13

void setup() {
  Serial.begin(9600);          
  pinMode(motionSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int motionValue = digitalRead(motionSensorPin);  // Read motion sensor value

  if (motionValue == HIGH) {
    Serial.println("Motion Detected!");
    digitalWrite(ledPin, HIGH);  // Turn on LED
  } else {
    Serial.println("No Motion Detected");
    digitalWrite(ledPin, LOW);   // Turn off LED
  }

  delay(1000);  
}
