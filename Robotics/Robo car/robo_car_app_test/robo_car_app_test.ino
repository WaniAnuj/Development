int pos = 0;

//Motor A
const int left_motor_1  = 12;    // when 1 > 2, forward
const int left_motor_2  = 13;    // when 2 > 1, reverse
//Motor B
const int right_motor_1  = 9;   // when 1 > 2, forward
const int right_motor_2  = 10;   // when 2 > 1, reverse

const int en1 = 5; // extra supply
const int en2 = 6; // extra supply

void setup()   
{  
  Serial.begin(9600);
    pinMode(left_motor_1, OUTPUT);
    pinMode(left_motor_2, OUTPUT);
    pinMode(right_motor_1, OUTPUT);
    pinMode(right_motor_2, OUTPUT);
    pinMode(en1, OUTPUT);
    pinMode(en2, OUTPUT);
} 
void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }

  if( val == 'F') // Forward
    {
      digitalWrite(left_motor_1, HIGH);
      digitalWrite(left_motor_2, LOW);
      digitalWrite(right_motor_1, HIGH);
      digitalWrite(right_motor_2, LOW);  
    }
  else if(val == 'B') // Backward
    {
      digitalWrite(left_motor_1, LOW);
      digitalWrite(left_motor_2, HIGH);
      digitalWrite(right_motor_1, LOW);
      digitalWrite(right_motor_2, HIGH); 
    }
  
    else if(val == 'L') //Left
    {
    digitalWrite(left_motor_1, LOW);
    digitalWrite(left_motor_2, LOW);
    digitalWrite(right_motor_1, HIGH);
    digitalWrite(right_motor_2, LOW);
    }
    else if(val == 'R') //Right
    {
    digitalWrite(left_motor_1, HIGH);
    digitalWrite(left_motor_2, LOW);
    digitalWrite(right_motor_1, LOW);
    digitalWrite(right_motor_2, LOW); 
    }
    
  else if(val == 'S') //Stop
    {
    digitalWrite(left_motor_1, LOW);
    digitalWrite(left_motor_2, LOW);
    digitalWrite(right_motor_1, LOW);
    digitalWrite(right_motor_2, LOW); 
    }

}
