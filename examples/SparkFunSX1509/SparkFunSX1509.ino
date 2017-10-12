/*
Adapted from SparkFun's SX1509 digitalWrite example.
https://github.com/sparkfun/SparkFun_SX1509_Arduino_Library

This simple example demonstrates the SX1509's digital output 
functionality. Attach an LED to SX1509 IO 15, or just look at
it with a multimeter. We're gonna blink it!
*/

#include <SparkFunSX1509.h>
#include <VirtualPins.h>

VirtualPins<SX1509> io;

uint8_t SX1509_ADDRESS = 0x3E;

auto SX1509_LED_PIN = io[15];

void setup() {
    if (!io.begin(SX1509_ADDRESS)) {
        // If we fail to communicate, loop forever.
        while (true) continue;
    }

    pinMode(SX1509_LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(SX1509_LED_PIN, HIGH);
    delay(1000);
    digitalWrite(SX1509_LED_PIN, LOW);
    delay(1000);
}