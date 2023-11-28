// https://randomnerdtutorials.com/esp32-hc-sr04-ultrasonic-arduino/
const int trigPin = 16;
const int echoPin = 17;
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
}

float distance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED/2;
  Serial.println(distanceCm);
  return(int(distanceCm));
}

void loop() {
  int d=distance();
  Serial.println(d);
  delay(1000);
}
