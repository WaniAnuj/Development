#include<SoftwareSerial.h>
#include<Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

SoftwareSerial bt(2, 3);
int pos;

void setup() 
{  
  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
  myservo4.attach(12);
  
  bt.begin(9600);
  Serial.begin(9600);
}

void loop()
{
 if (bt.available()>0)
    {
  Serial.println("Enter which motor to move:");
  val = bt.read();
  Serial.print(val);
    if (val=="Base")
       {
        Serial.println("Enter the angle:")
        pos1 = bt.read();
        Serial.print(pos1);
        pos1 = map(pos1, 0, 180, 180, 0);
        myservo1.write(pos1);
       }
      else if (val=="Claw")
              {
                Serial.println("Enter the angle:")
                pos2 = bt.read();
                Serial.print(pos2);
                pos2 = map(pos2, 0, 180, 180, 0);
                myservo2.write(pos2);
              }
           else if (val=="Left")
              {
                Serial.println("Enter the angle:")
                pos3 = bt.read();
                Serial.print(pos3);
                pos3 = map(pos3, 0, 180, 180, 0);
                myservo2.write(pos3);
              }
              else if (val=="Right")
                  {
                    Serial.println("Enter the angle:")
                    pos4 = bt.read();
                    Serial.print(pos4);
                    pos4 = map(pos4, 0, 180, 180, 0);
                    myservo2.write(pos4);
                  }
     }
}
