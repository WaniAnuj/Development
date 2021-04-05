#include <DHT.h>
#define dht11_PIN 5                        // dht 11 pin connected to pin number 6

DHT dht(5, DHT11);

int G_humidity = 0;
int G_temp = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  delay(5000);
  int chk = dht.read(dht11_PIN);
  G_humidity = dht.readHumidity();
  G_temp = dht.readTemperature();
   if ( G_humidity == 0 || G_temp == 0 ) {
   }
   else{
  Serial.print("Humidity: ");
  Serial.println(G_humidity);
  Serial.print("Tempreture: ");
  Serial.println(G_temp);
  Serial.print("OG: ");
  Serial.println(chk);
   }
}
