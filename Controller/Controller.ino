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

const int laserPin = 12;

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);

  base.attach(10);
  shoulder.attach(9);
  elbow.attach(8);

  base.write(baseVal);
  shoulder.write(shoulderVal);
  elbow.write(elbowVal);

  pinMode(laserPin, OUTPUT);
}

void loop() {
  if (BTSerial.available() > 0) {
    data = BTSerial.read();

    data = tolower(data);
    
    Serial.print("Received data: "); Serial.println(data);

    if (data == 'l' && baseVal < MAX_ANGLE) baseVal += 15;
    if (data == 'r' && baseVal > MIN_ANGLE) baseVal -= 15;

    if (data == 'f' && shoulderVal < MAX_ANGLE) shoulderVal += 15;
    if (data == 'b' && shoulderVal > MIN_ANGLE) shoulderVal -= 15;

    if (data == 'u' && elbowVal < MAX_ANGLE) elbowVal += 15;
    if (data == 'd' && elbowVal > MIN_ANGLE) elbowVal -= 15;

    if (data == '1') digitalWrite(laserPin, 1);
    if (data == '0') digitalWrite(laserPin, 0);

    base.write(baseVal);
    shoulder.write(shoulderVal);
    elbow.write(elbowVal);

    delay(50);
  }
}
