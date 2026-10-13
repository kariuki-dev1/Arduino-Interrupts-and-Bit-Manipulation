#include<Arduino.h>
const byte interruptPin = 2; // Pin for the interrupt
volatile bool pressedButton = false; // Flag to indicate if the interrupt has occurred

void buttonISR() {
  pressedButton = true; // Set the flag to indicate the interrupt has occurred
}

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP); // Set the interrupt pin as input with pull-up resistor
  attachInterrupt(digitalPinToInterrupt(interruptPin),buttonISR, FALLING); // Attach the interrupt to the pin
  detachInterrupt(digitalPinToInterrupt(interruptPin)); // Detach the interrupt to prevent it from triggering immediately
  attachInterrupt(digitalPinToInterrupt(interruptPin), buttonISR, FALLING); // Reattach the interrupt to the pin
}

void loop() {
  
    if (pressedButton) {
        Serial.println("Interrupt occurred!"); // Print a message when the interrupt occurs
        pressedButton = false; // Reset the flag
    }
}
