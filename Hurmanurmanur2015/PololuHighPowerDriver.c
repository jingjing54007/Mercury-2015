//*****************************************************************************
// Written for Pololu High-Power Motor Driver 18v15 
// https://www.pololu.com/product/755
//
// PWM	DIR		OUTA	OUTB	Operation
// H		L			L			H			Forward
// H		H			H			L			Backward
// L		X			L			L			Brake
//*****************************************************************************

#include "RASDemo.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/pwm.h>

#define LDIR
#define RDIR

static tPWM *LPWM; // 
static tPWM *RPWM; //

void InitGearMotor(void) {
	
	SetPin(LDIR, 0);
	SetPin(RDIR, 0);
	LPWM = InitializePWM( // pin ,1000);
	RPWM = InitializePWM( ,1000);
}
	
void SetGearMotor(float left, float right) {

		if (left == 0 && right == 0) {
			StopGearMotor();
		}
		
		if (left < 0) {
			left = -left;
			SetPin(LDIR, 1); // set direction backward
		} 
		if (left > 0) {
			SetPin(LDIR, 0); // else go forward
		}
		if (right < 0) {
			right = -right;
			SetPin(RDIR, 1); 
		}
		if (right > 0) {
			SetPin(RDIR, 0);
		}
		
		SetPWM(LPWM, left_speed, 0);
		SetPWM(RPWM, right_speed, 0);		
}

void StopGearMotor(void) {
	
		SetPWM(LPWM, 0, 0);
		SetPWM(RPWM, 0, 0);
}