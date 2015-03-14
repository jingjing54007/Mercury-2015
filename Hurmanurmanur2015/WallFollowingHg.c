#include "RASLib/inc/common.h"
#include "RASLib/inc/gpio.h"
#include "RASLib/inc/time.h"
#include "RASLib/inc/motor.h"
#include "RASLib/inc/adc.h"
#include <stdlib.h>

tMotor *left_motors, *right_motors;	
tADC *adc1, *adc2, *adc3;	//use for IR sensors
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

struct PIDStruct {		//struct tailored for one set of motors
	tMotor* motorL;
	tMotor* motorR;
	tADC*	adc1;		//left IR
	tADC*	adc2;		//right IR		
	float prevCommand;
	signed long prevTicks;	//previous distance to wall
	float prevErr;
	float accumErr;	
	signed long deltaTicks;	//distance to the wall
} typedef PIDStruct;


#define PIDP (0.00003)	//alter constant to fit things
#define PIDD (0.00000)
#define PIDI (0.000000)
#define MAX_MOTOR (0.5)
#define MIN_MOTOR (-0.5)

void runPID(PIDStruct* s, int goalDeltaTicks) {
	signed long ticks = ADCRead(s->adc1) - ADCRead(s->adc2); //left IR measurement - right IR measurement
	signed long deltaTicks = ticks - s->prevTicks;

	float err = goalDeltaTicks - deltaTicks;
	s->accumErr += err;

	float pidOutput = err*PIDP + (err - s->prevErr)*PIDD + s->accumErr*PIDI;
	float motorCommand = s->prevCommand + pidOutput;

	if (motorCommand > MAX_MOTOR) motorCommand = MAX_MOTOR;
	if (motorCommand < MIN_MOTOR) motorCommand = MIN_MOTOR;
	
	s->prevTicks = ticks;
	s->prevErr = err;
	s->prevCommand = motorCommand;
	s->deltaTicks = deltaTicks;

	setMotor(s->motorL, -motorCommand);
	setMotor(s->motorR, motorCommand);
}
