#include "RASLib/inc/common.h"
#include "RASLib/inc/motor.h"
#include "RASLib/inc/time.h"
#include "RASLib/inc/pwm.h"
#include "RASLib/inc/servo.h"
#include "ToshibaMotorDriver.h"

// duty cycles for driving 
float forward = 50;
float left = 50;
float right = 50;
float back = 50;

tBoolean blink_on = true;
static tPWM *pwm_left;
static tPWM *pwm_right;

static tServo *armServo;
static tServo *handServo;

// heartbeat
void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}

void moveArm(void)
{
	//hand servo info
	//0.55 = closed
	//0.2 = open

	SetServo(armServo, 0.75f);
	SetPin(PIN_F2, blink_on);
	SetPin(PIN_F3, !blink_on);
	Wait(2.0);

	SetServo(handServo, 0.2f);
	SetPin(PIN_F3, blink_on);
	SetPin(PIN_F3, !blink_on);
	Wait(2.0);

	SetServo(armServo, 0.1f);
	SetPin(PIN_F2, blink_on);
	SetPin(PIN_F3, !blink_on);
	Wait(2.0);

	SetServo(handServo, 0.55f);
	SetPin(PIN_F3, blink_on);
	SetPin(PIN_F2, !blink_on);
	Wait(2.0);

	//SetServo(armServo, 0.0f);
	//SetPin(PIN_F2, blink_on);
	//SetPin(PIN_F3, !blink_on);
	//Wait(2.0);
}

int main(void) {

	//CallEvery(blink, 0, 0.5);
	
// This works, driving forward only
// ** PWM set to high **
//	SetPin(PIN_B4,1);
//	SetPin(PIN_B5,0);
//	SetPin(PIN_E4,1);
//	SetPin(PIN_E5,0);

// Testing Toshiba Driver	
	
	//pwm_left = InitializePWM(PIN_B6, 1000);
	//pwm_right = InitializePWM(PIN_E6, 1000);
	armServo = InitializeServo(PIN_B2);
	handServo = InitializeServo(PIN_B3);
	
	
	//TBForward(50, 50, pwm_left, pwm_right);
	
	//while(1);

	moveArm();
	//while(1) __asm("");

/*
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
*/
}

