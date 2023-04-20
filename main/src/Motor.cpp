#include "Motor.h"

Motor::Motor(byte motorPin) {
    this->motorPin = motorPin;
    pinMode(this->motorPin, OUTPUT);
}

void Motor::turnOn() {
    digitalWrite(this->motorPin, HIGH);
}

void Motor::turnOff() {
    digitalWrite(this->motorPin, LOW);
}