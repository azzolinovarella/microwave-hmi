#include "Buzzer.h"

Buzzer::Buzzer(byte buzzerPin) {
    this->buzzerPin = buzzerPin;
    pinMode(this->buzzerPin, OUTPUT);
}

void Buzzer::buzz(int buzzPeriod) {
    // Primeiro bip - mais curto
    digitalWrite(this->buzzerPin, HIGH);
    delay(buzzPeriod/4);
    digitalWrite(this->buzzerPin, LOW);
    delay(buzzPeriod/4);
    // Segundo bip - igual ao primeiro
    digitalWrite(this->buzzerPin, HIGH);
    delay(buzzPeriod/4);
    digitalWrite(this->buzzerPin, LOW);
    delay(buzzPeriod/4);
    // Tericeiro bip - mais longo 
    digitalWrite(this->buzzerPin, HIGH);
    delay(buzzPeriod/2);
    // Desliga o buzzer
    digitalWrite(this->buzzerPin, LOW);
}