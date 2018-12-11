/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  This example code is in the public domain.
 */

 #include "Test.h"

Test test("test");

void setup() {
	// initialize the digital pin as an output.
	// Pin 13 has an LED connected on most Arduino boards:
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	Serial.println(test.test());
	digitalWrite(LED_BUILTIN, HIGH);   // set the LED on
	delay(1500);              // wait for a second
	digitalWrite(LED_BUILTIN, LOW);    // set the LED off
	delay(1500);              // wait for a second
}
