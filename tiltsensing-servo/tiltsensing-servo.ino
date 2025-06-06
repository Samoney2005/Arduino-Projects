/* This sketch controls a servo mototr a tilt control switch!
 */
#include<Servo.h> // include Servo library
int inPin =2; // the tilt control switch is wires to Arduino D2 pin
int reading; // the current reading from the input pin
Servo myservo; // create servo motor object

void setup() {
  myservo.attach(9); // attach servo motor to pin 9 of Arduino
  pinMode(inPin, INPUT); // make pin 2 an input
  Serial.begin(9600); // open communication port
  
}

void loop() {
  reading = digitalRead(inPin); // store digital data in variable
  if(reading == HIGH){ // check digital data with target value
    myservo.write(90); //if digital data equals target value,
                        // servo motor rotates 90 degrees 
    Serial.println(reading); //print tilt control switch digital data    
    delay(15); // wait 15ms for rotation
  }
  else {          // if reading is not equal to the target value,
        myservo.write(0); // rotate servo motor to 0 degrees
        delay(15);      // wait 15ms for rotation
  }

}
