#define tsr 4
#define tsl 27
#define r 12
#define g 13
#define b 14
#define buzzer 2

bool tsrv, tslv;
int melody[4] = {262, 294, 330, 349};

void setup() {
  Serial.begin(115200);
  
  pinMode(tsr, INPUT);
  pinMode(tsl, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(buzzer, HIGH);

  ledcAttachPin(25, 0);
}

void loop() {
  tsrv = analogRead(tsr) <= 15;
  tslv = analogRead(tsl) <= 10;

  if(tsrv and tslv){
    digitalWrite(r, HIGH);
    digitalWrite(b, HIGH);
    for(int i=0; i<4; i++){
      ledcWriteTone(0, melody[i]);
      delay(300);
    }
    ledcWriteTone(0, 0);
  }
  else if(tslv){
    digitalWrite(r, HIGH);
    digitalWrite(b, LOW);
    Serial.println("Red led on");
  }
  else if(tsrv){
    digitalWrite(r, LOW);
    digitalWrite(b, HIGH);
    Serial.println("Blue led on");
  }
  else{
    digitalWrite(r, LOW);
    digitalWrite(b, LOW);
  }
  delay(500);
}
