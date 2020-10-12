#ifndef roboarm_h
#define roboarm_h

#if (ARDUINO >=100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include <SoftwareSerial.h>
#include <ServoTimer2.h>

class roboarm{
  public:
  roboarm();

  void roboarm_setup();
  void recvWithStartEndMarkers();
  void showNewData();
  void JoystickMode();
  void resetFunc();
  void Sample();
  void Test();
  void stop_reps();
  void prog_mode();
  void prog_mode_base();
  void prog_mode_left();
  void prog_mode_right();
  void prog_mode_claw();
  void roboarm_functioning();

  private:
  int motor = 0;
  char* commands[50];
  char* token;
  int pos;
  int pos1;
  int pos2;
  int negpos;
  int negpos2;
  int count = 0;
  int loop_count = 0;
  int i;
  
  ServoTimer2 claw;
  ServoTimer2 left;
  ServoTimer2 base;
  ServoTimer2 right;
  
  int left_joy_ctrl = A0;    // analog pin used to connect the Joystick1
  int base_joy_ctrl = A3;    // analog pin used to connect the Joystick1
  int right_joy_ctrl = A2;   // analog pin used to connect the Joystick2
  int claw_joy_ctrl = A1;   // analog pin used to connect the Joystick2
  
  int left_joy_val;        // variable to read the value from the analog pin
  int base_joy_val;
  int right_joy_val;
  int claw_joy_val;
  
  int claw_pin = 6;   // variable to assign the servo to pin 6 
  int left_pin = 9;   // variable to assign the servo to pin 9 
  int base_pin = 10;  // variable to assign the servo to pin 10 
  int right_pin = 11;  // variable to assign the servo to pin 11
  
  int initial_positionL = 750;
  int initial_positionB = 750;
  int initial_positionR = 750;
  int initial_positionC = 750;
  
  boolean newData = false;
  
};

extern roboarm RoboArm;
#endif
