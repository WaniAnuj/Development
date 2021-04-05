/////////////////////////////////////////////////////////
const int ledPin           = 13;
const int buttonPin        =  6;

bool      buttonState      = false;
bool      lastButtonState  = false;
uint32_t  changedTime;
bool      changing         = false;
const uint32_t BOUNCE_TIME = 50000UL;

char      response[20];
uint8_t   length;

//////////////////////////////////////////////////////////

#include <NeoSWSerial.h>

#define PHrxPin 2
#define PHtxPin 3

#define ECrxPin 4
#define ECtxPin 5

NeoSWSerial phSerial (PHrxPin, PHtxPin);
NeoSWSerial ecSerial (ECrxPin, ECtxPin);

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
  while (!Serial)
    ;

  ecSerial.begin(9600);
  phSerial.begin(9600); // begin also calls listen
}

void loop()
{
  buttonLoop();
  phLoop();
  ecLoop();
}

void buttonLoop()
{
  // Watch for (and debounce) button presses
  if (!changing) {

    // See if it's changing now
    buttonState = digitalRead(buttonPin);

    if (lastButtonState != buttonState) {
      lastButtonState  = buttonState;
      changedTime      = millis();       // save when it changed
      changing         = true;

      digitalWrite( ledPin, buttonState ); // set the LED

      // Do something when the button changed
      if (buttonState) {
        phSerial.print( F("R\r") ); // request a reading
        //phSerial.print( 1 ); ???
      } else {
        //phSerial.print( 2 ); ???
      }
    }

  } else { // changing

    // It might be bouncing for a while, has it been long enough?
    if (micros() - changedTime > BOUNCE_TIME) {
      changing = false; // reset to catch when it changes again
    }
  }

} // buttonLoop


void phLoop()
{
  while (phSerial.available() > 0) {
    char c = phSerial.read();

    if (c == '\r') {
      // That's the end of the sensor response
      response[ length ] = '\0'; // NUL-terminate the C string (not the String class)

      Serial.print( F("Data From pH Sensor:") ); // F macro saves RAM
      Serial.println( response ); // just the characters, really

      //  Is the response a reading value or a *XX response code?
      if (isdigit( response[0] )) {

        // Parse the response into a float value
        float phValue = strtod( response, NULL );

        Serial.print( F("phValue = ") );
        Serial.println( phValue );
       
        // ... do something with ph Value?

      } else if (response[0] == '*') {
        // Handle various response codes here...
      }

      length = 0;        // empty the response string...
      ecSerial.listen(); // ... and switch to the EC sensor for a while
      ecSerial.print( F("R\r") ); // ask for an EC reading

    } else {
      //  Save characters until the CR comes in (make sure there's room)
      if (length < sizeof(response)-1)
        response[ length++ ] = c;
    }
  }

} // phLoop


void ecLoop()
{
  while (ecSerial.available() > 0) {
    char c = ecSerial.read();

    if (c == '\r') {
      // That's the end of the sensor response
      response[ length ] = '\0';

      Serial.print( F("Data From EC Sensor:") );
      Serial.println( response );

      //  Is the response a reading value or a *XX response code?
      if (isdigit( response[0] )) {

        // Parse the response into a float value
        float ecValue = strtod( response, NULL );

        Serial.print( F("EC value = ") );
        Serial.println( ecValue );
     
        // ... do something with EC Value?

      } else if (response[0] == '*') {
        // Handle various response codes here...
      }

      length = 0;        // empty the response string...
      phSerial.listen(); // ... and switch back to the ph sensor

    } else {
      //  Save characters until the CR comes in (make sure there's room)
      if (length < sizeof(response)-1)
        response[ length++ ] = c;
    }
  }

} // ecLoop
