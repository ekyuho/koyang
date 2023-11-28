// 얘는 한번한 실행됩니다.
void setup() {
  pinMode(32, OUTPUT);
}

// 얘는 무한히 반복됩니다.
void loop() {
  digitalWrite(32,1);
  delay(1000);
  digitalWrite(32,0);
  delay(1000);
}