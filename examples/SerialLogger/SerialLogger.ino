/*
A virtual blink example.
Instead of manipulating any physical I/O pins, the Logger
class prints a message to Serial describing the manipulation
of virtual pins.
The remainder of the sketch replicates a standard Blink example.
*/

#include <VirtualPins.h>

class Logger {
public:
    static void pinMode(uint8_t pin, uint8_t mode) {
        char buf[32];
        snprintf(buf, sizeof(buf), "Virtual pin %d mode = %d", pin, mode);

        Serial.println(buf);
    }

    static void digitalWrite(uint8_t pin, uint8_t val) {
        char buf[32];
        snprintf(buf, sizeof(buf), "Virtual pin %d value = %d", pin, val);

        Serial.println(buf);
    }
};

VirtualPins<Logger> io;

auto virtualPin = io[0];

void setup() {
    Serial.begin(9600);
    pinMode(virtualPin, OUTPUT);
}

void loop() {
    digitalWrite(virtualPin, HIGH);
    delay(1000);
    digitalWrite(virtualPin, LOW);
    delay(1000);
}