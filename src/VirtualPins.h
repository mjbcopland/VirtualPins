#pragma once

#include <stdint.h>

template<typename T>
class VirtualPin {
private:
    T &parent;
    const uint8_t pin;

public:
    explicit constexpr VirtualPin(T &parent, uint8_t pin) : parent(parent), pin(pin) {}

    void pinMode(uint8_t mode) const {
        parent.pinMode(pin, mode);
    }

    void digitalWrite(uint8_t val) const {
        parent.digitalWrite(pin, val);
    }

    int digitalRead() const {
        return parent.digitalRead(pin);
    }

    int analogRead() const {
        return parent.analogRead(pin);
    }

    void analogWrite(int val) const {
        parent.analogWrite(pin, val);
    }
};

template<typename T>
class VirtualPins : public T {
public:
    VirtualPin<T> operator[](int pin) {
        return VirtualPin<T>(*this, pin);
    }
    constexpr VirtualPin<const T> operator[](int pin) const {
        return VirtualPin<const T>(*this, pin);
    }
};

template<typename T>
inline void pinMode(const VirtualPin<T> &pin, uint8_t mode) {
    return pin.pinMode(mode);
}

template<typename T>
inline void digitalWrite(const VirtualPin<T> &pin, uint8_t val) {
    return pin.digitalWrite(val);
}

template<typename T>
inline int digitalRead(const VirtualPin<T> &pin) {
    return pin.digitalRead();
}

template<typename T>
inline int analogRead(const VirtualPin<T> &pin) {
    return pin.analogRead();
}

template<typename T>
inline void analogWrite(const VirtualPin<T> &pin, int val) {
    return pin.analogWrite(val);
}
