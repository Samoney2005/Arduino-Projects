const int blueLed = 13;
const int  yellowLed  = 12;

int delaytime = 300;

void setup() {
  pinMode(blueLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
}

void loop() {
  digitalWrite(blueLed, HIGH);
  delay(delaytime);
  digitalWrite(blueLed, LOW);
  delay(delaytime);

  digitalWrite(yellowLed, HIGH);
  delay(delaytime);
  digitalWrite(yellowLed, LOW);
  delay(delaytime);
}
