# MorseCodeToLED

An Arduino project that takes text typed into the serial monitor and blinks it out as Morse code on an LED.

## How it works

1. Type a message into the serial monitor and press Enter
2. The sketch converts it to Morse code using [morseCodeLibrary](https://github.com/haligoat/morseCodeLibrary)
3. The LED blinks the dots and dashes in real Morse timing
4. The dot/dash pattern is echoed back to the serial monitor as it plays

## Hardware

- Arduino Uno (or compatible)
- Built-in LED on pin 13 (`LED_BUILTIN`), or an external LED + 220Ω resistor on any digital pin

## Setup

This project uses PlatformIO. The `morseLib` files live in `lib/morseLib/`.

1. Clone this repo
2. Open in CLion (with the PlatformIO plugin) or VS Code (with the PlatformIO extension)
3. Build and upload to your Uno
4. Open the serial monitor at **115200 baud**, with line ending set to **Newline**

## Usage

\`\`\`
Print your text here: hello
.... . .-.. .-.. ---
\`\`\`

The LED blinks each symbol as it's printed.

## Timing

Speed is controlled by the `UoT` constant (unit of time, in milliseconds):

\`\`\`cpp
const int UoT = 200; // 1 unit = 200ms
\`\`\`

Lower it for faster blinking, raise it to make the pattern easier to follow by eye.

| Element | Duration |
|---|---|
| Dot | 1 unit |
| Dash | 3 units |
| Gap between symbols | 1 unit |
| Gap between letters | 3 units |
| Gap between words | 7 units |

## Related

- [morseCodeLibrary](https://github.com/haligoat/morseCodeLibrary) — the text-to-Morse conversion library this project depends on
