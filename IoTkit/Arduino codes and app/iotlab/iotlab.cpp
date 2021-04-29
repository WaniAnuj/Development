#include "iotlab.h"


#define MAX_ADC_READING 1023
#define ADC_REF_VOLTAGE 5
#define REF_RESISTANCE 5000  // 5kohm reference resistance
#define LUX_CALC_SCALAR 12518931
#define LUX_CALC_EXPONENT -1.405 

iotlab::iotlab() {
  // Anything you need when instantiating your object goes here
}


// this is our 'begin' function
void iotlab::Serial_Monitor(int baudRate) {
  Serial.begin(baudRate);
  }

  
void iotlab::Wifi_createlink(SoftwareSerial* ss){
  Serial1 = ss;
}


void iotlab::Wifi_begin(unsigned long baudrate){
  long rates[6] = {115200,74880,57600,38400,19200,9600};

  Serial.print("Setting ESP8266 baudrate to ");
  Serial.print(baudrate);
  Serial.println("...");

  for(int i = 0; i < 6; i++){
    Serial1->begin(rates[i]);
    delay(100);
    Serial1->print("AT+UART_DEF=");
    Serial1->print(baudrate);
    Serial1->print(",8,1,0,0\r\n");
    delay(100);  
  }
    
  Serial1->begin(baudrate);
}


void iotlab::Wifi_setup(){
    while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo native USB port only
  }
  Serial.print("Searching for ESP8266..."); 
  // initialize ESP module
  WiFi.init(Serial1);
  delay(3000);
  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }
  Serial.println("found it");
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void iotlab::Wifi_start()
{
  Serial_Monitor(9600);
  Wifi_begin(19200);
  Wifi_setup();
}


String iotlab::Wifi_name(String s)
{
  ss = s;
  return s;
}


String iotlab::Wifi_Password(String p)
{
  ps = p;
  return p;  
}


void iotlab::Wifi_Connect(){
  char c[20];
  char d[20];
  Wifi_name(ss).toCharArray(c,20);
  Wifi_Password(ps).toCharArray(d,20);
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to name: ");
    Serial.println(c);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(c, d);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
//      Seriaint(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
}


String iotlab::Cloudkey(String w)
{
  wak = w;
  return w;  
}


String iotlab::downloadkey(String r)
{
  rak =r;
  return r;  
}


unsigned long iotlab::Cloud_channel_number(unsigned long ch)
{
  chn = ch;
  return ch;
}


unsigned int iotlab::Cloud_field_number(unsigned int f)
{
  fn = f;
  return f;
}


void iotlab::Cloud(int pin)
{
  Wifi_Connect();
  char e[20];
  Cloudkey(wak).toCharArray(e,20);
  int adc_val = analogRead(pin);
  Serial.println("Uploading values to the Cloud");
  int x = ThingSpeak.writeField(Cloud_channel_number(chn), Cloud_field_number(fn), adc_val, e);
  if(x == 200){
    Serial.print("The Analog Sensor value is ");
    Serial.println(adc_val);
    Serial.println("Channel Update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  
  delay(16000); // Wait 20 seconds to Cloud the channel again
}


void iotlab::Download()
{
  Wifi_Connect();
  int statusCode = 0;
  Serial.println("Downloading values from the Cloud");
   // Read in Cloud_field_number 4 of the public channel recording the temperature
  float obtained_value = ThingSpeak.readFloatField(Cloud_channel_number(chn), Cloud_field_number(fn));  

  // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200){
    Serial.println("The obtained value is: " + String(obtained_value));
  }
  else{
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }
  
  delay(16000); // No need to read the temperature too often.
}

void iotlab::PrivateDownload()
{
  Wifi_Connect();
  char f[20];
  iot.downloadkey(rak).toCharArray(f,20);
  int statusCode = 0;
  long value = ThingSpeak.readLongField(Cloud_channel_number(chn), Cloud_field_number(fn), f);  

   // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200){
    Serial.println("The obtained value is: " + String(value));
  }
  else{
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }
  
  delay(16000); // No need to read the counter too often.
}

void iotlab::Cloud_lightsensor(int pinno)
{
  Wifi_Connect();
  char g[20];
  Cloudkey(wak).toCharArray(g,20);
  int sensorValue = analogRead(pinno);
  float resistorVoltage = (float)sensorValue / MAX_ADC_READING * ADC_REF_VOLTAGE;
  float ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
  float ldrResistance = ldrVoltage/resistorVoltage * REF_RESISTANCE;
  float ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);
  Serial.println("Uploading to the Cloud");
  int x = ThingSpeak.writeField(Cloud_channel_number(chn), Cloud_field_number(fn), ldrLux, g);
  if(x == 200){
    Serial.print("The Light Sensor value is ");
    Serial.print(ldrLux);
    Serial.println("lumens/sq.m");
    Serial.println("Channel Update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  
  delay(16000); // Wait 20 seconds to Cloud the channel again
}

float iotlab::light_intensity(float b)
{
  lth = b;
  return b;
}

void iotlab::led_pin(int pinn)
{
  led = pinn;
  pinMode(pinn, OUTPUT);
}

void iotlab::led_on_off(int pinn)
{
  int statusCode = 0;
//  Serial.println("Downloading from the Cloud");
  // Read in Cloud_field_number 4 of the public channel recording the temperature
  float rcvd_value = ThingSpeak.readFloatField(Cloud_channel_number(chn), Cloud_field_number(fn));  

  // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200){
    Serial.println("The Recieved value is: " + String(rcvd_value));
  }
  else{
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }

  if(rcvd_value <= light_intensity(lth)){
    digitalWrite(pinn,HIGH);
    Serial.println("The Light led Will be Switched ON");
  }
  else{
    digitalWrite(pinn,LOW);
    Serial.println("The Light led is OFF");
  }
  delay(16000); // No need to read the temperature too often.
  
}

