#include "RASDemo.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>

static tMotor *Motors[4];
static tBoolean initialized = false;
tBoolean blink_on = true;

void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}

void initMotors(void)
{
	 if (!initialized)
	 {
		 initialized = true;
	         Motors[0] = InitializeTLEMotor(PIN_B4, PIN_B5, true, false);	        
		 Motors[1] = InitializeTLEMotor(PIN_E4, PIN_E5, true, false);
	 }
}

float forward = 1.00;
float back = -0.75;
float adjustValue = 0.25; //why do we have this?
int main(void)
{
    CallEvery(blink, 0, 0.5);
   // initMotors();

//	SetMotor(Motors[0], forward);
//	SetMotor(Motors[1], forward);
	SetPin(PIN_B4,1);
	SetPin(PIN_B5,0);
	SetPin(PIN_E4,1);
	SetPin(PIN_E5,0);
	while(1);
}

