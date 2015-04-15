#include "RASLib/inc/common.h"
#include "RASLib/inc/adc.h"
#include "RASLib/inc/motor.h"

#define OK_FRONT_DIST 100000
#define OK_SIDE_DIST 10

tADC *adc[3];	
tMotor *motors[4];


/*	Activate pins D0 - D2 to take in input from IR sensors
 *	D0 = Left
 *	D1 = Front
 *  D2 = Right
 */
void initIRSenors(void) {
	adc[0] = InitializeADC(PIN_D0);
    adc[1] = InitializeADC(PIN_D1);
    adc[2] = InitializeADC(PIN_D2);
}

/*	Activate pins to run motors (2 pins each) 
 *  Left Side:
 *		Front: E1, E2 
 *		Back:  E4, E5 
 *	Right Side:
 *		Front: A2, A3 
 *		Back:  D6, D7 
 */
void initMotors(void) {
	//left side
	motors[0] = InitializeMotor(PIN_E1, PIN_E2, true, false);
    motors[1] = InitializeMotor(PIN_E4, PIN_E5, true, false);
    //right side
	motors[2] = InitializeMotor(PIN_A2, PIN_A3, true, false);
    motors[3] = InitializeMotor(PIN_D6, PIN_D7, true, false);
}

//set speed constants
//learn ye ole' English ye' scurvy dogs
float fore = 0.75;
float aft = -0.75;
float adjustValue = 0.25;

void followDatWall(void) {
	float left = ADCRead(adc[0]);
	float front = ADCRead(adc[1]);
	float right = ADCRead(adc[2]);

	while(true) {
		//adjustments for going straight
		while(front > OK_FRONT_DIST) {
			front = ADCRead(adc[1]);
			left = ADCRead(adc[0]);
			right = ADCRead(adc[2]);
			if(left - right > OK_SIDE_DIST) { //too far right
				SetMotor(motors[0], fore - adjustValue);
				SetMotor(motors[1], fore - adjustValue);
				SetMotor(motors[2], fore + adjustValue);
				SetMotor(motors[3], fore + adjustValue);
			} else if (right - left > OK_SIDE_DIST) { //too far left
				SetMotor(motors[0], fore + adjustValue);
				SetMotor(motors[1], fore + adjustValue);
				SetMotor(motors[2], fore - adjustValue);
				SetMotor(motors[3], fore - adjustValue);
			} else { //we're pretty damn straight!
				SetMotor(motors[0], fore);
				SetMotor(motors[1], fore);
				SetMotor(motors[2], fore);
				SetMotor(motors[3], fore);
			}

		//we 'bout to crash byetch
		if(right > left) {
			SetMotor(motors[0], fore);
			SetMotor(motors[1], fore);
			SetMotor(motors[2], aft);
			SetMotor(motors[3], aft);
		} else { //should be turnin' portside me matey
			SetMotor(motors[0], aft);
			SetMotor(motors[1], aft);
			SetMotor(motors[2], fore);
			SetMotor(motors[3], fore);	
			}
		}
	}
}

void rammingSpeed(void)
{
	float portSpeed = 1;
	float starboardSpeed = 1;

	while(true)
	{
		SetMotor(motors[0], portSpeed);
		SetMotor(motors[1], portSpeed);
		SetMotor(motors[2], starboardSpeed);
		SetMotor(motors[3], starboardSpeed);
/*
		if(left - right > OK_SIDE_DIST)
		{
			portSpeed = 0.9;
		}
		else if(right - left > OK_SIDE_DIST)
		{
			starboardSpeed = 0.9;
		}
		else
		{
			portSpeed = starboardSpeed = 1;
		}
*/
	}
}