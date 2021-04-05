/*Multiple LoRa Communication */

#include <SPI.h>
#include <RH_RF95.h>

RH_RF95 rf95;

void setup()
{
  Serial.begin(9600);
//  while (!Serial) ; // Wait for serial port to be available
  if (!rf95.init())
    Serial.println("init failed");
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
}

void loop()
{
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);
  if (rf95.waitAvailableTimeout(3000))
  {
    // Should be a reply message for us now
    if (rf95.recv(buf, &len))
    {
      int dataLength;
      String Request = (char*)buf;
      Serial.println(Request);
      if (Request == "C1") {
        Serial.print("Client 2 Got Request, Answering Server...");
//      uint8_t data[10] = "I'm Lora";
/*     int dataLength = data.length();dataLength++;
       uint8_t total[dataLength]; //variable for data to send
       data.toCharArray(total, dataLength); //change type data from string ke uint8_t
       Serial.println(data);*/
        int val = analogRead(A0);
        uint8_t data[10];
        String str;
        str = String(val);
        str.toCharArray(data,10);
        Serial.print("Sensor value node 2:");
        Serial.println(atoi(data));
        rf95.send(data, 10); //send data
        rf95.waitPacketSent();
      }
    }
  }
  else
  {
    Serial.println("No reply, is rf95_server running?");
  }
  delay(400);
}
