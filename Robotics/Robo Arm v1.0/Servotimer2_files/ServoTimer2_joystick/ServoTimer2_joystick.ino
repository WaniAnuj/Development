#include <ServoTimer2.h>

ServoTimer2 claw;  // create servo object to control claw
ServoTimer2 left;
ServoTimer2 base;
ServoTimer2 right;

int x_key = A0;    // analog pin used to connect the Joystick1
int y_key = A1;    // analog pin used to connect the Joystick1
int x_key1 = A2;   // analog pin used to connect the Joystick2
int y_key1 = A3;   // analog pin used to connect the Joystick2

int x_pos;        // variable to read the value from the analog pin
int y_pos;
int x_pos1;
int y_pos1;

int claw_pin = 6;   // variable to assign the servo to pin 6 
int left_pin = 9;   // variable to assign the servo to pin 9 
int base_pin = 10;  // variable to assign the servo to pin 10 
int right_pin = 11;  // variable to assign the servo to pin 11

int initial_position = 750;
int initial_position1 = 750;
int initial_position2 = 750;
int initial_position3 = 750;

void setup ( ) {
Serial.begin (9600) ;

claw.attach (claw_pin) ;   // attaches the servo by reading the value from the variable
left.attach (left_pin) ;
base.attach (base_pin) ;
right.attach (right_pin) ;

claw.write (initial_position);  // Initially the default position of the servo
left.write (initial_position1);
base.write (initial_position2);
right.write (initial_position3);

}

void loop ( ) {

x_pos = analogRead (x_key) ;  // reads the value of the joystick1 (value between 0 and 1023)
Serial.println(x_pos);
y_pos = analogRead (y_key) ;       
Serial.println(y_pos);


x_pos1 = analogRead (x_key1) ;   // reads the value of the joystick2 (value between 0 and 1023)
Serial.println(x_pos1);
y_pos1 = analogRead (y_key1) ;
Serial.println(y_pos1);

// if less than 300 or more than 700 the servo should move otherwise nothing
// Controlling the claw and base motor using 1st joystick
if (x_pos < 350)
{
if (initial_position > 2250)
{ }
else
{
  initial_position = initial_position + 24;
  claw.write (initial_position);
  delay (10);
}
}
if (x_pos > 650)
{
if (initial_position < 755)
{ }
else
{
initial_position = initial_position - 5;
claw.write (initial_position) ;
delay (10) ;
}
}

if (y_pos < 350){
if (initial_position1 > 2250)
{ }
else
{ initial_position1 = initial_position1 + 24;
left.write (initial_position1);
delay (10) ;
}
}
if (y_pos > 650)
{
if (initial_position1 < 755)
{ }
else
{
initial_position1 = initial_position1 - 24;
left.write (initial_position1) ;
delay (10) ;
}
}

// if less than 300 or more than 700 the servo should move otherwise nothing
// Controlling the left and right motor using 2nd joystick

if (x_pos1 < 350)
{
if (initial_position2 < 755)
{ }
else
{
  initial_position2 = initial_position2 - 24;
  base.write (initial_position2);
  delay (10) ;
}
}
if (x_pos1 > 650)
{
if (initial_position2 > 2250)
{}
else
{
initial_position2 = initial_position2 + 24;
base.write (initial_position2) ;
delay (10) ;
}
}

if (y_pos1 < 350){
if (initial_position3 < 755)
{ }
else
{ initial_position3 = initial_position3 - 24;
right.write (initial_position3);
delay (10) ;
}
}
if (y_pos1 > 650)
{
if (initial_position3 > 2250)
{ }
else
{
initial_position3 = initial_position3 + 24;
right.write ( initial_position3 ) ;
delay (10) ;
}
}
}
