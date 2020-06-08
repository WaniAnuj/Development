#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo1;


int potpin = 0;// analog pin used to connect the potentiometer
int potpin1 = 1;


int val;    // variable to read the value from the analog pin
int val1;


void setup() {
  Serial.begin(9600);
  myservo.attach(11);  // attaches the servo on pin 8 to the servo object
  myservo1.attach(6);
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 150);     // scale it to use it with the servo (value between 0 and 180)
  Serial.println(val);
  Serial.println("Rotating the Right Motor");
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(10);                           // waits for the servo to get there
  

  val1 = analogRead(potpin1);            
  val1 = map(val1, 0, 1023, 0, 150);  
  Serial.println(val1);
  Serial.println("Rotating the Left Motor");
  myservo1.write(val1);
  delay(10);  
  
                            
}
