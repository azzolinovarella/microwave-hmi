#include "Microwave.h"
#include "LcdKeypad.h"

Microwave::Microwave(LcdKeypad lcdKeypadObject, LedRgb ledRgbObject, Buzzer buzzerObject, Motor motorObject)
    : lcdKeypad(lcdKeypadObject), ledRgb(ledRgbObject), buzzer(buzzerObject), motor(motorObject) {
        this->digitPosition = 0;
        this->ledRgb.turnOnGreen();  // Criar um método de setup para tudo?
}

void Microwave::run() {
    this->resolveInput(lcdKeypad.monitorButtons());
    this->lcdKeypad.print("INSIRA O TEMPO:", this->getTime(), this->mapBlinkPos());
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

byte Microwave::mapBlinkPos() {
    switch(this->digitPosition) {
        case 0:
            return 4;
        
        case 1: 
            return 3;

        case 2:
            return 1;
        
        case 3:
            return 0;
    }
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

int Microwave::getRunPeriod() {
    int totalPeriod;

    totalPeriod = this->unitSecDigit;
    totalPeriod += this->decSecDigit * 10;
    totalPeriod += this->unitMinDigit * 60;
    totalPeriod += this->decMinDigit * 60 * 10;

    return totalPeriod; 
}

void Microwave::updateDigits(int totalPeriod) {
    int remainder;
    
    this->decMinDigit = totalPeriod / 600;
    remainder = totalPeriod % 600;

    this->unitMinDigit = remainder / 60;
    remainder = remainder % 60;

    this->decSecDigit = remainder / 10;
    this->unitSecDigit = remainder % 10;
}

void Microwave::turnOnMicrowave() {
    int totalPeriod = this->getRunPeriod();

    // Microondas começa a funcionar
    this->ledRgb.turnOnRed();
    this->motor.turnOn();
    this->countDown(totalPeriod);
    
    // Microondas para de funcionar
    this->motor.turnOff();
    this->ledRgb.turnOnGreen();
    this->lcdKeypad.print("FINALIZADO", "", 17);
    this->buzzer.buzz(500, 1000);
}

void Microwave::countDown(int totalPeriod) {
    while(totalPeriod > 0) {
        totalPeriod -= 1;
        this->lcdKeypad.print("RODANDO...", this->getTime(), 17);
        this->updateDigits(totalPeriod);
        delay(1000);
    }
}