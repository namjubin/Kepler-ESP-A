#define hs 15
#define led 26
#define buzzer 32

void setup() {
  Serial.begin(115200);
  pinMode(hs, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if(digitalRead(hs)){
    Serial.println("detect!!");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else{
    Serial.println("not detect!!");
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
  delay(1000);
}
