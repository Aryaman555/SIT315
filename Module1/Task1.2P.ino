bool on = false;

void setup() {
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0, ledchange, FALLING);
}

void loop() {
  delay(1000);
}

void ledchange() {
  on = !on;
  if (on) {
    digitalWrite(6, LOW);
    Serial.println("LED state: LOW");
  } else {
    digitalWrite(6, HIGH);
    Serial.println("LED state: HIGH");
  }
}
