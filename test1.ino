#define buzzer 2
#define btn 26

bool state = false;
int channel = 0;
int cnt = 0;

int first[4] = {262, 294, 330, 349};
int second[25] = {330, 294, 261, 294, 330, 330, 330, 294, 294, 294, 330, 392,392, 330, 294, 261, 294, 330, 330, 330, 294, 294, 330, 294, 261};

void setup() {
  pinMode(btn, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);

  ledcSetup(0, 2000, 8);
  ledcAttachPin(25, channel);
}

void loop() {
  if(cnt == 1){
    for(int i=0; i<4; i++){
      if(!digitalRead(btn)){
        break;
      }
      ledcWriteTone(channel, first[i]);
      delay(300);
    }
    ledcWriteTone(channel, 0);
    while(digitalRead(btn)){}
  }
  else if(cnt == 2){
    for(int i=0; i<25; i++){
      if(!digitalRead(btn)){
        break;
      }
      ledcWriteTone(channel, second[i]);
      delay(300);
    }
    ledcWriteTone(channel, 0);
    while(digitalRead(btn)){}
  }
  else{
    ledcWriteTone(channel, 0);
    while(digitalRead(btn)){}
  }
  cnt = (cnt+1)%3;
  delay(300);
}
