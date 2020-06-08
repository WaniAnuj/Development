void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    char str[] = "1:80<1:60"; 
  
    // Returns first token 
    char* token = strtok(str, ":"); 
  
    // Keep printing tokens while one of the 
    // delimiters present in str[]. 
    while (token != NULL) { 
        Serial.println(token); 
        token = strtok(NULL, ":"); 
    } 
}

void loop() {

  for (int i =0; i< sizeof(token); i++){
          results[i]=atoi(token);
          Serial.println("array");
          Serial.println(results[i]);
          }
}
