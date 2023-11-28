// 얘는 한번한 실행됩니다.
void setup() {
  pinMode(32, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
}

void on(int pin) {
  digitalWrite(pin,1);
}

void off(int pin) {
  digitalWrite(pin,0);
}

// 얘는 무한히 반복됩니다.
//32 13 26 25 22 23
void loop() {
  on(32); on(13); on(26); on(25); on(22); on(23);
  delay(1000);
  off(32); off(13); off(26); off(25); off(22); off(23);
  delay(1000);
}