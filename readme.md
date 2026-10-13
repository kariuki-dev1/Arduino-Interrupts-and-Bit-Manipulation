# Arduino Interrupts and Bit Manipulation

## Overview
A beginner Arduino Uno project demonstrating external interrupts, bit manipulation, arrays, and digital outputs using PlatformIO and Wokwi.

## Project Objective
Control four LEDs using a pushbutton interrupt.

- **Initial state:** LEDs connected to pins 4, 6, and 8 are ON. The LED on pin 2 is OFF.
- **When the button is pressed:** The LED on pin 2 turns ON, while the LEDs on pins 4, 6, and 8 turn OFF.

## Components
- Arduino Uno
- 4 red LEDs
- 4 resistors
- 1 pushbutton
- Wokwi simulator

## Pin Connections

| Component | Arduino pin |
|---|---|
| LED 1 | 2 |
| LED 2 | 6 |
| LED 3 | 4 |
| LED 4 | 8 |
| Pushbutton | 3 |
| Button ground | GND |

Each LED has its own current-limiting resistor. The button uses the Arduino's internal pull-up resistor.

## Concepts Practised

- `pinMode()` and `digitalWrite()`
- Arrays and `for` loops
- Binary representation using `uint8_t`
- `bitSet()`, `bitClear()`, and `bitRead()`
- External interrupts with `attachInterrupt()`
- `INPUT_PULLUP` and `FALLING`
- `volatile` variables and interrupt service routines (ISRs)
- Using a flag to let `loop()` handle an interrupt event

## How It Works

1. `setup()` configures the LED pins as outputs and the button pin as an input with pull-up.
2. `attachInterrupt()` registers `buttonISR()` to respond when the button signal falls from HIGH to LOW.
3. The ISR sets `buttonpressed` to `true`.
4. `loop()` detects the flag and changes the LED state using bit manipulation.
5. The flag resets to `false`, allowing the program to respond to another button press.

## Project Files

- `src/temp.cpp` — Arduino program.
- `diagram.json` — Wokwi circuit schematic.
- `platformio.ini` — PlatformIO project configuration.
- `wokwi.toml` — Wokwi simulator configuration.

## Tools
- C++ / Arduino framework
- PlatformIO
- Wokwi

## Future Improvements
- Toggle between the two LED patterns on successive button presses.
- Explore switch debouncing.
- Experiment with different bit patterns.

## Learning Outcome
This project demonstrates how an Arduino can respond to an external hardware event without continuously polling the button in `loop()`.
