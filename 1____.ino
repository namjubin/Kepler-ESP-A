#define buzzer 25
#define btn 26

bool state = false;
int cnt = 0;
int first[4] = {262, 294, 330, 349};
int second[25] = {330, 294, 261, 294, 330, 330, 330, 294, 294, 294, 330, 392,  392, 330, 294, 261, 294, 330, 330, 330, 294, 294, 330, 294, 261};

void setup() {
  pinMode(2, OUTPUT);
  pinMode(btn, INPUT);
  digitalWrite(2, HIGH);

  ledcSetup(0, 2000, 8);
  ledcAttachPin(buzzer, 0);
}

void loop() {
  if(cnt == 1){
    for(int i=0; i<4; i++){
      if(!digitalRead(btn)){
        break;
      }
      ledcWriteTone(0, first[i]);
      delay(500);
    }
    ledcWriteTone(0, 0);
    while(digitalRead(btn)){}
  }
  else if(cnt == 2){
    for(int i=0; i<25; i++){
      if(!digitalRead(btn)){
        break;
      }
      ledcWriteTone(0, second[i]);
      delay(500);
    }
    ledcWriteTone(0, 0);
    while(digitalRead(btn)){}
  }
  else{
    ledcWriteTone(0, 0);
    while(digitalRead(btn)){}
  }

  ledcWriteTone(0, 0);
  cnt = (cnt+1)%3;
  delay(500);
}
