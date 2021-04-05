#include<SoftwareSerial.h>

SoftwareSerial bt(2,4);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
bt.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
bt.println("AT");
String c = bt.readString();
Serial.println("Response: "+c);
}
