#include <Arduino.h>
#include "morseLib.h"
#include <string.h>
const int UoT = 500;




void ledOn( int units) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(UoT*units);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}

void textToMorseToLed(char c []) {
    char input [SIZE_INPUT];
    strcpy(input, c);
    char output[SIZE_OUTPUT];
    convertToMorse(input, output);

    for (int i = 0; output[i] != '\0'; i++) {

        switch (output[i]){
            case '.':
                Serial.print(".");
                ledOn(1);
                break;
            case '-':
                Serial.print("-");
                ledOn(3);
                break;
            case ' ':
                Serial.print(" ");
                delay(4000);
                break;

        }
    }
    Serial.println();

}

int readUserInput(char buffer[]) {
    int i = 0;
    while (true) {
        if (Serial.available()) {
            char curChar = Serial.read();
            if (curChar == '\n') {
                break;
            }
            if (curChar != '\r' && i < SIZE_INPUT -1 ) {
                buffer[i] = curChar;
                i++;
            }
        }
    }

    buffer[i] = '\0';
    return i;
}

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(10*UoT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    char text[SIZE_INPUT];
    Serial.print("Print your text here: ");
    while (!Serial.available()){}
    int len = readUserInput(text);
    Serial.println(text);
    text[len] = '\0';
    textToMorseToLed(text);
}

