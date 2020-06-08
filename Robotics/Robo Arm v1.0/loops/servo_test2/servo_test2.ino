#include<Servo.h>

Servo one;
Servo two;
Servo three;
Servo four;

int val;

void setup(){
  Serial.begin(9600);
  one.attach(6); //claw on pcb
  two.attach(9); //left motor on pcb
  three.attach(10); //base motor on pcb
  four.attach(11); //right motor
  one.write(0);
  two.write(0);
  three.write(0);
  four.write(0);
}

void loop(){
  
//  Serial.println("Incrementing motor 1 conected to pin 6");
//  for(val=0;val<=120;val++)
//  {
//    two.write(val);
//    one.write(val);
//    three.write(val);
//    four.write(val);
//    delay(10);
//  }
//
//   for(val=0;val<=120;val++)
//  {
//    one.write(120-val);
//    two.write(120-val);
//    three.write(120-val);
//    four.write(120-val);
//    delay(10);
//  }
//  
//  Serial.println("Decrementing motor 1 conected to in 6");
//  for(val=120;val>=0;val--)
//  {
//    two.write(val);
//    four.write(val);
//    delay(20);
//  }
//
//  for(val=0;val<=75;val++)
//  {
//    three.write(val);
//    delay(20);
//  }
//
//    for(val=0;val<=120;val++)
//  {
//    two.write(val);
//    four.write(val);
//    delay(20);
//  }
//
//  for(val=0;val<=120;val++)
//  {
//    one.write(val);
//    delay(20);
//  }
//
//  for(val=120;val>=0;val--)
//  {
//    two.write(val);
//    four.write(val);
//    one.write(val);
//    delay(20);
//  }
//
//  for(val=0;val<=75;val++)
//  {
//    three.write(75-val);
//    delay(20);
//  }
  
}
