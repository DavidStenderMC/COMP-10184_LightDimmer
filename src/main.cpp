#include <Arduino.h>

/*
  I, David Stender, 000828140 certify that this material is my original work.
  No other person's work has been used without due acknowledgement.
*/

bool lightOn = false; // If the light should be on
bool lastButtonState; // The state of the button on the last loop
bool currentButtonState; // The state of the button on this loop
 
void setup() { 
  pinMode(D5, INPUT_PULLUP);// configure pin D5 as digital input - this is the pushbutton 
  pinMode(D4, OUTPUT); // configure pin D4 as a digital output - this is the LED 
  analogWriteRange(1023); // set default PWM range 
  currentButtonState = digitalRead(D5);
} 
 
 
void loop() {
  // Handles the state of the button and the what the state of the light
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(D5);
  if(lastButtonState == 1 && currentButtonState == 0) {
    lightOn = !lightOn;
    delay(1);
  }

  // Controls if the light is on and can be controlled or if it is just off
  if(lightOn) {
    analogWrite(D4, analogRead(A0));
  } else{
    digitalWrite(D4,1);
  }
}