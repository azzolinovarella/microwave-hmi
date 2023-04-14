#include "Microwave.h"
#include "LcdKeypad.h"

Microwave::Microwave(LcdKeypad lcdKeypadObject, LedRgb ledRgbObject, Buzzer buzzerObject, Motor motorObject)
    : lcdKeypad(lcdKeypadObject), ledRgb(ledRgbObject), buzzer(buzzerObject), motor(motorObject) {
        digitPosition = 0;
}

void Microwave::run(){
    char input;

    input = lcdKeypad.monitorButtons();

    resolveInput(input);
}

void Microwave::resolveInput(char input){
    switch (input) {
        case 'r':
            this->digitPosition == 0 ? this->digitPosition = 4 : this->digitPosition -= 1;  
            break;       
        
        case 'u':
            if (this->digitPosition == 0) {
                this->unitSecDigit == 9 ? this->unitSecDigit = 0 : this->unitSecDigit += 1;
            
            } else if (this->digitPosition == 1) {
                this->decSecDigit == 5 ? this->decSecDigit = 0 : this->decSecDigit += 1;
            
            } else if (this->digitPosition == 2) {
                this->unitMinDigt == 9 ? this->unitMinDigt = 0 : this->unitMinDigt += 1;
            
            } else if (this->digitPosition == 4) {
                this->decMinDigt == 5 ? this->decMinDigt = 0 : this->decMinDigt += 1;
            }
            break;

        case 'd':
            if (this->digitPosition == 0) {
                this->unitSecDigit == 0 ? this->unitSecDigit = 9 : this->unitSecDigit -= 1;
            
            } else if (this->digitPosition == 1) {
                this->decSecDigit == 0 ? this->decSecDigit = 5 : this->decSecDigit -= 1;
            
            } else if (this->digitPosition == 2) {
                this->unitMinDigt == 0 ? this->unitMinDigt = 9 : this->unitMinDigt -= 1;
            
            } else if (this->digitPosition == 4) {
                this->decMinDigt == 0 ? this->decMinDigt = 5 : this->decMinDigt -= 1;
            }
            break;

        case 'l':
            this->digitPosition == 4 ? this->digitPosition = 0 : this->digitPosition += 1;
            break;

        case 's':
            this->turnOnMicrowave();
            break;
    
    }
}

void Microwave::increaseUnit(int unitDigit){
    // ToDo
}

void Microwave::decreaseUnit(int unitDigit){
    // ToDo
}

void Microwave::increaseDec(int decDigit){
    // ToDo   
}

void Microwave::decreaseDec(int decDigit){
    // ToDo    
}

void Microwave::turnOnMicrowave(){
    // ToDo
}