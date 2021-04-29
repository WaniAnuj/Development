#include "WiFiEsp.h"


#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial Serial1(3, 4); // RX, TX
#endif

#define buzzer 2
char ssid[] = "Eduvance_Tenda";     // your network SSID (name)
char pass[] = "eduvance123";        // your network password
int status = WL_IDLE_STATUS;

int buzzerStatus = LOW;

WiFiEspServer server(80);
RingBuffer buf(8);

void setup()
{
  pinMode(buzzer, OUTPUT);  
  Serial.begin(9600);   
  Serial1.begin(19200);    
  WiFi.init(&Serial1);    

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");
  printWifiStatus();
  server.begin();
}


void loop()
{
  WiFiEspClient client = server.available();  

  if (client) {                             
    Serial.println("New client");            
    buf.init();                               
    while (client.connected()) {           
      if (client.available()) {              
        char c = client.read();              
        buf.push(c);                   
        
        if (buf.endsWith("\r\n\r\n")) {
          sendHttpResponse(client);
          break;
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (buf.endsWith("GET /H")) {
          Serial.println("Turn buzzer ON");
          buzzerStatus = HIGH;
          digitalWrite(buzzer, HIGH);   // turn the buzzer on (HIGH is the voltage level)
        }
        else if (buf.endsWith("GET /L")) {
          Serial.println("Turn buzzer OFF");
          buzzerStatus = LOW;
          digitalWrite(buzzer, LOW);    // turn the buzzer off by making the voltage LOW
        }
      }
    }
    
    // close the connection
    client.stop();
    Serial.println("Client disconnected");
  }
}


void sendHttpResponse(WiFiEspClient client)
{
  // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
  // and a content-type so the client knows what's coming, then a blank line:
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();

  client.print("The buzzer is ");
  client.print(buzzerStatus);
  client.println("<br>");
  client.println("<br>");
  
  client.println("Click <a href=\"/H\">here</a> turn the buzzer on<br>");
  client.println("Click <a href=\"/L\">here</a> turn the buzzer off<br>");
  
  client.println();
}

void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
