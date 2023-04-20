#ifndef MICROWAVE_H
#define MICROWAVE_H

#include <Arduino.h>

#include "LcdKeypad.h"
#include "LedRgb.h"
#include "Buzzer.h"
#include "Motor.h"

class Microwave {
	public:
		// MÉTODOS ----------------------------------
		Microwave(LcdKeypad lcdKeypad, LedRgb ledRgb, Buzzer buzzer, Motor motor);
		void run();
		// ------------------------------------------


	private:
		// MÉTODOS ----------------------------------
		void resolveInput(char input);
		void resolveRight();
		void resolveUp();
		void resolveDown();
		void resolveLeft();
		byte mapBlinkPos();
		String getTime();
		int getRunPeriod();
		void updateDigits(int totalPeriod);
		void turnOnMicrowave();
		void countDown(int totalPeriod);
		// ------------------------------------------
		// ATRIBUTOS --------------------------------
		// Objetos 
		LcdKeypad lcdKeypad;
		LedRgb ledRgb;
		Buzzer buzzer;
		Motor motor;
		// Digitos
		int digitPosition;  // 0 - uni sec, 1 - dec sec, 2- uni min, 3 - dec min
		int unitSecDigit;
		int decSecDigit;
		int unitMinDigit;
		int decMinDigit;
		// -----------------------------------------
};

#endif