#ifndef WALLFOLLOWINGHG
#define WALLFOLLOWINGHG

#include "RASLib/inc/common.h"
#include "RASLib/inc/gpio.h"
#include "RASLib/inc/time.h"
#include "RASLib/inc/motor.h"
#include "RASLib/inc/adc.h"
#include "PololuHighPowerDriver.h"
#include <stdlib.h>

extern tADC *adc1, *adc2, *adc3;	//use for IR sensors

struct PIDStruct {		//struct tailored for one set of motors
	tADC*	adc1;		//left IR
	tADC*	adc2;		//right IR		
	float prevCommandRight;
	float prevCommandLeft;
	signed long prevTicks;	//previous distance to wall
	float prevErr;
	float accumErr;	
	signed long deltaTicks;	//distance to the wall
} typedef PIDStruct;

void blinkLED(void);	//we don't really need this probably
void initializeIRSensors(void);
void runPID(PIDStruct* s, int goalDeltaTicks);

#endif
