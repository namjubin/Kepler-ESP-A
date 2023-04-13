void setup() {
  Serial.begin(115200);
  pinMode(15, OUTPUT);
  pinMode(36, INPUT);
}

void loop() {
  int value = analogRead(36);
  Serial.println(value);
  
  if(value < 1000){
    digitalWrite(15, HIGH);
  }
  else{
    digitalWrite(15, LOW);
  }
}
