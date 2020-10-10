 #include <Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
myservo.attach(11);
for(int i=0;i<=180;i+=1){
  myservo.write(i);
  delay(20);
}
myservo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:

}
