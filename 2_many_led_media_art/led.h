class Led {
public:
	int pin;
	Led(int _pin) {
		pin=_pin;
	  pinMode(pin, OUTPUT);
	}

	void on() {
	  digitalWrite(pin,1);
	}

	void off() {
	  digitalWrite(pin,0);
	}
	
	void on_off(int _on, int _off) {
		on();
		delay(_on);
		off();
		delay(_off);
	}
};