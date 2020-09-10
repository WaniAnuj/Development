#include <ServoTimer2.h>

ServoTimer2 claw;  // create servo object to control claw
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

void setup ( ) {
Serial.begin (9600) ;

claw.attach (claw_pin) ;   // attaches the servo by reading the value from the variable
left.attach (left_pin) ;
base.attach (base_pin) ;
right.attach (right_pin) ;

claw.write (initial_positionL);  // Initially the default position of the servo
left.write (initial_positionB);
base.write (initial_positionR);
right.write (initial_positionC);

}

void loop ( ) {

left_joy_val = analogRead (left_joy_ctrl);  // reads the value of the joystick1 (value between 0 and 1023)
base_joy_val = analogRead (base_joy_ctrl);

right_joy_val = analogRead (right_joy_ctrl);   // reads the value of the joystick2 (value between 0 and 1023)
claw_joy_val = analogRead (claw_joy_ctrl) ;
//Serial.println(claw_joy_val);

// if less than 300 or more than 700 the servo should move otherwise nothing
// Controlling the claw and base motor using 1st joystick
if (left_joy_val < 350)
{
if (initial_positionL > 2250)
{ }
else
{
  initial_positionL = initial_positionL + 16;
  left.write (initial_positionL);
  delay (10);
}
}
if (left_joy_val > 650)
{
if (initial_positionL < 755)
{ }
else
{
initial_positionL = initial_positionL - 16;
left.write (initial_positionL) ;
delay (10) ;
}
}

if (base_joy_val > 650){
if (initial_positionB > 2250)
{ }
else
{ initial_positionB = initial_positionB + 16;
base.write (initial_positionB);
delay (10) ;
}
}
if (base_joy_val < 350)
{
if (initial_positionB < 755)
{ }
else
{
initial_positionB = initial_positionB - 16;
base.write (initial_positionB) ;
delay (10) ;
}
}

// if less than 300 or more than 700 the servo should move otherwise nothing
// Controlling the left and right motor using 2nd joystick

if (right_joy_val > 650)
{
if (initial_positionR < 755)
{ }
else
{
  initial_positionR = initial_positionR - 16;
  right.write (initial_positionR);
  delay (10) ;
}
}
if (right_joy_val < 350)
{
if (initial_positionR > 2250)
{}
else
{
initial_positionR = initial_positionR + 16;
right.write (initial_positionR) ;
delay (10) ;
}
}

if (claw_joy_val < 350){
if (initial_positionC < 755)
{ }
else
{ initial_positionC = initial_positionC - 16;
claw.write (initial_positionC);
delay (10) ;
}
}
if (claw_joy_val > 650)
{
if (initial_positionC > 2250)
{ }
else
{
initial_positionC = initial_positionC + 16 ;
claw.write ( initial_positionC );
delay (10) ;
}
}
}
