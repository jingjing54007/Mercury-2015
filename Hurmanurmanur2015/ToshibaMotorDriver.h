#include "RASDemo.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/pwm.h>

// pins for Toshiba motor driver
#define L1 PIN_B4
#define L2 PIN_B5 
#define R1 PIN_E4 
#define R2 PIN_E5

// TOSHIBA MOTOR DRIVER 
// requires 2 "logic" pins for motor state
// requires 1 PWM pin for speed and direction

void TBForward(float Lspeed, float Rspeed, tPWM *left, tPWM *right) {

	// set logic bits
	SetPin(L1, 1);
	SetPin(L2, 0);
	SetPin(R1, 1);
	SetPin(R2, 0);
	
	// activate PWMs with speed
	SetPWM(left, Lspeed, 0);
	SetPWM(right, Rspeed, 0);
}

void TBLeft(float speed) {

	// set logic bits
	SetPin(L1, 0);
	SetPin(L2, 1);
	SetPin(R1, 1);
	SetPin(R2, 0);
	
	// activate PWMs with speed
}

void TBRight(float speed) {

	// set logic bits
	SetPin(L1, 1);
	SetPin(L2, 0);
	SetPin(R1, 0);
	SetPin(R2, 1);
	
	// activate PWMs with speed
}

void TBBackward(float speed) {

	// set logic bits
	SetPin(L1, 0);
	SetPin(L2, 1);
	SetPin(R1, 0);
	SetPin(R2, 1);
	
	// activate PWMs with speed
}

