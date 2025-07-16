const int blueLed = 13;    
const int greenLed = 12;  
const int redLed = 11;   
const int whiteLed = 10;
const int yellowLed = 9;  
const int buttonPin = 8;  

int buttonState = HIGH;
int lastButtonState = HIGH;
int buttonPressCount = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

bool actionDone = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);

  Serial.begin(9600);
  Serial.println("Ready.");
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Debounce
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        buttonPressCount++;
        if (buttonPressCount > 4) buttonPressCount = 1;
        actionDone = false;

        Serial.print("Running program ");
        Serial.println(buttonPressCount);
      }
    }
  }

  lastButtonState = reading;

  if (!actionDone) {
    runProgram(buttonPressCount);
    actionDone = true;
  }
}

void runProgram(int step) {
  switch (step) {
    case 1:
      // Keep all LEDs ON (stay ON until next press)
      setAllLeds(HIGH);
      break;

    case 2:
      // Flash pattern (ON/OFF alternate) 5 times
      for (int i = 0; i < 5; i++) {
        digitalWrite(blueLed, LOW);
        digitalWrite(greenLed, HIGH);
        digitalWrite(redLed, LOW);
        digitalWrite(whiteLed, HIGH);
        digitalWrite(yellowLed, LOW);
        delay(500);

        digitalWrite(blueLed, HIGH);
        digitalWrite(greenLed, LOW);
        digitalWrite(redLed, HIGH);
        digitalWrite(whiteLed, LOW);
        digitalWrite(yellowLed, HIGH);
        delay(500);
      }
      setAllLeds(LOW); // Then turn OFF
      break;

    case 3:
      // Slower cascading lights (Christmas style)
      for (int i = 0; i < 3; i++) {  // Repeat pattern 3 times
        digitalWrite(yellowLed, HIGH); delay(500); digitalWrite(yellowLed, LOW);
        digitalWrite(whiteLed, HIGH); delay(500); digitalWrite(whiteLed, LOW);
        digitalWrite(redLed, HIGH);   delay(500); digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH); delay(500); digitalWrite(greenLed, LOW);
        digitalWrite(blueLed, HIGH);  delay(500); digitalWrite(blueLed, LOW);
      }
      setAllLeds(LOW);
      break;

    case 4:
      // All LEDs OFF
      setAllLeds(LOW);
      break;
  }
}

void setAllLeds(bool state) {
  digitalWrite(blueLed, state);
  digitalWrite(greenLed, state);
  digitalWrite(redLed, state);
  digitalWrite(whiteLed, state);
  digitalWrite(yellowLed, state);
}
