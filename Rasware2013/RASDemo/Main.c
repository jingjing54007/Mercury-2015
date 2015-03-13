#include "RASDemo.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>

tBoolean blink_on = true;

void blink(void)
{
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}


int main(void)
{
    	CallEvery(blink, 0, 0.5);
	SetPin(PIN_B4,1);
	SetPin(PIN_B5,0);
	SetPin(PIN_E4,1);
	SetPin(PIN_E5,0);
	while(1);
}

