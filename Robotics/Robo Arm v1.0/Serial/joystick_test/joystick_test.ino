#include <SoftwareSerial.h>
#include <Servo.h>

int joystick;
int cn;
int clawppos;

Servo claw;
Servo left;
Servo base;
Servo right;

SoftwareSerial bt(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
  claw.attach(6);
  clawppos = 0;
  claw.write(clawppos);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bt.available()>0){
    joystick = bt.read();
//    Serial.println(joystick);
  if(joystick == 0){
    cn=0;
  }
  if(joystick == 1){
    cn=1;
  }
  if(joystick == 2){
    cn=2;
  }
  if(joystick == 3){
    cn=3;
  }
  if(joystick == 4){
    cn=4;
  }
  if(joystick == 5){
    cn=5;
  }
  if(joystick == 6){
    cn=6;
  }
  if(joystick == 7){
    cn=7;
  }
  if(joystick == 8){
    cn=8;
  }
  while(cn == 6){
    if(bt.available()>0){
      cn = bt.read();
    }
    claw.write(clawppos);
    clawppos++;
    delay(20);
  }
  while(cn == 5){
    if(bt.available()>0){
      cn = bt.read();
    }
    claw.write(clawppos);
    clawppos--;
    delay(20);
  }
  while(cn == 0){
    if(bt.available()>0){
      cn=bt.read();  
  }
  }
  }
}
