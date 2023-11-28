void led_init() {
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  digitalWrite(33, 0);
}

void led_on() {
  digitalWrite(32,1);
}

void led_off() {
  digitalWrite(32,0);
}