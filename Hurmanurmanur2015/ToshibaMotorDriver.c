#include "RASDemo.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/pwm.h>

static tMotor *Motors[4];
static tBoolean initialized = false;
tBoolean blink_on = true;
static tPWM *PWM_Left;
static tPWM *PWM_Right;

// heartbeat
void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}

// pins for Toshiba motor driver
#define L1 PIN_B4
#define L2 PIN_B5 
#define R1 PIN_E4 
#define R2 PIN_E5

// duty cycles for driving 
float forward = 50;
float left = 50;
float right = 50;
float back = 50;

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




int main(void)
{
//	initMotors();
		PWM_Left InitializePWM(PIN_B6, 1000);
		PWM_Right InitializePWM(PIN_E6, 1000);
	
//	SetMotor(Motors[0], forward);
//	SetMotor(Motors[1], forward);	
//	SetPin(PIN_B4,1);
//	SetPin(PIN_B5,0);
//	SetPin(PIN_E4,1);
//	SetPin(PIN_E5,0);
	
	TBForward(forward, forward, PWM_Left, PWM_Right);
	
	while(1);
}
