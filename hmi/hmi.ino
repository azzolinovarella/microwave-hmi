#include <LiquidCrystal.h>

// Definição da classe HMI (Human Machine Interface) ------------------------------------
class HMI {
    public:
        // Segundo o ChatGPT, a sintaxe dos ":" segue: 
        /*
        This is a constructor for the HMI class that takes a LiquidCrystal object as an argument. The : 
        after the constructor name indicates that it is an initializer list for member variables. The 
        initializer list is used to initialize the member variable lcd with the passed lcdObject.
        In other words, this constructor creates a new HMI object and initializes its lcd member variable with the 
        lcdObject argument that is passed to the constructor. This allows you to create an HMI object with 
        an already existing LiquidCrystal object, rather than creating a new LiquidCrystal object inside the 
        HMI constructor. 
        */    
        HMI(LiquidCrystal lcdObject) : lcd(lcdObject) {
        // Quando tivermos outro objeto, ficaria: HMI(LiquidCrystal lcdObject, LedRGB ledObject) : lcd(lcdObject), led(ledObject)
            this->set_lcd(lcd);
        }
    
        void print(String message) {
            this->lcd.clear();
            this->lcd.setCursor(0, 0);
            this->lcd.print(message);
        }

        void monitorButtons() {
            switch(analogRead(0)) {
                case 0 ... 80:
                    this->right();
                    break;
                case 81 ... 200:
                    this->up();
                    break;
                case 201 ... 400:
                    this->down();
                    break;
                case 401 ... 600:
                    this->left();
                    break;
                case 601 ... 800:
                    this->select();
                    break;
            }
        }

    private:
        LiquidCrystal lcd;
        // LedRGB ledRGB;
        // Motor motor;
        // Buzzer buzzer;

        void set_lcd(LiquidCrystal lcd) {
            this->lcd = lcd;
            this->lcd.begin(16, 2);  // Define o número de colunas e linhas do display
        }

        void right() {
            this->print("RIGHT");
        }

        void up() {
            this->print("UP");
        }

        void down() {
            this->print("DOWN");
        }

        void left() {
            this->print("LEFT");
        }

        void select() {
            this->print("SELECT");
        }

        /* 
        void set_motor(Motor motor) {
            // etc.
        }
        */
};
// ----------------------------------------------------------------------------------------

// Constantes auxiliares ------------------------------------------------------------------
const byte rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // Pinos para ligar o display
// ----------------------------------------------------------------------------------------

// Instancia o objeto ---------------------------------------------------------------------
// LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Led RGB
// # TODO
// Motor
// # TODO
// Buzzer
// # TODO

// Finalmente, a HMI (IHM)
HMI hmi(lcd);
// -----------------------------------------------------------------------------------------

// Funções padrões -------------------------------------------------------------------------
void setup() {
    // Nada?
}

void loop() {
    hmi.monitorButtons();
    delay(100);  // TODO: Remover ou ver uma forma mais inteligente de fazer isso
}

// -----------------------------------------------------------------------------------------
