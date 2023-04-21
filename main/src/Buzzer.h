#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {
  public:
    // MÉTODOS ----------------------------------
    Buzzer(byte buzzerPin);
    void buzz(int smallerBuzzPeriod, int biggerBuzzPeriod);  // Em ms
    // ------------------------------------------

 private:
  // ATRIBUTOS --------------------------------
  byte buzzerPin;
  // -----------------------------------------
};

#endif