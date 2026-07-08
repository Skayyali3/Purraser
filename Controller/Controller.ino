#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);

Servo base;
Servo shoulder;
Servo elbow;

const int basePotentio = A0;
const int shoulderPotentio = A1;
const int elbowPotentio = A2;

void setup() {
  base.attach(7);
  shoulder.attach(6);
  elbow.attach(5);
  pinMode(basePotentio, INPUT);
  pinMode(shoulderPotentio, INPUT);
  pinMode(elbowPotentio, INPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  int baseValue = analogRead(basePotentio);
  baseValue = map(baseValue, 0, 1023, 0, 180);
  base.write(baseValue);
  delay(50);
  int shoulderValue = analogRead(shoulderPotentio);
  shoulderValue = map(shoulderValue, 0, 1023, 0, 180);
  shoulder.write(shoulderValue);
  delay(50);
  int elbowValue = analogRead(elbowPotentio);
  elbowValue = map(elbowValue, 0, 1023, 0, 180);
  elbow.write(elbowValue);
  delay(50);
}
