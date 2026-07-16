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

    if (data == 'l' && baseVal < MAX_ANGLE) baseVal += 5;
    if (data == 'r' && baseVal > MIN_ANGLE) baseVal -= 5;

    if (data == 'f' && shoulderVal < MAX_ANGLE) shoulderVal += 5;
    if (data == 'b' && shoulderVal > MIN_ANGLE) shoulderVal -= 5;

    if (data == 'u' && elbowVal < MAX_ANGLE) elbowVal += 5;
    if (data == 'd' && elbowVal > MIN_ANGLE) elbowVal -= 5;

    if (data == 'i') digitalWrite(laserPin, 1); // cuz its the closest letter in terms of shape to binary ON
    if (data == 'o') digitalWrite(laserPin, 0); //same reason as above except binary OFF

    base.write(baseVal);
    shoulder.write(shoulderVal);
    elbow.write(elbowVal);

    delay(50);
  }
}
