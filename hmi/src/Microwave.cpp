#include "Microwave.h"
#include "LcdKeypad.h"

Microwave::Microwave(LcdKeypad lcdKeypadObject, LedRgb ledRgbObject, Buzzer buzzerObject, Motor motorObject)
    : lcdKeypad(lcdKeypadObject), ledRgb(ledRgbObject), buzzer(buzzerObject), motor(motorObject) {
        this->digitPosition = 0;
        this->ledRgb.turnOnGreen();  // Criar um método de setup para tudo?
}

void Microwave::run() {
    char input;
    String time;

    input = lcdKeypad.monitorButtons();
    this->resolveInput(input);
    time = this->getTime();
    this->lcdKeypad.print("INSIRA O TEMPO:", time);
    delay(250);  // Calibrar
}

void Microwave::resolveInput(char input) {
    switch (input) {
        case 'r':
            this->resolveRight();  
            break;       
        
        case 'u':
            this->resolveUp();
            break;

        case 'd':
            this->resolveDown();
            break;

        case 'l':
            this->resolveLeft();
            break;

        case 's':
            this->turnOnMicrowave();
            break;
    
    }
}

void Microwave::resolveRight() {
    this->digitPosition == 0 ? this->digitPosition = 3 : this->digitPosition -= 1;
}

void Microwave::resolveUp() {
    switch(this->digitPosition) {
        case 0:
            this->unitSecDigit == 9 ? this->unitSecDigit = 0 : this->unitSecDigit += 1;
            break;
        
        case 1:
            this->decSecDigit == 5 ? this->decSecDigit = 0 : this->decSecDigit += 1;
            break;
        
        case 2:
            this->unitMinDigit == 9 ? this->unitMinDigit = 0 : this->unitMinDigit += 1;
            break;
        
        case 3:
            this->decMinDigit == 5 ? this->decMinDigit = 0 : this->decMinDigit += 1;
            break;
    }
}

void Microwave::resolveDown() {
    switch(this->digitPosition) {
        case 0:
            this->unitSecDigit == 0 ? this->unitSecDigit = 9 : this->unitSecDigit -= 1;
            break;

        case 1:
            this->decSecDigit == 0 ? this->decSecDigit = 5 : this->decSecDigit -= 1;
            break;

        case 2:
            this->unitMinDigit == 0 ? this->unitMinDigit = 9 : this->unitMinDigit -= 1;
            break;

        case 3:
            this->decMinDigit == 0 ? this->decMinDigit = 5 : this->decMinDigit -= 1;
            break;
    }
}

void Microwave::resolveLeft() {
    this->digitPosition == 3 ? this->digitPosition = 0 : this->digitPosition += 1;
}

String Microwave::getTime() {
    String time;

    time = (String) this->decMinDigit;
    time += (String) this->unitMinDigit;
    time += ":";
    time += (String) this->decSecDigit;
    time += (String) this->unitSecDigit;

    return time;
}

unsigned long Microwave::getRuntime() {
    unsigned long totalPeriod;

    totalPeriod = this->unitSecDigit;
    totalPeriod += this->decSecDigit * 10;
    totalPeriod += this->unitMinDigit * 60;
    totalPeriod += this->decMinDigit * 60 * 10;

    return totalPeriod; 
}

void Microwave::turnOnMicrowave() {
    unsigned long initialTime = millis();
    unsigned long currentTime = millis();  // No início é assim mesmo
    unsigned long totalPeriod = this->getRuntime();

    this->ledRgb.turnOnRed();
    // this->motor.turnOn();
    // Sepa mudar para usar delay??? Acho mais fácil e o display não buga!
    while ((currentTime - initialTime)/1000 < totalPeriod) {
        // ToDo 
        this->lcdKeypad.print("RODANDO...", "TEMPO");

        currentTime = millis();
    }
    // this->motor.turnOff();
    this->ledRgb.turnOnGreen();
    // this->buzzer.buzz();

    // Só para testar
    this->decMinDigit = 0;
    this->unitMinDigit = 0;
    this->decSecDigit = 0;
    this->unitSecDigit = 0;
}