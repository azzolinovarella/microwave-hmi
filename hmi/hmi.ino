#include "src/LcdKeypad.h"
#define R_LED 0
#define B_LED 1
#define G_LED 2

// Definição da classe HMI (Human Machine Interface) ------------------------------------
class HMI {  // TODO: Talvez renomear para Microwave (?)
    // TODO: Usando de exemplo; Apartar depois (?)
    public:
        // Quando tivermos outro objeto, ficaria: HMI(LiquidCrystal lcdObject, LedRGB ledObject) : lcd(lcdObject), led(ledObject)
        HMI(LcdKeypad lcdKeypadObject) : lcdKeypad(lcdKeypadObject) {
            this->setLcdKeypad(lcdKeypad);
        }
        
    private:
        LcdKeypad lcdKeypad;
        // LedRgb ledRgb;
        // Motor motor;
        // Buzzer buzzer;

        void setLcdKeypad(LcdKeypad LcdKeypad) {
            this->lcdKeypad = lcdKeypad;
        }
};
// ----------------------------------------------------------------------------------------

// Constantes auxiliares ------------------------------------------------------------------
const byte RS = 8, EN = 9, D4 = 4, D5 = 5, D6 = 6, D7 = 7; // Pinos para ligar o display
// ----------------------------------------------------------------------------------------

// Instancia o objeto ---------------------------------------------------------------------
// LCD Keypad
LcdKeypad lcdKeypad(RS, EN, D4, D5, D6, D7);
// Led RGB
// # TODO
// Motor
// # TODO
// Buzzer
// # TODO

// Finalmente, a HMI (IHM)
HMI hmi(lcdKeypad);
// -----------------------------------------------------------------------------------------

// Funções padrões -------------------------------------------------------------------------
void setup() {
    // TODO: Nada?
}

void loop() {
    // TODO
}

// -----------------------------------------------------------------------------------------
