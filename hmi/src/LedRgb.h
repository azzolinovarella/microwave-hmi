#ifndef LEDRGB_H
#define LEDRGB_H

#include <Arduino.h>

class LedRgb {
  public:
    // MÉTODOS ----------------------------------
    LedRgb(byte rPin, byte gPin, byte bPin);
    void turnOff();
    void turnOnRed();
    void turnOnGreen();
    void turnOnBlue();
    void test();
    // ------------------------------------------

  private:
    // ATRIBUTOS --------------------------------
    // Indicativo do pino -----------------------
    byte rPin;
    byte gPin;
    byte bPin;
    // Status dos LED ---------------------------
    byte rPinStatus;
    byte gPinStatus;
    byte bPinStatus;
    // ------------------------------------------
    // MÉTODOS ----------------------------------
    void setRPin(byte rPin);
    void setGPin(byte gPin);
    void setBPin(byte bPin);
    // ------------------------------------------
};

#endif