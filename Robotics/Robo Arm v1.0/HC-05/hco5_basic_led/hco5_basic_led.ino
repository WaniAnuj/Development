#include<SoftwareSerial.h>

/* Create object named bt of the class SoftwareSerial */ 
SoftwareSerial bt(2,3); /* (Rx,Tx) */  

void setup() {
  bt.begin(9600); /* Define baud rate for software serial communication */
  Serial.begin(9600); /* Define baud rate for serial communication */
  pinMode(13,OUTPUT);
}

void loop() {
    char x;
//    Serial.println("Welcome to HC-05");
    if (bt.available()) /* If data is available on serial port */
    {
     Serial.println("Let's get started"); 
//     Serial.write(bt.read());
     x=bt.read(); /* Print character received on to the serial monitor */
     if(x=='a')
     {
      digitalWrite(13,HIGH);
      Serial.println("LED ON");
     }
     else if(x=='b')
     {
      digitalWrite(13,LOW);
      Serial.println("LED OFF");
     }
    }
}
