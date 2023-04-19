// #include "src/LcdKeypad.h"
#include "src/Microwave.h"
#include "src/LcdKeypad.h"
#include "src/LedRgb.h"
#include "src/Buzzer.h"
#include "src/Motor.h"
#define R_LED 0
#define B_LED 1
#define G_LED 2

// Constantes auxiliares ------------------------------------------------------------------
const byte RS = 8, EN = 9, D4 = 4, D5 = 5, D6 = 6, D7 = 7; // Pinos para ligar o display
const byte R_PIN = 0, G_PIN = 1, B_PIN = 2;
// ----------------------------------------------------------------------------------------

// Instancia o objeto ---------------------------------------------------------------------
// LCD Keypad
LcdKeypad lcdKeypad(RS, EN, D4, D5, D6, D7);
// Led RGB
LedRgb ledRgb(R_PIN, G_PIN, B_PIN);
// Buzzer
Buzzer buzzer(R_PIN);  // Alterar
// Motor
Motor motor(R_PIN);   // Aqui acho que não precisa alterar

// Finalmente, a HMI (IHM)
Microwave microwave(lcdKeypad, ledRgb, buzzer, motor);
// -----------------------------------------------------------------------------------------

// Funções padrões -------------------------------------------------------------------------
void setup() {
    // TODO: Nada?
}

void loop() {
    microwave.run();
    // Serial.print(microwave.decMinDigt);
    // Serial.print(microwave.unitMinDigt);
    // Serial.print(":");
    // Serial.print(microwave.decSecDigit);
    // Serial.println(microwave.unitSecDigit);
    // // Serial.println(analogRead(A0));
    // delay(100);
}

// -----------------------------------------------------------------------------------------
