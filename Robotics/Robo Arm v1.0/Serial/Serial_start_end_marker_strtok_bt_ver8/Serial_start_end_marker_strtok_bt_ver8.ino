#include <SoftwareSerial.h>
#include <Servo.h>

const byte numChars = 200;
char receivedChars[numChars];
int motor = 0;
char* commands[50];
char* token;
int pos;
int negpos;
int count = 0;
int loop_count = 0;
int i;
int reset = 12;

Servo claw;
Servo left;
Servo base;
Servo right;

boolean newData = false;

SoftwareSerial bt(2,4);

void setup() {
    Serial.begin(9600);
    bt.begin(9600);
    pinMode(reset, OUTPUT);
    digitalWrite(reset,HIGH);
    claw.attach(6);
    left.attach(9);
    base.attach (10);
    right.attach(11);
    claw.write(10);
    left.write(10);
    base.write(10);
    right.write(10);
    Serial.println("<Arduino is ready>");
}
//void(* resetFunc) (void)=0;
void loop() {
    recvWithStartEndMarkers();
    showNewData();
// prevcount, newcount
if(strcmp(commands[motor],"Base") == 0){
  pos = atoi(commands[motor+1]);
//  Serial.println(commands[motor]);
  Serial.println(pos);
  if(pos>0){
  for(i=11;i<pos;i++){
    base.write(i);
    delay(10);
  }
  }
  else if(pos<0){
    negpos=abs(pos);
  for(i=11;i<negpos;i++){
    base.write(negpos-i);
    delay(10);
  }
  }
  motor+=2;
  if(motor == count-2){
    loop_count+=1;
  }
}
else if(strcmp(commands[motor],"Left") == 0){
  pos = atoi(commands[motor+1]);
//  Serial.println(commands[motor]);
  Serial.println(pos);
  if(pos>0){
  for(i=11;i<pos;i++){
    left.write(i);
    delay(10);
  }
  }
  else if(pos<0){
    negpos=abs(pos);
  for(i=11;i<negpos;i++){
    left.write(negpos-i);
    delay(10);
  }
  }
  motor+=2;
  if(motor == count-2){
    loop_count+=1;
  }
}
else if(strcmp(commands[motor],"Right") == 0){
  pos = atoi(commands[motor+1]);
//  Serial.println(commands[motor]);
  Serial.println(pos);
  if(pos>0){
  for(i=11;i<pos;i++){
    right.write(i);
    delay(10);
  }
  }
  else if(pos<0){
    negpos=abs(pos);
  for(i=11;i<negpos;i++){
    right.write(negpos-i);
    delay(10);
  }
  }
  motor+=2;
  if(motor == count-2){
    loop_count+=1;
  }
}
else if(strcmp(commands[motor],"Claw") == 0){
  pos = atoi(commands[motor+1]);
//  Serial.println(commands[motor]);
  Serial.println(pos);
  if(pos>0){
  for(i=11;i<pos;i++){
    claw.write(i);
    delay(10);
  }
  }
  else if(pos<0){
    negpos=abs(pos);
  for(i=11;i<negpos;i++){
    claw.write(negpos-i);
    delay(10);
  }
  }
  motor+=2;
  if(motor == count-2){
    loop_count+=1;
  }
}
else if(strcmp(commands[0],"Automate") == 0){
  for(i=11;i<=100;i++){
    claw.write(i);
    delay(10);
  }
  for(i=11;i<=100;i++){
    claw.write(100-i);
    delay(10);
  }
  for(i=11;i<=75;i++){
    base.write(i);
    delay(10);
  }
  for(i=11;i<=75;i++){
    base.write(75-i);
    delay(10);
  }
  for(i=11;i<=80;i++){
    left.write(i);
    delay(10);
  }
  for(i=11;i<=80;i++){
    left.write(80-i);
    delay(10);
  }
  for(i=11;i<=80;i++){
    right.write(i);
    delay(10);
  }
  for(i=11;i<=80;i++){
    right.write(80-i);
    delay(10);
  }
  loop_count+=1;
}
else if(strcmp(commands[motor],"Repitition") == 0){
  pos = atoi(commands[motor+1]);
    if(pos == loop_count){
//    while(1){
//    recvWithStartEndMarkers();
//    showNewData();
//    if(strcmp(commands[0],"Stop") == 0){
//      resetFunc();
      digitalWrite(reset,LOW);
      delay(100);
//        }
//      }
    }
    motor=0;
}
else if(strcmp(commands[0],"Stop") == 0){
//      resetFunc();
//      delay(100);
        digitalWrite(reset,LOW);
        delay(100);
        }     
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
 
 // if (Serial.available() > 0) {
    while (bt.available() > 0 && newData == false) {
        rc = bt.read();
        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
     // Returns first token 
    token = strtok(receivedChars, ":"); 
    // Keep printing tokens while one of the 
    // delimiters present in str[]. 
    while (token != NULL) { 
        commands[motor]=token;
        Serial.println(commands[motor]);
        motor+=1;      
//        Serial.println(token);    
        token = strtok(NULL, ":");
        count++;
        
    }
   
   motor=0;
   newData = false;
    }
}
