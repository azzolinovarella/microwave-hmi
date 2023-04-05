#include "LedRgb.h"

LedRgb::LedRgb(byte rPin, byte gPin, byte bPin) {
    this->setRPin(rPin);
    this->setGPin(gPin);
    this->setBPin(bPin);
    this->turnOff();  // Seta o status do R, G e B
}

void LedRgb::turnOff() {
   this->rPinStatus = LOW;
   this->gPinStatus = LOW;
   this->bPinStatus = LOW;
   
   digitalWrite(this->rPin, this->rPinStatus);
   digitalWrite(this->gPin, this->gPinStatus);
   digitalWrite(this->bPin, this->bPinStatus);
}

void LedRgb::turnOnRed() {
   this->turnOff();
   
   this->rPinStatus = HIGH;
   digitalWrite(this->rPin, this->rPinStatus); 
}

void LedRgb::turnOnGreen() {
   this->turnOff();
   
   this->gPinStatus = HIGH;
   digitalWrite(this->gPin, this->gPinStatus); 
}

void LedRgb::turnOnBlue() {
   this->turnOff();
   
   this->bPinStatus = HIGH;
   digitalWrite(this->bPin, this->bPinStatus); 
}

void LedRgb::test() {
   this->turnOff();
   this->rPinStatus = HIGH;
   digitalWrite(this->rPin, this->rPinStatus);
   Serial.print(this->rPinStatus);
   Serial.print(this->gPinStatus);
   Serial.println(this->bPinStatus);
   delay(500);
   
   this->turnOff();
   this->gPinStatus = HIGH;
   digitalWrite(this->gPin, this->gPinStatus);
   Serial.print(this->rPinStatus);
   Serial.print(this->gPinStatus);
   Serial.println(this->bPinStatus);
   delay(500);
   
   this->turnOff();
   this->bPinStatus = HIGH;
   digitalWrite(this->bPin, this->bPinStatus);
   Serial.print(this->rPinStatus);
   Serial.print(this->gPinStatus);
   Serial.println(this->bPinStatus);
   delay(500);
}

void LedRgb::setRPin(byte rPin) {
     pinMode(rPin, OUTPUT);
     this->rPin = rPin;
}
   
void LedRgb::setGPin(byte gPin) {
   pinMode(gPin, OUTPUT);
   this->gPin = gPin;
}

void LedRgb::setBPin(byte bPin) {
   pinMode(bPin, OUTPUT);
   this->bPin = bPin;
}
