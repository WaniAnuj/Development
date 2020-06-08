#include<SoftwareSerial.h>
#include <Servo.h>

Servo three;
Servo one;
Servo two;
Servo four;

SoftwareSerial bt(2, 3);
int pos;

void setup() 
{  
  three.attach(10);//base
  one.attach(6); //claw
  two.attach(9);//left 
  four.attach(11); //right

  one.write(0);
  two.write(0);
  three.write(0);
  four.write(0);
  
  bt.begin(9600);
  Serial.begin(9600);
}

void loop()
{
 if (bt.available()>0)
    {
  Serial.println("Enter which motor to move:");
  String  val = bt.readString();
  Serial.print(val);
    if (val=="Base")
       {
        bt.write("Enter the angle:");
        Serial.println("Enter the angle:");
         if (bt.available()>0){
        int pos1 = bt.read();
        Serial.print(pos1);
        pos1 = map(pos1, 0, 180, 180, 0);
        three.write(pos1);
       }
       }
      else if (val=="Claw")
              {
                Serial.println("Enter the angle:");
                bt.write("Enter the angle:");
                int pos2 = bt.read();
                Serial.print(pos2);
                pos2 = map(pos2, 0, 180, 180, 0);
                one.write(pos2);
              }
           else if (val=="Left")
              {
                Serial.println("Enter the angle:");
                bt.write("Enter the angle:");
                int pos3 = bt.read();
                Serial.print(pos3);
                pos3 = map(pos3, 0, 180, 180, 0);
                two.write(pos3);
              }
              else if (val=="Right")
                  {
                    Serial.println("Enter the angle:");
                    bt.write("Enter the angle:");
                    int pos4 = bt.read();
                    Serial.print(pos4);
                    pos4 = map(pos4, 0, 180, 180, 0);
                    four.write(pos4);
                  }
     }
}
