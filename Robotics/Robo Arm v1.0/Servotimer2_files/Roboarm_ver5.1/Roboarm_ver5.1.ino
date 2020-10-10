#include <SoftwareSerial.h>
#include <ServoTimer2.h>

const byte numChars = 200;
char receivedChars[numChars];
int motor = 0;
char* commands[50];
char* token;
int pos;
int pos1;
int pos2;
int negpos;
int negpos2;
int count = 0;
int loop_count = 0;
int i;

ServoTimer2 claw;
ServoTimer2 left;
ServoTimer2 base;
ServoTimer2 right;

int left_joy_ctrl = A0;    // analog pin used to connect the Joystick1
int base_joy_ctrl = A3;    // analog pin used to connect the Joystick1
int right_joy_ctrl = A2;   // analog pin used to connect the Joystick2
int claw_joy_ctrl = A1;   // analog pin used to connect the Joystick2

int left_joy_val;        // variable to read the value from the analog pin
int base_joy_val;
int right_joy_val;
int claw_joy_val;

int claw_pin = 6;   // variable to assign the servo to pin 6 
int left_pin = 9;   // variable to assign the servo to pin 9 
int base_pin = 10;  // variable to assign the servo to pin 10 
int right_pin = 11;  // variable to assign the servo to pin 11

int initial_positionL = 750;
int initial_positionB = 750;
int initial_positionR = 750;
int initial_positionC = 750;

boolean newData = false;

SoftwareSerial bt(2,4);

