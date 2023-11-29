#include "ds18b20.h"
Ds18b20 temperature;

void setup(void)
{
	Serial.begin(115200);
	delay(1000);
}

void loop(void)
{
	Serial.println(temperature.get());
	delay(300);
}