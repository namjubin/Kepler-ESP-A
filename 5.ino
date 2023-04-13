void setup() {
  Serial.begin(115200);
  pinMode(15, INPUT);
}

void loop() {
  if(digitalRead(15)){
    Serial.println("detect!!");
  }
  else{
    Serial.println("not detect!!");
  }
  
  delay(1000);
}
