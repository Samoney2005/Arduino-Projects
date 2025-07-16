const int button = 13;
const int yellowLed = 12; 
const int buzzer = 11;
int buttonState = 0;
int counter = 0;
bool ledState = false;

void setup() {
pinMode(button, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(yellowLed, OUTPUT);
Serial.begin(9600);
}

void loop() {
  buttonState  = digitalRead(button);
  Serial.println(buttonState);
  
  if(buttonState == HIGH)
  {
    counter++;
    Serial.print("Counter:");
    Serial.println(counter);

    ledState = !ledState;
  }

  if(ledState == true)
  {
    digitalWrite(yellowLed, HIGH);
    tone(buzzer, 600);
    delay(600);
  }
  else
  {
    digitalWrite(yellowLed, LOW);
    tone(buzzer, 300);
    delay(300);
  }
  delay (300);
}
