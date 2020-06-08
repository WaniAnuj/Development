#include <Servo.h>
const byte numChars = 200;
char receivedChars[numChars];
int motor = 0;
char* commands[50];
char* token;
int pos;
int negpos;
int count = 0;
int i;

Servo claw;
Servo left;
Servo base;
Servo right;

boolean newData = false;

void setup() {
    Serial.begin(9600);
    claw.attach(6);
    left.attach(9);
    base.attach (10);
    right.attach(11);
    claw.write(0);
    left.write(0);
    base.write(0);
    right.write(0);
    Serial.println("<Arduino is ready>");
}
void(* resetFunc) (void)=0;
void loop() {
    recvWithStartEndMarkers();
    showNewData();
// prevcount, newcount
if(strcmp(commands[motor],"Base") == 0){
  pos = atoi(commands[motor+1]);
//  Serial.println(commands[motor]);
  Serial.println(pos);
  if(pos>0){
  for(i=0;i<pos;i++){
    base.write(i);
    delay(10);
  }
  }
  else if(pos<0){
    negpos=abs(pos);
  for(i=0;i<negpos;i++){
    base.write(negpos-i);
    delay(10);
  }
  }
  motor+=2;
  if(motor == count){
    motor=0;
  }
}
//else if(strcmp(commands[motor],"Left") == 0){
//    pos = atoi(commands[motor+1]);
//  Serial.println(commands[motor]);
//  Serial.println(pos);
//  motor+=2;
//  delay(1000);
//  Serial.println("**********");
//  if(motor == count){
//    motor=0;
//  }
//}
//else if(strcmp(commands[motor],"Right") == 0){
//   pos = atoi(commands[motor+1]);
//  Serial.println(commands[motor]);
//  Serial.println(pos);
//  motor+=2;
//  delay(1000);
//  Serial.println("**********");
//  if(motor == count){
//    motor=0;
//  }
//}
//else if(strcmp(commands[motor],"Claw") == 0){
//  pos = atoi(commands[motor+1]);
//  Serial.println(commands[motor]);
//  Serial.println(pos);
//  motor+=2;
//  delay(1000);
//  Serial.println("**********");
//  if(motor == count){
//    motor=0;
//  }
//}
else if(strcmp(commands[0],"Stop") == 0){
  resetFunc();
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
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();
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
//        Serial.println(commands[motor]);
        motor+=1;      
//        Serial.println(token);    
        token = strtok(NULL, ":");
        count++;
        
    }
   
   motor=0;
   newData = false;
    }
}
