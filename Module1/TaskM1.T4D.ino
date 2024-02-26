#include <avr/io.h>
#include <avr/interrupt.h>

const int pirPin1 = 2;
const int pirPin2 = 3;
const int pirPin3 = 4;
const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;

volatile bool motionDetected1 = false;
volatile bool motionDetected2 = false;
volatile bool motionDetected3 = false;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, INPUT);
  pinMode(pirPin3, INPUT);

  PCICR |= (1 << PCIE2);
  PCMSK2 |= (1 << PCINT2);
  PCMSK2 |= (1 << PCINT1);
  PCMSK2 |= (1 << PCINT0);

  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 15624;

  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);

  TIMSK1 |= (1 << OCIE1A);

  Serial.begin(9600);
}

void loop() {
}

ISR(PCINT2_vect) {
  motionDetected1 = digitalRead(pirPin1);
  if (motionDetected1) {
    Serial.println("Motion detected on PIR1");
    digitalWrite(ledPin1, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }

  motionDetected2 = digitalRead(pirPin2);
  if (motionDetected2) {
    Serial.println("Motion detected on PIR2");
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }

  motionDetected3 = digitalRead(pirPin3);
  if (motionDetected3) {
    Serial.println("Motion detected on PIR3");
    digitalWrite(ledPin3, HIGH);
  } else {
    digitalWrite(ledPin3, LOW);
  }
}

ISR(TIMER1_COMPA_vect) {
  static bool ledState = LOW;
  digitalWrite(ledPin1, ledState);
  ledState = (ledState == LOW) ? HIGH : LOW;
}
