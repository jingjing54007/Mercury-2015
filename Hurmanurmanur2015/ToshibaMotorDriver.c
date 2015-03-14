//*****************************************************************************
//
// TOSHIBA TB66215FNG DRIVER
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE AUTHORS OF THIS FILE
// SHALL NOT, UNDER ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
// OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
//
// Written by: 
// The student branch of the 
// IEEE - Robotics and Automation Society 
// at the University of Texas at Austin
//
// Website: ras.ece.utexas.edu
// Contact: ut.ieee.ras@gmail.com
//
//*****************************************************************************

// TOSHIBA MOTOR DRIVER
// USE FOR DRIVERS WITH TOSHIBA TB6612FNG MODEL CHIP
// requires 2 "logic" pins for motor state
// requires 1 PWM pin for speed and direction

#include "ToshibaMotorDriver.h"

// launchpad pins								// Driver pin names
#define L1 PIN_B4 							// AIN1
#define L2 PIN_B5 							// AIN2
#define R1 PIN_E4 							// BIN1
#define R2 PIN_E5 							// BIN2
#define LPWM PIN_B0							// PWMA
#define RPWM PIN_B1							// PWMB

static tPWM *pwm_left;
static tPWM *pwm_right;

// initialize PWMs
void TBInit(void) {
	
	pwm_left = InitializePWM(LPWM, 1000);
	pwm_right = InitializePWM(RPWM, 1000);
}

void TBForward(float speed_left, float speed_right) {

	// set logic bits
	SetPin(L1, 1);
	SetPin(L2, 0);
	SetPin(R1, 1);
	SetPin(R2, 0);
	
	// activate PWMs with speed
	SetPWM(pwm_left, speed_left, 0);
	SetPWM(pwm_right, speed_right, 0);
}

void TBLeft(float speed_left, float speed_right) {

	// set logic bits
	SetPin(L1, 0);
	SetPin(L2, 1);
	SetPin(R1, 1);
	SetPin(R2, 0);
	
	// activate PWMs with speed
	SetPWM(pwm_left, speed_left, 0);
	SetPWM(pwm_right, speed_right, 0);
}

void TBRight(float speed_left, float speed_right) {

	// set logic bits
	SetPin(L1, 1);
	SetPin(L2, 0);
	SetPin(R1, 0);
	SetPin(R2, 1);
	
	// activate PWMs with speed
	SetPWM(pwm_left, speed_left, 0);
	SetPWM(pwm_right, speed_right, 0);
}

void TBBackward(float speed_left, float speed_right) {

	// set logic bits
	SetPin(L1, 0);
	SetPin(L2, 1);
	SetPin(R1, 0);
	SetPin(R2, 1);
	
	// activate PWMs with speed
	SetPWM(pwm_left, speed_left, 0);
	SetPWM(pwm_right, speed_right, 0);
}

void TBBrake(void) {

	SetPin(L1, 1);
	SetPin(L2, 1);
	SetPin(R1, 1);
	SetPin(R2, 1);	
}

void TBCoast(void) {

	SetPin(L1, 0);
	SetPin(L2, 0);
	SetPin(R1, 0);
	SetPin(R2, 0);
}	
