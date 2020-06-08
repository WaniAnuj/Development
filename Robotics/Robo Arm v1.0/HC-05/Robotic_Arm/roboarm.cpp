#include"roboarm.h"

roboarm::roboarm() {
  // Anything you need when instantiating your object goes here
}

// this is our 'begin' function
void roboarm::base_motor(int bp)
{
  Servo base_motor
  base_motor_pin = bp;
  base_motor.attach(base_motor_pin);
}

void roboarm::claw_motor(int cp)
{
  Servo claw_motor
  claw_motor_pin = cp;
  claw_motor.attach(claw_motor_pin);
}

void roboarm::left_motor(int lp)
{
  Servo left_motor
  left_motor_pin = lp;
  left_motor.attach(left_motor_pin);
}

void roboarm::right_motor(int rp)
{
  Servo right_motor;
  right_motor_pin = rp;
  right_motor.attach(right_motor_pin);
}

void roboarm::Serial_Monitor(int baudRate)
{
  Serial.begin(baudRate);
}

void roboarm::Bluetooth(int Baudrate)
{
  Bluetooth.begin(Baudrate);
}

void roboarm::BT_createlink(SoftwareSerial* bl)
{
  Serial1 = bl;
}

void roboarm::BT_start()
{
  if 
}
