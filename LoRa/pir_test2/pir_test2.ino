bool PIR_flag = false;
int pir_count;
void setup() {
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(2), pir_isr , FALLING);
  Serial.begin(115200);
  Serial.println("Starting...");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(PIR_flag == true)
  {
    pir_count++;
    PIR_flag = false;
  }
  Serial.print("count:");
  Serial.println(pir_count);
  delay(2000);
}

void pir_isr()
{
  PIR_flag = true;
}
