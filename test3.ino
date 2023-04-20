#define r 12
#define g 13
#define b 14
#define ss 36
#define buzzer 26

int center_value = 2300;
int value;

void setup() {
  Serial.begin(115200);
  
  pinMode(ss, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  value = analogRead(ss);
  Serial.println(value);

  if(value < center_value){
    digitalWrite(r, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(buzzer, LOW);
  }
  else if(value >= center_value and value < 3000){
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(buzzer, LOW);
  }
  else{
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
    digitalWrite(buzzer, HIGH);
  }
}
