int pos1;
float pos2;
char i[50];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
    i = Serial.readString();
    pos1 = atoi(i);
    Serial.println(pos1);
    pos2=map(pos1,0,180,750,2250);
    Serial.println(pos2);
    delay(1000);
}
}
