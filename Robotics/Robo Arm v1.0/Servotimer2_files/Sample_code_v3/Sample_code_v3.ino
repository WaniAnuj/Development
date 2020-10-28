#include <SoftwareSerial.h>
#include <ServoTimer2.h>

const byte numChars = 200;
char receivedChars[numChars];
int motor = 0;
char* commands[50];
char* token;
int pos;
int pos1;
int pos2;
int negpos;
int negpos2;
int count = 0;
int loop_count = 0;
int i;

ServoTimer2 claw;
ServoTimer2 left;
ServoTimer2 base;
ServoTimer2 right;

int left_joy_ctrl = A0;    // analog pin used to connect the Joystick1
int base_joy_ctrl = A3;    // analog pin used to connect the Joystick1
int right_joy_ctrl = A2;   // analog pin used to connect the Joystick2
int claw_joy_ctrl = A1;   // analog pin used to connect the Joystick2

int left_joy_val;        // variable to read the value from the analog pin
int base_joy_val;
int right_joy_val;
int claw_joy_val;

int claw_pin = 6;   // variable to assign the servo to pin 6 
int left_pin = 9;   // variable to assign the servo to pin 9 
int base_pin = 10;  // variable to assign the servo to pin 10 
int right_pin = 11;  // variable to assign the servo to pin 11

int initial_positionL = 750;
int initial_positionB = 750;
int initial_positionR = 750;
int initial_positionC = 750;

boolean newData = false;

SoftwareSerial bt(2,4);

void setup() {
    Serial.begin(9600);
    bt.begin(9600);
    
    claw.attach(6);
    left.attach(9);
    base.attach (10);
    right.attach(11);
    
    claw.write(750);
    left.write(750);
    base.write(750);
    right.write(750);
    
    Serial.println("<Arduino is ready>");
}

void loop() {
// 80 aproximately equals to 10 deg
for(i=750;i<=1583;i+=8){
    claw.write(i);
    delay(10);
}
for(i=750;i<=1583;i+=8){
    right.write(i);
    delay(10);
}
  for(i=750;i<=1583;i+=8){
    claw.write(2333-i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    right.write(2333-i);
//    left.write(i);
    delay(10);
  }
  for(i=750;i<=1375;i+=8){
    base.write(i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    right.write(i);
//    left.write(2333-i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    claw.write(i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    claw.write(2333-i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    right.write(2333-i);
    delay(10);
  }
  for(i=750;i<=1375;i+=8){
    base.write(2125-i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    right.write(i);
    delay(10); 
  }
  for(i=750;i<=1583;i+=8){
    claw.write(i); 
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    right.write(2333-i);
    delay(10);
}
  for(i=750;i<=1583;i+=8){
    claw.write(2333-i);
    delay(10);
}
}
