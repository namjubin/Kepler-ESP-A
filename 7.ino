#define R 12
#define G 13
#define B 14

int channel = 0;
int freq = 500;
int resolution = 8;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  ledcSetup(channel, freq, resolution);
}

void loop() {
  ledcAttachPin(R, channel);
  ledcWrite(channel, 255);
  delay(1000);
  ledcWrite(channel, 0);
  ledcAttachPin(G, channel+1);
  ledcWrite(channel+1, 255);
  delay(1000);
  ledcWrite(channel+1, 0);
  ledcAttachPin(B, channel+2);
  ledcWrite(channel+2, 255);
  delay(1000);
  ledcWrite(channel+2, 0);
}
