// 얘는 한번한 실행됩니다.
void setup() {
  led_init();
}

// 얘는 무한히 반복됩니다.
void loop() {
  led_on();
  delay(1000);
  led_off();
  delay(1000);
}