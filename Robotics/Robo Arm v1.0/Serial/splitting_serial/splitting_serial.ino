#define INPUT_SIZE 30

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop(){
//  char input[INPUT_SIZE + 1];
  if(Serial.available()>0){
  char input[INPUT_SIZE + 1];
  byte size = Serial.readBytes(input, INPUT_SIZE);
  Serial.println(size);
  Serial.println("******");
  Serial.println(input);
  input[size] = 0;
  Serial.println(input);
//  for(int i=0;i<=2;i++){
  char* command = strtok(input, "&");
  Serial.println(command);
//  }
//  while(sizeof(command)!=0){
    char* separator = strchr(command, ":");
    Serial.println(separator);
//    if(separator!= 0){
//      *separator = 0;
      int servoId = atoi(command);
      Serial.println(servoId);
      ++separator;
      int pos = atoi(separator);
      Serial.println(pos);
//    }
    command = strtok(0,"&");
  }
}