void iotlab::lightsensor_pin(int pin)
{
  Cloud_lightsensor(pin);
  led_on_off(led);
}

void iotlab::Ultrasound_pin(int trigPin, int echoPin)
{
  trig = trigPin;
  echo = echoPin;
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void iotlab::Cloud_Ultrasound()
{
  Wifi_Connect();
  char h[20];
  Cloudkey(wak).toCharArray(h,20);
  // Clears the trigPin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echo, HIGH);
  // Calculating the distance
  int distance= duration*0.034/2;
  Serial.println("Uploading the distance between object and sensor to the Cloud");
  // Write to ThingSpeak. There are up to 8 Cloud_field_numbers in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to Cloud_field_number 1.
  int x = ThingSpeak.writeField(Cloud_channel_number(chn), Cloud_field_number(fn), distance, h);
  if(x == 200){
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("Channel Update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(16000); // Wait 20 seconds to Cloud the channel again
}

void iotlab::Buzzer_pin(int DPIN)
{
    buzz = DPIN;
    pinMode(DPIN, OUTPUT);
}

int iotlab::distance(int a)
{
  th = a;
  return a;
}

void iotlab::Buzzout()
{
  Serial.println("Downloading from the Cloud"); 
  int statusCode = 0; 
    // Read in Cloud_field_number 4 of the public channel recording the temperature
  float rcvd_value = ThingSpeak.readFloatField(Cloud_channel_number(chn), Cloud_field_number(fn));  

  // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200){
    Serial.println("The Recieved value is: " + String(rcvd_value));
  }
  else{
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }

  if(rcvd_value >= distance(th)){
    Serial.println("The Buzzer will beep 3 times");
    for(int i=0;i<3;i++){
    digitalWrite(buzz,HIGH);
    delay(500);
    digitalWrite(buzz,LOW);
    delay(500);  
    }   
  }
  else if(rcvd_value < distance(th)){
    digitalWrite(buzz,LOW);
    Serial.println("The Buzzer is OFF");
  }
  delay(16000); // No need to read the temperature too often.
}

void iotlab::distance_check()
{
  Cloud_Ultrasound();
  Buzzout();
}

void iotlab::light_buzz()
{
  int statusCode = 0;
  // Read in Cloud_field_number 4 of the public channel recording the temperature
  float rcvd_value = ThingSpeak.readFloatField(Cloud_channel_number(chn), Cloud_field_number(fn));  
  Serial.println("Downloading");
  // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200){
    Serial.println("The Recieved value is: " + String(rcvd_value));
  }
  else{
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }

  if(rcvd_value >= light_intensity(lth)){
    Serial.println("The Buzzer will beep 3 times");
    for(int i=0;i<3;i++){
    digitalWrite(buzz,HIGH);
    delay(500);
    digitalWrite(buzz,LOW);
    delay(500);  
    }   
  }
  else if(rcvd_value < light_intensity(lth)){
    digitalWrite(buzz,LOW);
    Serial.println("The Buzzer is OFF");
  }
  delay(16000); // No need to read the temperature too often.
}

void iotlab::sunrise_alarm(int a)
{
  Cloud_lightsensor(a);
  light_buzz();
}

void iotlab::distance_alarm()
{
  Serial.println("Downloading from the Cloud"); 
  int statusCode = 0; 
    // Read in Cloud_field_number 4 of the public channel recording the temperature
  float rcvd_value = ThingSpeak.readFloatField(Cloud_channel_number(chn), Cloud_field_number(fn));  

  // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200){
    Serial.println("The Recieved value is: " + String(rcvd_value));
  }
  else{
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }

  if(rcvd_value < distance(th)){
    Serial.println("Caution!!! Intruder detected");
    for(int i=0;i<3;i++){
    digitalWrite(buzz,HIGH);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(buzz,LOW);
    digitalWrite(led,LOW);
    delay(500);  
    }   
  }
  else if(rcvd_value >= distance(th)){
    digitalWrite(buzz,LOW);
    digitalWrite(led,LOW);
    Serial.println("Everything is fine");
  }
  delay(16000); // No need to read the temperature too often.
}

void iotlab::burglar_alarm()
{
  Cloud_Ultrasound();
  distance_alarm();
}

iotlab iot;
