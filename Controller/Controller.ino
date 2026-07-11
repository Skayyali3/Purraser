#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);

Servo base;
Servo shoulder;
Servo elbow;

char data;

int baseVal = 90;
int shoulderVal = 90;
int elbowVal = 90;

const int MAX_ANGLE = 170;
const int MIN_ANGLE = 10;

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);

  base.attach(7);
  shoulder.attach(6);
  elbow.attach(5);

  base.write(baseVal);
  shoulder.write(shoulderVal);
  elbow.write(elbowVal);
}

void loop() {
  if (BTSerial.available() > 0) {

    data = BTSerial.read();
    Serial.print("Received data: "); Serial.println(data);

    if (data == 'L' && baseVal < MAX_ANGLE) baseVal += 5;
    if (data == 'R' && baseVal > MIN_ANGLE) baseVal -= 5;

    if (data == 'F' && shoulderVal < MAX_ANGLE) shoulderVal += 5;
    if (data == 'B' && shoulderVal > MIN_ANGLE) shoulderVal -= 5;

    if (data == 'U' && elbowVal < MAX_ANGLE) elbowVal += 5;
    if (data == 'D' && elbowVal > MIN_ANGLE) elbowVal -= 5;
  }

  base.write(baseVal);
  shoulder.write(shoulderVal);
  elbow.write(elbowVal);

  delay(50);
}
