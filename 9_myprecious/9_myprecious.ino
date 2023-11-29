#include <WiFi.h>
#include <HTTPClient.h>
#include "hc_sr04.h"
Distance distance;
#include "ds18b20.h"
Ds18b20 temperature;
#include "led.h"
Led led1(32);
Led led2(13);
Led led3(26);
Led led4(25);
Led led5(22);
Led led6(23);

//const char* ssid     = "GY_Chil_Museum Free";
//const char* password = "goyang600";
const char* ssid     = "cookie2";
const char* password = "0317137263";
int myid=1;

unsigned s=1;
unsigned mark=0, mark2=0;

void send(float temp, float humidity, int distance ) {
	if (temp==0) {
		Serial.printf("\n skip 0 temp");
		return;
	}
	HTTPClient http;
	String url = "http://t.damoa.io:8080/add?u=600&f=3&i=";
	url+=String("0T")+String(temp);
	url+=String(",0H")+String(humidity);
	url+=String(",0F")+String(distance);
	url += "&s="+String(s++);
	http.begin(url);
	Serial.printf("\n%s", url.c_str());
	int httpCode = http.GET();
	if(httpCode == HTTP_CODE_OK) {
		String payload = http.getString();
	} else {
		Serial.println("http error "+ String(httpCode));
	}
	http.end();
}

void setup(void)
{
	Serial.begin(115200);
	delay(1000);

	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}

	Serial.println("");
	Serial.println("WiFi connected");
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());
	mark = millis() + 2000;
	temperature.get();
}

void loop(void)
{
	if (millis()>mark) {
		mark = millis()+60000;
		send(temperature.get(), analogRead(33)/50., distance.get());
	}
	if (millis()>mark2) {
		mark2 = millis()+100;
		int d=distance.get();
		if (d>100) led2.on();
		else led2.off();
		if (d>75 && d<100) led3.on();
		else led3.off();
		if (d>50 && d<75) led4.on();
		else led4.off();
		if (d>25 && d<50) led5.on();
		else led5.off();
		if (d<25) {
			led6.on();
			led1.on();
		} else {
			led6.off();
			led1.off();
		}
	}
}