const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;
// LED pins connected to Arduino
//int redLed = 2;  
//int greenLed = 3;  
//int blueLed = 4;
// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  

//Motor A
const int left_motor_1  = 4;    // when 1 > 2, forward
const int left_motor_2  = 5;    // when 2 > 1, reverse
//Motor B
const int right_motor_1  = 6;   // when 1 > 2, forward
const int right_motor_2  = 7;   // when 2 > 1, reverse

const int supply1 = 2; // extra supply
const int supply2 = 3; // extra supply

int count = 0;

void setup()   
{  
  Serial.begin(9600); 
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
    pinMode(supply1, OUTPUT);
    digitalWrite(supply1, HIGH);
    pinMode(supply2, OUTPUT);
    digitalWrite(supply2, HIGH);
}  
    
void loop() 
{  
  color(); 
  Serial.print(" R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);  
  //Serial.println();  
 
  if (red < blue && red < green && red < 20)
  {  
   Serial.println(" - (Red Color)");
   count = 1;
  }  
 
  else if (blue < red && blue < green)   
  {  
   Serial.println(" - (Blue Color)");  
   count = 2; 
  }  
 
 else if (green < red && green < blue)  
  {  
   Serial.println(" - (Green Color)");   
   count = 3;
  }  
  else
  {
  Serial.println();
  count = 0;  
  }
  // delay(300);   

  if (count == 1){
    while(red < blue && red < green && red < 20){
      color();
      Serial.println("RED Colour, Moving forward");
        digitalWrite(left_motor_1, HIGH); // left motor forward
        digitalWrite(left_motor_2, LOW);
        digitalWrite(right_motor_1, HIGH); // right motor forward
        digitalWrite(right_motor_2, LOW);
      }
      count = 0;
      digitalWrite(left_motor_1, LOW); // left motor stop
      digitalWrite(left_motor_2, LOW);
      digitalWrite(right_motor_1, LOW); // right motor stop
      digitalWrite(right_motor_2, LOW);
      delay(1000);

      // Move left and check
      digitalWrite(left_motor_1, LOW); // left motor stop
      digitalWrite(left_motor_2, LOW);
      digitalWrite(right_motor_1, HIGH); // right motor forward
      digitalWrite(right_motor_2, LOW);
      delay(100);

      
    }
   else if(count == 2){
    while(blue < red && blue < green){
      color();
      Serial.println("BLUE Colour, Moving forward");
        digitalWrite(left_motor_1, HIGH); // left motor forward
        digitalWrite(left_motor_2, LOW);
        digitalWrite(right_motor_1, HIGH); // right motor forward
        digitalWrite(right_motor_2, LOW);
      }
      count = 0;
      digitalWrite(left_motor_1, LOW); // left motor stop
      digitalWrite(left_motor_2, LOW);
      digitalWrite(right_motor_1, LOW); // right motor stop
      digitalWrite(right_motor_2, LOW);
      delay(1000);

      // Move right and check
      digitalWrite(left_motor_1, HIGH); // left motor stop
      digitalWrite(left_motor_2, LOW);
      digitalWrite(right_motor_1, LOW); // right motor forward
      digitalWrite(right_motor_2, LOW);
      delay(100);
    }
    else if(count == 3){
    while(green < red && green < blue){
      color();
      Serial.println("GREEN Colour, Moving forward");
        digitalWrite(left_motor_1, HIGH); // left motor forward
        digitalWrite(left_motor_2, LOW);
        digitalWrite(right_motor_1, HIGH); // right motor forward
        digitalWrite(right_motor_2, LOW);
      }
      count = 0;
      digitalWrite(left_motor_1, LOW); // left motor stop
      digitalWrite(left_motor_2, LOW);
      digitalWrite(right_motor_1, LOW); // right motor stop
      digitalWrite(right_motor_2, LOW);
      delay(1000);
    }
    else{
      digitalWrite(left_motor_1, LOW); // left motor stop
      digitalWrite(left_motor_2, LOW);
      digitalWrite(right_motor_1, LOW); // right motor stop
      digitalWrite(right_motor_2, LOW);
      }
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
}
