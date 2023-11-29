const int trigPin = 16;
const int echoPin = 17;
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

class Distance {
public:
	long duration;
	float distanceCm;
	
	Distance(void) {
		pinMode(trigPin, OUTPUT);
		pinMode(echoPin, INPUT);
	}

	float get() {
		digitalWrite(trigPin, LOW);
		delayMicroseconds(2);
		digitalWrite(trigPin, HIGH);
		delayMicroseconds(10);
		digitalWrite(trigPin, LOW);

		duration = pulseIn(echoPin, HIGH);
		distanceCm = duration * SOUND_SPEED/2;
		//Serial.println(distanceCm);
		return(int(distanceCm));
	}
};