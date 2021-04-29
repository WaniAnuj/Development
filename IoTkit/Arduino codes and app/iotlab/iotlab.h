#ifndef il_h
#define il_h

#if (ARDUINO >=100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif
#include <SoftwareSerial.h>
#include <ThingSpeak.h>
#include <WiFiEsp.h>



class iotlab{
  public:
    // Constructor 
    iotlab();

    // Methods
    void Serial_Monitor(int baudRate);
    void Wifi_begin(unsigned long baudrate);
    void Wifi_createlink(SoftwareSerial* ss);
    void Wifi_setup();
    void Wifi_start();
    String Wifi_name(String s);
    String Wifi_Password(String p);
    void Wifi_Connect();
    String Cloudkey(String w);
    String downloadkey(String r);
    unsigned long Cloud_channel_number(unsigned long ch);
    unsigned int Cloud_field_number(unsigned int f);
    void Cloud(int pin);
    void Download();
    void PrivateDownload();
    void Cloud_lightsensor(int pinno);
    float light_intensity(float b);
    void led_pin(int pinn);//////
    void led_on_off(int pinn);
    void lightsensor_pin(int pin);   ////////
    void Ultrasound_pin(int trigPin, int echoPin);////////
    void Cloud_Ultrasound();  
    void Buzzer_pin(int DPIN);//////////
    int distance(int a);/////////
    void Buzzout();
    void distance_check();/////////
    void light_buzz();
    void sunrise_alarm(int a);
    void distance_alarm();
    void burglar_alarm();
 
 private:
 SoftwareSerial *Serial1;
 WiFiEspClient  client;
 String ss;
 String ps;
 unsigned long chn;
 unsigned int fn;
 String wak;
 String rak;
 int th;
 float lth;
 int led;
 int trig;
 int echo;
 int buzz;
};

extern iotlab iot;
#endif
