#include <MQ135.h>

#define mq135_pin A2
MQ135 gasSensor = MQ135(A1);// MQ135 digital pin connected to pin number A2
float ppm=0;
void setup() {
  Serial.begin(115200);
  float rzero = gasSensor.getRZero();
}

void loop() {
  // put your main code here, to run repeatedly:
  ppm = gasSensor.getPPM();
  Serial.print("MQ135: ");
  Serial.println(ppm);
  delay(2000);
}
