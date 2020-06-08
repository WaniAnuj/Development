#include <SoftwareSerial.h>
#include <Servo.h>

int joystick;
int cn;
int clawppos;
int leftppos;
int baseppos;
int rightppos;
int t = 10;

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
  left.attach(9);
  base.attach(10);
  right.attach(11);
  clawppos = 0;
  claw.write(clawppos);
  leftppos = 0;
  left.write(leftppos);
  baseppos = 0;
  base.write(baseppos);
  rightppos = 0;
  right.write(rightppos);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bt.available()>0){
    joystick = bt.read();
    Serial.println(joystick);
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
  while(cn == 1){
    if(bt.available()>0){
      cn = bt.read();
    }
    base.write(baseppos);
    baseppos--;
    delay(t);
  }
  while(cn == 2){
    if(bt.available()>0){
      cn = bt.read();
    }
    base.write(baseppos);
    baseppos++;
    delay(t);
  }
    while(cn == 3){
    if(bt.available()>0){
      cn = bt.read();
    }
    left.write(leftppos);
    leftppos++;
    delay(t);
  }
   while(cn == 4){
    if(bt.available()>0){
      cn = bt.read();
    }
    left.write(leftppos);
    leftppos--;
    delay(t);
  }
    while(cn == 5){
    if(bt.available()>0){
      cn = bt.read();
    }
    claw.write(clawppos);
    clawppos--;
    delay(t);
  } 
  while(cn == 6){
    if(bt.available()>0){
      cn = bt.read();
    }
    claw.write(clawppos);
    clawppos++;
    delay(t);
  }
  while(cn == 7){
    if(bt.available()>0){
      cn = bt.read();
    }
    right.write(rightppos);
    rightppos++;
    delay(t);
  }
  while(cn == 8){
    if(bt.available()>0){
      cn = bt.read();
    }
    right.write(rightppos);
    rightppos--;
    delay(t);
  }
  while(cn == 0){
    if(bt.available()>0){
      cn=bt.read();  
  }
  }
  }
}
