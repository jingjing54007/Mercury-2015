#include "RASDemo.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>

static tMotor *Motors[4];
static tBoolean initialized = false;

void initMotors(void)
{
	 if (!initialized)
	 {
		 initialized = true;
	         Motors[0] = InitializeTLEMotor(PIN_B4, PIN_B5, true, false);	        
		 Motors[1] = InitializeTLEMotor(PIN_E4, PIN_E5, true, false);
	 }
}

float forward = 0.75;
float back = -0.75;
float adjustValue = 0.25; //why do we have this?
int main(void)
{
    initMotors();
	SetMotor(Motors[0], forward);
	SetMotor(Motors[1], forward);
}

