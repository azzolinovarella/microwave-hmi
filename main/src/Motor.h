#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
  public:
    // MÉTODOS ----------------------------------
    Motor(byte motorPin);
    void turnOn();
    void turnOff();
    // ------------------------------------------
  
  private:
    // ATRIBUTOS --------------------------------
    // Indicativo do pino -----------------------
    byte motorPin;
    // ------------------------------------------
};

#endif