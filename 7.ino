#define R 12
#define G 13
#define B 14
#define btn 26

int cnt = 0;
bool push = false;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  
  if(!digitalRead(btn)){
    if(!push){
      cnt = (cnt+1)%4;
      push = true;
    }
  }
  else{
    push = false;
  }

  if(cnt == 1){
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
  else if(cnt == 2){
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
  }
  else if(cnt == 3){
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
  }
  else{
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
}