void setup() {
    Serial.begin(9600);
    bt.begin(9600);
    
    claw.attach(6);
    left.attach(9);
    base.attach (10);
    right.attach(11);
    
    claw.write(750);
    left.write(750);
    base.write(750);
    right.write(750);
    
    Serial.println("<Arduino is ready>");
}
void(* resetFunc) (void)=0;
void loop() {
    recvWithStartEndMarkers();
    showNewData();
// prevcount, newcount
if(strcmp(commands[motor],"Base") == 0){
  pos1 = atoi(commands[motor+1]);
//  Serial.println(commands[motor]);
//  Serial.println("***************");
  if(pos1>0){
//  Serial.println(pos1);
  pos2 = map(pos1,0,180,750,2250);
//  Serial.println(pos2);
  for(i=750;i<pos2;i+=8){
    base.write(i);
    delay(10);
  }
  }
  else if(pos1<0){
    negpos=abs(pos1);
//    Serial.println(negpos);
    negpos2 = map(negpos,0,180,750,2250);
//    Serial.println(negpos2);
  for(i=750;i<(negpos2);i+=8){
    base.write(negpos2+750-i);
    delay(10);
  }
  }
  motor+=2;
  if(motor == count-2){
    loop_count+=1;
  }
}
else if(strcmp(commands[motor],"Left") == 0){
  pos1 = atoi(commands[motor+1]);
  Serial.println(commands[motor]);
  Serial.println("***************");
  if(pos1>0){
  Serial.println(pos1);
  pos2 = map(pos1,0,180,750,2250);
  Serial.println(pos2);
  for(i=750;i<pos2;i+=8){
    left.write(i);
    delay(10);
  }
  }
  else if(pos1<0){
    negpos=abs(pos1);
    Serial.println(negpos);
    negpos2 = map(negpos,0,180,750,2250);
    Serial.println(negpos2);
  for(i=750;i<(negpos2);i+=8){
    left.write(negpos2+750-i);
    delay(10);
  }
  }
  motor+=2;
  if(motor == count-2){
    loop_count+=1;
  }
}
else if(strcmp(commands[motor],"Right") == 0){
  pos1 = atoi(commands[motor+1]);
  Serial.println(commands[motor]);
  Serial.println("***************");
  if(pos1>0){
  Serial.println(pos1);
  pos2 = map(pos1,0,180,750,2250);
  Serial.println(pos2);
  for(i=750;i<pos2;i+=8){
    right.write(i);
    delay(10);
  }
  }
  else if(pos1<0){
    negpos=abs(pos1);
    Serial.println(negpos);
    negpos2 = map(negpos,0,180,750,2250);
    Serial.println(negpos2);
  for(i=750;i<(negpos2);i+=8){
    right.write(negpos2+750-i);
    delay(10);
  }
  }
  motor+=2;
  if(motor == count-2){
    loop_count+=1;
  }
}
else if(strcmp(commands[motor],"Claw") == 0){
  pos1 = atoi(commands[motor+1]);
  Serial.println(commands[motor]);
  Serial.println("***************");
  if(pos1>0){
  Serial.println(pos1);
  pos2 = map(pos1,0,180,750,2250);
  Serial.println(pos2);
  for(i=750;i<pos2;i+=8){
    claw.write(i);
    delay(10);
  }
  }
  else if(pos1<0){
    negpos=abs(pos1);
    Serial.println(negpos);
    negpos2 = map(negpos,0,180,750,2250);
    Serial.println(negpos2);
  for(i=750;i<(negpos2);i+=8){
    claw.write(negpos2+750-i);
    delay(10);
  }
  }
  motor+=2;
  if(motor == count-2){
    loop_count+=1;
  }
}
else if(strcmp(commands[0],"Automate") == 0){
  for(i=750;i<=1583;i+=8){
    right.write(i);
    claw.write(i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    claw.write(2333-i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    right.write(2333-i);
    left.write(i);
    delay(10);
  }
  for(i=750;i<=1375;i+=8){
    base.write(i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    right.write(i);
    left.write(2333-i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    claw.write(i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    claw.write(2333-i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    right.write(2333-i);
    delay(10);
  }
  for(i=750;i<=1375;i+=8){
    base.write(2125-i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    right.write(i);
    delay(10); 
  }
  for(i=750;i<=1583;i+=8){
    claw.write(i); 
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    right.write(2333-i);
    claw.write(2333-i);
    delay(10);
  }
  delay(2000);
  loop_count+=1;
}
else if(strcmp(commands[motor],"Test") == 0){
  for(i=750;i<=1583;i+=8){
    claw.write(i);
    delay(10);
  }
  for(i=750;i<=1583;i+=8){
    claw.write(2333-i);  //1583+750=2333-->100deg+0deg
    delay(10);
  }
  for(i=750;i<=1375;i+=8){
    base.write(i);
    delay(10);
  }
  for(i=750;i<=1375;i+=8){
    base.write(2125-i);  //1375+750=2125-->75deg+0deg
    delay(10);
  }
  for(i=750;i<=1416;i+=8){
    left.write(i);
    delay(10);
  }
  for(i=750;i<=1416;i+=8){
    left.write(2166-i);  //1416+750=2166-->80deg+0deg
    delay(10);
  }
  for(i=750;i<=1416;i+=8){
    right.write(i);
    delay(10);
  }
  for(i=750;i<=1416;i+=8){
    right.write(2166-i);  //1416+750=2166-->80deg+0deg
    delay(10);
  }
  loop_count+=1;
  }
else if(strcmp(commands[motor],"Repitition") == 0){
  pos = atoi(commands[motor+1]);
  Serial.println(pos);
  Serial.println(loop_count);
    if(pos == loop_count){
      resetFunc(); 
      delay(100);
    }
    motor=0;
}
else if(strcmp(commands[motor],"Joystick") == 0){
  JoystickMode();
}
else if(strcmp(commands[0],"Program") == 0){
      resetFunc();
      delay(100);
        } 
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

void JoystickMode(){
  left_joy_val = analogRead (left_joy_ctrl);  // reads the value of the joystick1 (value between 0 and 1023)
  base_joy_val = analogRead (base_joy_ctrl);
  
  right_joy_val = analogRead (right_joy_ctrl);   // reads the value of the joystick2 (value between 0 and 1023)
  claw_joy_val = analogRead (claw_joy_ctrl) ;
  //Serial.println(claw_joy_val);
  
  // if less than 300 or more than 700 the servo should move otherwise nothing
  // Controlling the claw and left motor using 1st joystick
  
  if (claw_joy_val < 350){
  if (initial_positionC < 755)
  { }
  else
  { initial_positionC = initial_positionC - 16;
  claw.write (initial_positionC);
  delay (10) ;
  }
  }
  if (claw_joy_val > 650)
  {
  if (initial_positionC > 2250)
  { }
  else
  {
  initial_positionC = initial_positionC + 16 ;
  claw.write ( initial_positionC );
  delay (10) ;
  }
  }

  if (left_joy_val < 350)
  {
  if (initial_positionL > 2250)
  { }
  else
  {
    initial_positionL = initial_positionL + 16;
    left.write (initial_positionL);
    delay (10);
  }
  }
  if (left_joy_val > 650)
  {
  if (initial_positionL < 755)
  { }
  else
  {
  initial_positionL = initial_positionL - 16;
  left.write (initial_positionL) ;
  delay (10) ;
  }
  }
  
  // if less than 300 or more than 700 the servo should move otherwise nothing
  // Controlling the base and right motor using 2nd joystick

  if (base_joy_val > 650){
  if (initial_positionB > 2250)
  { }
  else
  { initial_positionB = initial_positionB + 16;
  base.write (initial_positionB);
  delay (10) ;
  }
  }
  if (base_joy_val < 350)
  {
  if (initial_positionB < 755)
  { }
  else
  {
  initial_positionB = initial_positionB - 16;
  base.write (initial_positionB) ;
  delay (10) ;
  }
  }
  
  if (right_joy_val > 650)
  {
  if (initial_positionR < 755)
  { }
  else
  {
    initial_positionR = initial_positionR - 16;
    right.write (initial_positionR);
    delay (10) ;
  }
  }
  if (right_joy_val < 350)
  {
  if (initial_positionR > 2250)
  {}
  else
  {
  initial_positionR = initial_positionR + 16;
  right.write (initial_positionR) ;
  delay (10) ;
  }
  }
}
