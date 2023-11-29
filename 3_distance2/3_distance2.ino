#include "hc_sr04.h"
Distance distance;
#include "led.h"
Led led1(32);
Led led2(13);
Led led3(26);
Led led4(25);
Led led5(22);
Led led6(23);

void setup(void)
{
	Serial.begin(115200);
	delay(1000);
}

void loop(void)
{
	int d=distance.get();
	Serial.println(d);
	
	if (d>100) led2.on();
	else led2.off();
	if (d>75 && d<100) led3.on();
	else led3.off();
	if (d>50 && d<75) led4.on();
	else led4.off();
	if (d>25 && d<50) led5.on();
	else led5.off();
	if (d>10 && d<25) led6.on();
	else led6.off();
	if (d<10) led1.on();
	else led1.off();
	delay(200);
}