const int pirSensor = 2;
const int pirLed = 7;

void setup() {
  pinMode(pirLed, OUTPUT);
  pinMode(pirSensor, INPUT);

  Serial.begin(9600);
}

void loop() {
  checkPIR();
  delay(200);
}

void checkPIR() {
  if (digitalRead(pirSensor) == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(pirLed, HIGH);
    delay(2000);
  } else {
    Serial.println("No Motion detected!");
    digitalWrite(pirLed, LOW);
    delay(2000);
  }
}
