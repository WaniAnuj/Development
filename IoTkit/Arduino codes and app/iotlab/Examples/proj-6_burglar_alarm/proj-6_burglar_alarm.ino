#include <iotlab.h>

SoftwareSerial serial(3, 4);

void setup(){
  io vct.Wifi_createlink(&serial);         // Assign Serial Communication pins to Wifi Module 
  iot.Wifi_start();  
  iot.Wifi_name("Eduvance_Tenda");      // Enter the Wifi router's User ID
  iot.Wifi_Password("eduvance123");     // Enter the Wifi router's Password
  iot.Cloudkey("7JFN99ST9V99MUVX");  // Enter the Write key from Thingspeak account
  iot.Cloud_channel_number(668447);            // Enter the Channel ID from Thingspeak account
  iot.Cloud_field_number(1);
  iot.Ultrasound_pin(5, 6);
  iot.Buzzer_pin(7);
  iot.led_pin(2);
  }

  void loop(){
  iot.distance(20);
  iot.burglar_alarm();
  }
