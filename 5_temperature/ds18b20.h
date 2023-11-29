#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature _ds18b20(&oneWire);
class Ds18b20 {
public:
	bool ready;
	float temp_readings[8][100];
	int numreadings;
	int count;
	bool available;
	DeviceAddress address[8];
	
	Ds18b20() {
		available = true;
		ready = false;
	}
	
	float get() {
		float x=0;
		if (!available) return 0;
		if (!ready) {
			ready = true;
			_ds18b20.begin();
			if (_ds18b20.getDeviceCount()>0) {
			  Serial.printf("\nds18b20 found %d devices", _ds18b20.getDeviceCount());
			  count = _ds18b20.getDeviceCount();
			  for (int i=0; i<_ds18b20.getDeviceCount(); i++) {
				if (_ds18b20.getAddress(address[i], i)) Serial.printf("\n _ds18b20[%d] address ok, ", i);
				_ds18b20.setResolution(12);
				Serial.printf("resolution %d", _ds18b20.getResolution(address[i]));
			  }
			  _ds18b20.setWaitForConversion(false);
			  _ds18b20.requestTemperatures();
			} else Serial.printf("\nfound no _ds18b20");
			return 0;
		}
		for (int i=0; i<_ds18b20.getDeviceCount(); i++) {
			x = _ds18b20.getTempC(address[i]);
			//Serial.printf(" %.1f", x);
			//temp_readings[i][numreadings++]=x;
		}
		_ds18b20.requestTemperatures();
		return x;
	}
};