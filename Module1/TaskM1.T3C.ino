const int pirSensor = 2;
const int pirLed = 7;
const int buzzer = 8;
const int tmpSensor = A0;

void setup() {
  pinMode(pirLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pirSensor, INPUT);
  pinMode(tmpSensor, INPUT);

  Serial.begin(9600);
}

void loop() {
  checkPIR();
  checkTMP();
  delay(200);
}

void checkPIR() {
  if (digitalRead(pirSensor) == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(pirLed, HIGH);
    delay(2000);
  } else {
    digitalWrite(pirLed, LOW);
  }
}

void checkTMP() {
  int temperature = analogRead(tmpSensor);
  float voltage = temperature * 5.0 / 1024;
  float celsius = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" degrees Celsius");

  if (celsius > 75) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }
}
