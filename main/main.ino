// #include "src/LcdKeypad.h"
#include "src/Microwave.h"
#include "src/LcdKeypad.h"
#include "src/LedRgb.h"
#include "src/Buzzer.h"
#include "src/Motor.h"

// Constantes auxiliares ------------------------------------------------------------------
const byte RS = 8, EN = 9, D4 = 4, D5 = 5, D6 = 6, D7 = 7; // Pinos para ligar o display
const byte R_PIN = 13, G_PIN = 12, B_PIN = 11;
const byte BUZZER_PIN = 2;
// ----------------------------------------------------------------------------------------

// Instancia o objeto ---------------------------------------------------------------------
// LCD Keypad
LcdKeypad lcdKeypad(RS, EN, D4, D5, D6, D7);
// Led RGB
LedRgb ledRgb(R_PIN, G_PIN, B_PIN);
// Buzzer
Buzzer buzzer(BUZZER_PIN);
// Motor
Motor motor(R_PIN);   // Aqui acho que não precisa alterar

// Finalmente, o Microondas (IHM)
Microwave microwave(lcdKeypad, ledRgb, buzzer, motor);
// -----------------------------------------------------------------------------------------

// Funções padrões -------------------------------------------------------------------------
void setup() {
   // Nada
}

void loop() {
    microwave.run();
    delay(200);
}
// -----------------------------------------------------------------------------------------
