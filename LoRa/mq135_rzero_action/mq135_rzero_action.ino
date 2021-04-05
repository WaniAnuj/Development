/*
--Initialization settings

Before you start using it, you need to energized it and preheat it for 12-24 hours. 
After that, perform the following procedures in the environment of 
20 degree C/35% air temperature, and read the value of RZERO.

*/

#include "MQ135.h"
const int ANALOGPIN=0;
MQ135 gasSensor = MQ135(ANALOGPIN);
void setup(){
  Serial.begin(9600);      // sets the serial port to 9600
}
void loop(){
  float rzero = gasSensor.getRZero();
  Serial.println(rzero);
  delay(1000);
}
