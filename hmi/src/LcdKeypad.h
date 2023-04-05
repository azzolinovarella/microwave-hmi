#ifndef LCDKEYPAD_H
#define LCDKEYPAD_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class LcdKeypad {
  public:
    // MÉTODOS ----------------------------------
    LcdKeypad(byte rs, byte en, byte d4, byte d5, byte d6, byte d7);
    char monitorButtons();
    void print(String message);
    // ------------------------------------------

 private:
  // ATRIBUTOS --------------------------------
  LiquidCrystal lcd;
  // ------------------------------------------
};

#endif