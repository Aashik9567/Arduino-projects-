#define buzzer 8
void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tone(buzzer, 10000,500);
  delay(1000);
  noTone(buzzer);
  delay(1000);
}