const byte numChars = 100;
char receivedChars[numChars];
int motor = 0;
char* results[100];
char* token;
int count1=0;
int count2=0;
char* values[100];
int prevcount;

boolean newData = false;
boolean right = false;

void setup() {
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
}

void loop() {
    recvWithStartEndMarkers();
    showNewData();
//    if(right==true){
//    for(int i=0;i<count2;i++)
//    {
//       Serial.println(results[i]);
//       Serial.println("----------");
//    }
//  }
//  Serial.println(results[0]);
  if(results[0] == 98){
    Serial.println("found it");
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
    count1++;
    Serial.println("count1");
    Serial.println(count1);
    // Keep printing tokens while one of the 
    // delimiters present in str[]. 
    while (token != NULL) { 
        results[motor]=token;
        Serial.println(results[motor]);
        motor+=1;       
//        Serial.println(token);    
        token = strtok(NULL, ":");
        count2++; 
    }
//    if(results[0] >0 && results[1] >0 && prevcount ==  count2-2){
//      Serial.println("if count2");
//          Serial.println(count2);
//          values[count2-2]=results[0];
//          values[count2-1]=results[1];
//          Serial.println("********");
//          Serial.println(values[count2-2]);
//          Serial.println(values[count2-1]); 
//          prevcount+=2;
//        }
   
   newData = false;
    }
    right= true;
}
