#define PIR_PIN 2
#define PHOTOSENSOR_PIN A0
#define EXTERNAL_LED_PIN 7

bool motionDetected = false;
bool lightDetected = false;

void setup() {
  pinMode(EXTERNAL_LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(PHOTOSENSOR_PIN, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), motionChange, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PHOTOSENSOR_PIN), lightIntensityChange, CHANGE);
}

void loop() {
  if (motionDetected || lightDetected) {
    digitalWrite(EXTERNAL_LED_PIN, HIGH);
    Serial.println("Motion or Light detected!");
    delay(1000);
    motionDetected = false;
    lightDetected = false;
  } else {
    digitalWrite(EXTERNAL_LED_PIN, LOW);
  }
  delay(100);
}

void motionChange() {
  motionDetected = !motionDetected;
}

void lightIntensityChange() {
  int lightIntensity = analogRead(PHOTOSENSOR_PIN);
  if (lightIntensity > 500) {
    lightDetected = true;
  }
}
