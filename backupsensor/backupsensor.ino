const int whiteLed = 5;
const int greenLed = 6;
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 12;
const int redLed = 13;

long duration;
int distance;

// Blink delays (ms) for each distance zone
const int blinkDelayFast = 150;    // fastest blink
const int blinkDelayMedium = 400;  // medium blink
const int blinkDelaySlow = 700;    // slowest blink

// Frequencies for buzzer (simulating volume by pitch)
const int buzzerFreqHigh = 1200;   // high freq = “loud”
const int buzzerFreqMedium = 800;  // medium freq
const int buzzerFreqLow = 400;     // low freq = “quiet”

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo duration and calculate distance in cm
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println(distance);
  delay(10);

  if (distance <= 5) {
    // Very close: all LEDs ON steady + continuous long beep
    digitalWrite(redLed, HIGH);
    digitalWrite(whiteLed, HIGH);
    digitalWrite(greenLed, HIGH);

    tone(buzzer, 1000); // continuous beep
    delay(1000);
    noTone(buzzer);
  }
  else if (distance <= 10) {
    // 3 LEDs blinking fast + buzzer high freq
    blinkLEDsWithTone(blinkDelayFast, buzzerFreqHigh, true, true, true);
  }
  else if (distance <= 20) {
    // 2 LEDs blinking medium + buzzer medium freq
    blinkLEDsWithTone(blinkDelayMedium, buzzerFreqMedium, true, false, true);
  }
  else if (distance <= 30) {
    // 1 LED blinking slow + buzzer low freq
    blinkLEDsWithTone(blinkDelaySlow, buzzerFreqLow, true, false, false);
  }
  else {
    // Far away: all LEDs off, buzzer off
    digitalWrite(redLed, LOW);
    digitalWrite(whiteLed, LOW);
    digitalWrite(greenLed, LOW);
    noTone(buzzer);
    delay(1000);
  }
}

// Blink specified LEDs together with buzzer tone synced to blink speed
void blinkLEDsWithTone(int delayTime, int freq, bool redOn, bool whiteOn, bool greenOn) {
  // Turn LEDs ON
  digitalWrite(redLed, redOn ? HIGH : LOW);
  digitalWrite(whiteLed, whiteOn ? HIGH : LOW);
  digitalWrite(greenLed, greenOn ? HIGH : LOW);

  tone(buzzer, freq);  // buzzer ON
  delay(delayTime);

  // Turn LEDs OFF
  digitalWrite(redLed, LOW);
  digitalWrite(whiteLed, LOW);
  digitalWrite(greenLed, LOW);

  noTone(buzzer);      // buzzer OFF
  delay(delayTime);
}
