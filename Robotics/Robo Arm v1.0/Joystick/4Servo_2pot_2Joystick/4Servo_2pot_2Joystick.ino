#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int potpin = A2;// analog pin used to connect the potentiometer
int potpin1 = A3;

int val;    // variable to read the value from the analog pin
int val1;

int x_key = A1;                                               
int y_key = A0;    
                                           
int x_pos;
int y_pos;

int servo1_pin = 10;
int servo2_pin = 9;  
int servo3_pin = 6;
int servo4_pin = 11;  

int initial_position = 90;
int initial_position1 = 90;
int initial_position2 = 90;
int initial_position3 = 90;

void setup ( ) {
Serial.begin (9600) ;

servo1.attach (servo1_pin ) ; 
servo2.attach (servo2_pin ) ; 
servo3.attach (servo3_pin ) ; 
servo4.attach (servo4_pin ) ; 

servo1.write (initial_position);
servo2.write (initial_position1);
servo3.write (initial_position2);
servo4.write (initial_position3);

pinMode (x_key, INPUT) ;                     
pinMode (y_key, INPUT) ;                      
}

void loop ( ) 
{
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 150);     // scale it to use it with the servo (value between 0 and 180)
  Serial.println(val);
  Serial.println("Rotating the Right Motor");
  servo3.write(val);                  // sets the servo position according to the scaled value 
  delay(10);                           // waits for the servo to get there
  

  val1 = analogRead(potpin1);            
  val1 = map(val1, 0, 1023, 0, 150);  
  Serial.println(val1);
  Serial.println("Rotating the Left Motor");
  servo4.write(val1);
  delay(10);  
  
x_pos = analogRead (x_key) ;  
Serial.println(x_pos);
y_pos = analogRead (y_key) ;                      
Serial.println(y_pos);
if (x_pos < 300)
{
if (initial_position > 180) 
{ } 
else
{ 
  initial_position = initial_position + 20; 
  servo2.write ( initial_position ); 
  delay (100) ;
}
}
if (x_pos > 700)
{
if (initial_position < 20)
{}  
else
{
initial_position = initial_position - 20;
servo1.write ( initial_position ) ;
delay (100) ;
}
}

if (y_pos < 300){
if (initial_position1 > 180) 
{ } 
else
{ initial_position1 = initial_position1 + 20;
servo2.write ( initial_position1 );
delay (100) ; 
} 
} 
if (y_pos > 700)
{
if (initial_position1 < 20)
{ }        
else
{
initial_position1 = initial_position1 - 20;
servo2.write ( initial_position1 ) ;
delay (100) ;
}
}
//delay(1000);
}
