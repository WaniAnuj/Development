// most reliable out of others

#include <Servo.h>

Servo myservo;
 
int pos = 90;

const int s0 = 7;
const int s1 = 8;
const int s2 = 4;
const int s3 = 3;
const int out = 2;

// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  

//Motor A
const int left_motor_1  = 12;    // when 1 > 2, forward
const int left_motor_2  = 13;    // when 2 > 1, reverse
//Motor B
const int right_motor_1  = 9;   // when 1 > 2, forward
const int right_motor_2  = 10;   // when 2 > 1, reverse

const int en1 = 5; // extra supply
const int en2 = 6; // extra supply

int colorid = 0; // stores checked color inside local variable
int linecolor = 0; // stores line following color
int tempcolor = 0; // stores temporary checked color
int dir = 0; // 1 for left, 2 for right

void setup()   
{  
  Serial.begin(9600);
  myservo.attach(11);
  myservo.write(90);
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
  pinMode(left_motor_1, OUTPUT);
  pinMode(left_motor_2, OUTPUT);
  pinMode(right_motor_1, OUTPUT);
  pinMode(right_motor_2, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  delay(2000);

  Serial.println("Started");
  delay(1000); 
  tempcolor = colorCheck();
  Serial.println(tempcolor);
  while (tempcolor == 4)
  {
    Serial.println("No RGB line detected!");
    stopRobot();
    tempcolor = colorCheck();
  }
  Serial.println("Line detected");
  linecolor = tempcolor;
  Serial.println(linecolor); 
}  
    
void loop() 
{  
  while(tempcolor == linecolor)
  {
    Serial.println("Following line");
    switch(linecolor){
      case 1: Serial.println("Following RED color"); break;
      case 2: Serial.println("Following BLUE color"); break;
      case 3: Serial.println("Following GREEN color"); break;
      default: Serial.println("Unknown colour"); break;
      }
    if(88<=pos<=95){
        moveForward();
      }
      else{
        Serial.println(pos);
        stopRobot();
      }
    tempcolor = colorCheck();
  }
    stopRobot();
    Serial.println("Checking color");
    dir = servoCheck();
    Serial.println(dir);
    switch(dir){
      case 0: stopRobot(); break;
      case 1: moveLeft(); break;
      case 2: moveRight(); break;
      case 3: moveForward();break;
      default: break;
      }
  tempcolor = colorCheck();
  }
   
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
//  Serial.print(" R Intensity:");  
//  Serial.print(red, DEC);  
//  Serial.print(" G Intensity: ");  
//  Serial.print(green, DEC);  
//  Serial.print(" B Intensity : ");  
//  Serial.print(blue, DEC);
//  Serial.println();   
}

int colorCheck()
{
  color();
  if (red < 12 && green < 12 && blue < 12)  
  {  
   Serial.println(" - (White Color)");   
   colorid = 4;
  }  
  
  else if (red < blue && red < green && red < 20)
  {  
   Serial.println(" - (Red Color)");
   colorid = 1;
  }  
 
  else if (blue < red && blue < green)   
  {  
   Serial.println(" - (Blue Color)");  
   colorid = 2; 
  }  
 
 else if (green < red && green < blue)  
  {  
   Serial.println(" - (Green Color)");   
   colorid = 3;
  }  

  else
  {
  Serial.println();
  colorid = 0;  
  }
  return colorid;
  delay(100);
}

int servoCheck()
{
  dir = 0;
  for (pos = 90; pos >= 10; pos -= 1) {
  myservo.write(pos);
  delay(10);
  }
  tempcolor = colorCheck();
  if(linecolor == tempcolor)
  {
    dir = 2;
    return(dir);
  }
  else{
  for (pos = 0; pos <= 170; pos += 1) {
  myservo.write(pos);
  delay(10);
  }
  tempcolor = colorCheck();
  if(linecolor == tempcolor)
  {
    dir = 1;
    return(dir);
  }
  else{
  for (pos = 170; pos >= 90; pos -= 1) {
  myservo.write(pos);
  delay(10);
  }
  tempcolor = colorCheck();
  if(linecolor == tempcolor)
  {
    dir = 3;
    return(dir);
  }
  }
  delay(10);
  }
}

void moveForward()
{
  Serial.println("Moving forward");
  analogWrite(en1, 100);
  analogWrite(en2, 100);
  digitalWrite(left_motor_1, HIGH);
  digitalWrite(left_motor_2, LOW);
  digitalWrite(right_motor_1, HIGH);
  digitalWrite(right_motor_2, LOW);
  delay(50);
}

void stopRobot()
{
  Serial.println("Stopping");
  analogWrite(en1, 0);
  analogWrite(en2, 0);
  digitalWrite(left_motor_1, LOW);
  digitalWrite(left_motor_2, LOW);
  digitalWrite(right_motor_1, LOW);
  digitalWrite(right_motor_2, LOW);
  delay(30);
}

void moveLeft()
{
  Serial.println("Moving left");
  analogWrite(en1, 100);
  analogWrite(en2, 150);
  digitalWrite(left_motor_1, HIGH);
  digitalWrite(left_motor_2, LOW);
  digitalWrite(right_motor_1, LOW);
  digitalWrite(right_motor_2, HIGH);
  delay(50);
}

void moveRight()
{
  Serial.println("Moving right");
  analogWrite(en1, 200);
  analogWrite(en2, 100);
  digitalWrite(left_motor_1, LOW);
  digitalWrite(left_motor_2, HIGH);
  digitalWrite(right_motor_1, HIGH);
  digitalWrite(right_motor_2, LOW);
  delay(50);
}
