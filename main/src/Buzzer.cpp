#include "Buzzer.h"

Buzzer::Buzzer(byte buzzerPin) {
    this->buzzerPin = buzzerPin;
    pinMode(this->buzzerPin, OUTPUT);
}

void Buzzer::buzz(int smallerBuzzPeriod, int biggerBuzzPeriod) {
    // Primeiro bip - mais curto
    digitalWrite(this->buzzerPin, HIGH);
    delay(smallerBuzzPeriod);
    digitalWrite(this->buzzerPin, LOW);
    delay(smallerBuzzPeriod);
    // Segundo bip - igual ao primeiro
    digitalWrite(this->buzzerPin, HIGH);
    delay(smallerBuzzPeriod);
    digitalWrite(this->buzzerPin, LOW);
    delay(smallerBuzzPeriod);
    // Tericeiro bip - mais longo 
    digitalWrite(this->buzzerPin, HIGH);
    delay(biggerBuzzPeriod);
    // Desliga o buzzer
    digitalWrite(this->buzzerPin, LOW);
}