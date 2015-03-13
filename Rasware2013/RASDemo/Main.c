#include "RASDemo.h"
#include "ToshibaMotorDriver.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/pwm.h>

// duty cycles for driving 
float forward = 50;
float left = 50;
float right = 50;
float back = 50;

tBoolean blink_on = true;
static tPWM *pwm_left;
static tPWM *pwm_right;

// heartbeat
void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}

int main(void) {

	CallEvery(blink, 0, 0.5);
	
// This works, driving forward only
// ** PWM set to high **
//	SetPin(PIN_B4,1);
//	SetPin(PIN_B5,0);
//	SetPin(PIN_E4,1);
//	SetPin(PIN_E5,0);

// Testing Toshiba Driver	
	
	//pwm_left = InitializePWM(PIN_B0, 1000);
	//pwm_right = InitializePWM(PIN_B1, 1000);
	
	//TBForward(50, 50, pwm_left, pwm_right);
	
	//while(1);

	char input;

	while(true) {
		scanf("%c", input);
		switch(input) {
			case 'w':
				//make arm go up

				break;
			case 's':
				//make arm go down

				break;
			default:
				//arm does nothing

		}
	}
}

