#include "RASLib/inc/common.h"
#include "RASLib/inc/gpio.h"
#include "RASLib/inc/time.h"
#include "RASLib/inc/motor.h"
#include "RASLib/inc/adc.h"
#include "PololuHighPowerDriver.h"
#include <stdlib.h>
#include "WallFollowingHg.h"

tMotor *left_motors, *right_motors;	
//tADC *adc1, *adc2, *adc3;	//use for IR sensors
tBoolean LED = true;

void blinkLED(void) {		//heartbeat
	SetPin(PIN_F2, LED);
	LED = !LED;
}

void initializeIRSensors(void) {
	adc1 = InitializeADC(PIN_D0);
	adc2 = InitializeADC(PIN_D1);
	//adc3 = InitializeADC(PIN_D2);
}
/* Below defines values read from the IR sensors on the robot 
float lVal = ADCRead(adc1) * 1000;	//left IR
float fVal = ADCRead(adc2) * 1000;	//front IR
float rVal = ADCRead(adc3) * 1000;	//right IR
*/



#define PIDP (0.00003)	//alter constant to fit things
#define PIDD (0.00000)
#define PIDI (0.000000)
#define MAX_MOTOR (0.5)
#define MIN_MOTOR (-0.5)

void runPID(PIDStruct* s, int goalDeltaTicks) {
	signed long ticks = ADCRead(s->adc1) - ADCRead(s->adc2); //left IR measurement - right IR measurement -- CONVERT THIS FOR REAL-WORLD MEASUREMENTS
	signed long deltaTicks = ticks - s->prevTicks;

	float err = goalDeltaTicks - deltaTicks;
	s->accumErr += err;

	float pidOutput = err*PIDP + (err - s->prevErr)*PIDD + s->accumErr*PIDI;
	float motorCommandLeft = s->prevCommandLeft + pidOutput;
	float motorCommandRight = s->prevCommandRight - pidOutput;

	if (motorCommandLeft > MAX_MOTOR) motorCommandLeft = MAX_MOTOR;
	if (motorCommandLeft < MIN_MOTOR) motorCommandLeft = MIN_MOTOR;
	if (motorCommandRight > MAX_MOTOR) motorCommandRight = MAX_MOTOR;
	if (motorCommandRight < MIN_MOTOR) motorCommandRight = MIN_MOTOR;
	
	s->prevTicks = ticks;
	s->prevErr = err;
	s->prevCommandLeft = motorCommandLeft;
	s->prevCommandRight = motorCommandRight;
	s->deltaTicks = deltaTicks;

	SetGearMotor(motorCommandLeft, motorCommandRight);
}