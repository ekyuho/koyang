void setup(void)
{
	Serial.begin(115200);
	delay(1000);
}

void loop(void)
{
	Serial.println(analogRead(33)/50);
	delay(1000);
}