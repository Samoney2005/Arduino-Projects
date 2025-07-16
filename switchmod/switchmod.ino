// assign pin value to switches and LEDs

const byte SW1_pin = 2;

const byte SW2_pin = 3;

const byte SW3_pin = 4;

const byte LED1_pin = 6;

const byte LED2_pin = 7;

const byte LED3_pin = 8;

const byte LED4_pin = 9;

const byte LED5_pin = 10;

const byte LED6_pin = 11;

const byte LED7_pin = 12;

// the setup function runs once when you press reset or power the boardvoid setup() {

void setup() {

// Configure the switch pins as INPUT pins

pinMode(SW1_pin, INPUT);

pinMode(SW2_pin, INPUT);

pinMode(SW3_pin, INPUT);

// Configure our LED control pins as OUTPUT pins

pinMode(LED1_pin, OUTPUT);

pinMode(LED2_pin, OUTPUT);

pinMode(LED3_pin, OUTPUT);

pinMode(LED4_pin, OUTPUT);

pinMode(LED5_pin, OUTPUT);

pinMode(LED6_pin, OUTPUT);

pinMode(LED7_pin, OUTPUT);



}

void loop() {

// Each time through loop() we will check each switch in turn and set each light's state appropriately

// create a variable to hold the decimal number of 0 - 7

int led_value = 0; // reset to zero each time thru the loop.

if (digitalRead(SW1_pin) == HIGH) {

led_value += 1; // add 1 to the led_value

}



if (digitalRead(SW2_pin) == HIGH) {

led_value += 2; // add2 to the led_value

}

if (digitalRead(SW3_pin) == HIGH) {

led_value += 4; // add 4 to the led_value

}

// turn the LED ON for the matching digit.

if (led_value == 1) {

digitalWrite(LED1_pin, HIGH); // turn on LED by providing HIGH voltage (5v)

}else {

digitalWrite(LED1_pin, LOW); // turn off LED by setting output to LOW (zero volts)

}

if (led_value == 2) {

digitalWrite(LED2_pin, HIGH); // turn on LED by providing HIGH voltage (5v)

}else {

digitalWrite(LED2_pin, LOW); // turn off LED by setting output to LOW (zero volts)

}

if (led_value == 3) {

digitalWrite(LED3_pin, HIGH); // turn on LED by providing HIGH voltage (5v)

}else {

digitalWrite(LED3_pin, LOW); // turn off LED by setting output to LOW (zero volts)

}

if (led_value == 4) {

digitalWrite(LED4_pin, HIGH); // turn on LED by providing HIGH voltage (5v)

}else {

digitalWrite(LED4_pin, LOW); // turn off LED by setting output to LOW (zero volts)

}

if (led_value == 5) {

digitalWrite(LED5_pin, HIGH); // turn on LED by providing HIGH voltage (5v)

}else {

digitalWrite(LED5_pin, LOW); // turn off LED by setting output to LOW (zero volts)

}

if (led_value == 6) {

digitalWrite(LED6_pin, HIGH); // turn on LED by providing HIGH voltage (5v)

}else {

digitalWrite(LED6_pin, LOW); // turn off LED by setting output to LOW (zero volts)

}

if (led_value == 7) {

digitalWrite(LED7_pin, HIGH); // turn on LED by providing HIGH voltage (5v)

}else {

digitalWrite(LED7_pin, LOW); // turn off LED by setting output to LOW (zero volts)

}

}

// end
