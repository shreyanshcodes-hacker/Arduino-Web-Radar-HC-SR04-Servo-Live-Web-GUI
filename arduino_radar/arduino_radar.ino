#include <Servo.h>

const byte TRIG_PIN = 9;
const byte ECHO_PIN = 10;
const byte SERVO_PIN = 6;

Servo radarServo;

float readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(3);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return 400.0;
  }

  return duration * 0.0343 / 2.0;
}

void sendMeasurement(int angle) {
  radarServo.write(angle);

  delay(35);

  float distance = readDistance();

  Serial.print(angle);
  Serial.print(",");
  Serial.println(distance, 1);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(115200);

  radarServo.attach(SERVO_PIN);

  radarServo.write(90);

  delay(1000);
}

void loop() {

  // Sweep 0 -> 180
  for (int angle = 0; angle <= 180; angle++) {
    sendMeasurement(angle);
  }

  // Sweep 180 -> 0
  for (int angle = 180; angle >= 0; angle--) {
    sendMeasurement(angle);
  }
}