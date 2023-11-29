#include "led.h"
Led led1(32);
Led led2(13);
Led led3(26);
Led led4(25);
Led led5(22);
Led led6(23);

void setup() {
}

void loop() {
  led1.on_off(30, 500); //켜져있는 시간, 꺼져있는 시간 밀리초
  led2.on_off(30, 100);
  led3.on_off(30, 100);
  led4.on_off(30, 100);
  led5.on_off(30, 100);
  led6.on_off(30, 1000);
}