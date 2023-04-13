#define R 12
#define G 13
#define B 14

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  digitalWrite(R, HIGH);
  delay(1000);
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  delay(1000);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
  delay(1000);
  digitalWrite(B, LOW);
}
