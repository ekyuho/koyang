// 얘는 한번한 실행됩니다.
void setup() {
  pinMode(32, OUTPUT);
}

void on(int pin) {
 digitalWrite(pin,1);
}

void off(int pin) {
 digitalWrite(pin,0);
}

// 얘는 무한히 반복됩니다.
void loop() {
  on(32);
  delay(30);
  off(32);
  delay(1000);
}