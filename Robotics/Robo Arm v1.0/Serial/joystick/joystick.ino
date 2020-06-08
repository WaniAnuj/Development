#include <SoftwareSerial.h>
#include <Servo.h>

int joystick;

Servo claw;
Servo left;
Servo base;
Servo right;

SoftwareSerial bt(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bt.available()>0){
    joystick = bt.read();
    Serial.println(joystick);
  }
}
