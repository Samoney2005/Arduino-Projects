#define GreenLED 13
#define WhiteLED 11
#define RedLED 9

int delaytime1 = 900;  // Delay between steps

void setup() {
  pinMode(GreenLED, OUTPUT);
  pinMode(WhiteLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
}

void loop() {
  // Step 1: All ON
  digitalWrite(GreenLED, HIGH);
  digitalWrite(WhiteLED, HIGH);
  digitalWrite(RedLED, HIGH);
  delay(delaytime1);

  // Step 2: Green + Red ON
  digitalWrite(WhiteLED, LOW);
  delay(delaytime1);

  // Step 3: Only White ON
  digitalWrite(GreenLED, LOW);
  digitalWrite(RedLED, LOW);
  digitalWrite(WhiteLED, HIGH);
  delay(delaytime1);

  // Step 4: All OFF
  digitalWrite(GreenLED, LOW);
  digitalWrite(WhiteLED, LOW);
  digitalWrite(RedLED, LOW);
  delay(delaytime1);

  // Step 5: Only Green ON
  digitalWrite(GreenLED, HIGH);
  delay(delaytime1);

  // Step 6: Only White ON
  digitalWrite(GreenLED, LOW);
  digitalWrite(WhiteLED, HIGH);
  delay(delaytime1);

  // Step 7: Only Red ON
  digitalWrite(WhiteLED, LOW);
  digitalWrite(RedLED, HIGH);
  delay(delaytime1);

  // Step 8: Only White ON
  digitalWrite(RedLED, LOW);
  digitalWrite(WhiteLED, HIGH);
  delay(delaytime1);

  // Step 9: Only Green ON
  digitalWrite(WhiteLED, LOW);
  digitalWrite(GreenLED, HIGH);
  delay(delaytime1);

  // Step 10: All OFF
  digitalWrite(GreenLED, LOW);
  digitalWrite(WhiteLED, LOW);
  digitalWrite(RedLED, LOW);
  delay(delaytime1);
}
