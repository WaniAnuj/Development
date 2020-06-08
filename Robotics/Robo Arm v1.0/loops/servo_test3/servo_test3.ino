#include <Servo.h>

Servo claw;
Servo left;
Servo base;
Servo right;

int i;

 void setup() {
  // put your setup code here, to run once:
  claw.attach(6);
  left.attach(9);
  base.attach(10);
  right.attach(11);
  claw.write(40);
  left.write(0);
  base.write(0);
  right.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for(i=0;i<=100;i++){
//    right.write(i);
//    claw.write(i);
//    delay(10);
//  }
//  for(i=0;i<=100;i++){
//    claw.write(100-i);
//    delay(10);
//  }
//  for(i=0;i<=100;i++){
//    right.write(100-i);
//    left.write(i);
//    delay(10);
//  }
//  for(i=0;i<=75;i++){
//    base.write(i);
//    delay(10);
//  }
//  for(i=0;i<=100;i++){
//    right.write(i);
//    left.write(100-i);
//    delay(10);
//  }
//  for(i=0;i<=100;i++){
//    claw.write(i);
//    delay(10);
//  }
//  for(i=0;i<=100;i++){
//    right.write(100-i);
//    claw.write(100-i);
//    delay(10);
//  }
//  for(i=0;i<=75;i++){
//    base.write(75-i);
//    delay(10);
//  }
  
}
