#include "LcdKeypad.h"
#include <LiquidCrystal.h>

LcdKeypad::LcdKeypad(byte rs, byte en, byte d4, byte d5, byte d6, byte d7)
    : lcd(rs, en, d4, d5, d6, d7) {
        lcd.begin(16, 2);
}

char LcdKeypad::monitorButtons() {
    switch(analogRead(0)) {
        case 0 ... 80:     // Right
            return 'r';
        case 81 ... 200:   // Up
            return 'u';
        case 201 ... 400:  // Down
            return 'd';
        case 401 ... 600:  // Left
            return 'l';
        case 601 ... 800:  // Select
            return 's';
        default:
            return NULL;   // Se não deixar isso, ele mantém o valor anterior!
    }
}

void LcdKeypad::print(String messageRow1, String messageRow2) {
    this->lcd.clear(); 
    this->lcd.setCursor(0, 0);
    this->lcd.print(messageRow1);
    this->lcd.setCursor(0, 1);
    this->lcd.print(messageRow2);
}