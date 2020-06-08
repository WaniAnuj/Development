#ifndef ra_h
#define ra_h

#if (ARDUINO >=100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif
#include <SoftwareSerial.h>
#include <Servo.h>



class roboarm{
  public:
    // Constructor 
    roboarm();




  private:


};
extern roboarm arm;
#endif
