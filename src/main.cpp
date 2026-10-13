#include<Arduino.h>

uint8_t ledstate = 0b00000000;
 int ledpins[] = {2, 6, 4, 8};

 int inturruptpin = 3;

  volatile bool buttonpressed = false;

void buttonISR() {
  buttonpressed = true;
}

void setup() {
  // Initialization code here
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(ledpins[i], OUTPUT);
  }

  pinMode(inturruptpin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(inturruptpin), buttonISR, FALLING);

  bitSet(ledstate, 1);
  bitSet(ledstate, 2);
  bitSet(ledstate, 3);

  for (int i = 0; i < 4; i++) {
    digitalWrite(ledpins[i], bitRead(ledstate, i));
  }
  Serial.print(ledstate,BIN);



}

void loop() {
  // Main code here

  if (buttonpressed) 
  {
            bitClear(ledstate, 1);
            bitClear(ledstate, 2);
            bitClear(ledstate, 3);
            bitSet(ledstate, 0);

        for (int i = 0; i < 4; i++)
        {
        
            digitalWrite(ledpins[i], bitRead(ledstate, i));
        }
           buttonpressed = false;
  }
}