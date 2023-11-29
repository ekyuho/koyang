#include "hc_sr04.h"
Distance distance;
#include "led.h"
Led led1(32);

void setup(void)
{
	Serial.begin(115200);
	delay(1000);
}

void loop(void)
{
	int d=distance.get();
	Serial.println(d);
	led1.on_off(d*10, d*5);
}