#include "led.h"
Led led1(32);

void setup() {
}

void loop() {
  led1.on_off(30, 1000);
}