/*Multiple node LoRa Communication*/
#include <Console.h>
#include <SPI.h>
#include <RH_RF95.h>

RH_RF95 rf95;
int led = 13;
unsigned long int millisBefore;

int turn = 1;
boolean statusRepeater = 0;
String myWriteAPIString = "QLE7OBH93FI1AYOX";
String datastring = "";
int senval;
bool pcktrecvstatus;

void setup()
{
  pinMode(led, OUTPUT);
  Bridge.begin(115200);
  Console.begin();
//  Console.begin(9600);
  while (!Console) ; // Wait for Console port to be available
  if (!rf95.init())
    Console.println("init failed");
    // Setup ISM frequency
  rf95.setFrequency(865.0);
  // Setup Power,dBm
  rf95.setTxPower(13);
  
  // Setup Spreading Factor (6 ~ 12)
  rf95.setSpreadingFactor(7);
  
  // Setup BandWidth, option: 7800,10400,15600,20800,31200,41700,62500,125000,250000,500000
  rf95.setSignalBandwidth(125000);
  
  // Setup Coding Rate:5(4/5),6(4/6),7(4/7),8(4/8) 
  rf95.setCodingRate4(5);

  rf95.setSyncWord(0x34);
  Console.println("Starting...");
  millisBefore = millis();
}

void loop()
{
  if (statusRepeater == 0) {
//    Console.println("Status 0");
    if (millis() - millisBefore < 1000) { 
//      Console.println("millis true");
      if (turn == 1) {
//        Console.println("turn1");
        Console.println("Send Request 1");
        SendRequest("C1"); 
        waitForAnswer();
        if(pcktrecvstatus == true)
        {
          datastring = "field1=";
          datastring +=senval;
          uploadData();
          datastring="";
          delay(15000);
        }
        millisBefore = millis();
        pcktrecvstatus = false;
        turn = 2;
      }
    } else if ((millis() - millisBefore > 1000) && (millis() - millisBefore < 2000)) { 
      if (turn == 2) {
        Console.println("Send Request 2");
        SendRequest("C2");
        waitForAnswer();
        if(pcktrecvstatus == true)
        {
          datastring = "field2=";
          datastring +=senval;
          uploadData();
          datastring="";
          delay(13000);
        }
        turn = 3;
        pcktrecvstatus = false;
        millisBefore = millis();
      }
    } else if (millis() - millisBefore > 6000) {
      if (turn == 3) {
        Console.println("Send Request 3");
        SendRequest("C3");
        waitForAnswer();
        if(pcktrecvstatus == true)
        {
          datastring = "field3=";
          datastring +=senval;
          uploadData();
          datastring="";
          delay(16000);
        }
        millisBefore = millis();
        pcktrecvstatus = false;
        turn = 1;
      }
    }
  }
}

void waitForAnswer() {
  // Now wait for a reply 
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);
//  pcktrecvstatus = false;
  if (rf95.waitAvailableTimeout(500))
  {
    if (rf95.recv(buf, &len))
    {
      Console.print("Received at Server: ");
      Console.println((char*)buf);
      senval = atoi(buf);
      pcktrecvstatus = true;
    }
    else
    {
      Console.println("recv failed");
      pcktrecvstatus = false;
    }
  }
}

void SendRequest(String request) {
  String dataTotal = request;
  int dataLength = dataTotal.length(); dataLength ++;
  uint8_t total[dataLength];
  dataTotal.toCharArray(total, dataLength);
  rf95.send(total, dataLength);
  rf95.waitPacketSent();
}

void uploadData() {//Upload Data to ThingSpeak
  // form the string for the API header parameter:


  // form the string for the URL parameter, be careful about the required "
  String upload_url = "https://api.thingspeak.com/update?api_key=";
  upload_url += myWriteAPIString;
  upload_url += "&";
  upload_url += datastring;

  Console.println("Call Linux Command to Send Data");
  Process p;    // Create a process and call it "p", this process will execute a Linux curl command
  p.begin("curl");
  p.addParameter("-k");
  p.addParameter(upload_url);
  p.run();    // Run the process and wait for its termination

  Console.print("Feedback from Linux: ");
  // If there's output from Linux,
  // send it out the Console:
  while (p.available()>0) 
  {
    char c = p.read();
    Console.write(c);
  }
  Console.println("");
  Console.println("Call Finished");
  Console.println("####################################");
  Console.println("");
}
