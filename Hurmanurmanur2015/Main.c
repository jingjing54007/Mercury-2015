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

void grabBall(void)
{
	//hand servo info
	//0.55 = closed
	//0.2 = open

	int i;

	SetPin(PIN_F2, blink_on);
	SetPin(PIN_F3, !blink_on);

	//set arm servo down after initialization
	for(i = 50; i>=10; i -= 1)
	{
		SetServo(armServo, (float) i * 0.01);
		Wait(0.1);
	}
	Wait(2.0);

	//Open hand
	SetPin(PIN_F3, blink_on);
	SetPin(PIN_F3, !blink_on);
	SetServo(handServo, 0.2f);
	Wait(2.0);

	//arm goes up
	SetPin(PIN_F2, blink_on);
	SetPin(PIN_F3, !blink_on);
	for(i = 10; i<=100; i += 1)
	{
		SetServo(armServo, (float) i * 0.01);
		Wait(0.05);
	}
	Wait(2.0);

	//Close hand
	SetPin(PIN_F3, blink_on);
	SetPin(PIN_F2, !blink_on);
	SetServo(handServo, 0.70f);
	Wait(2.0);

	
	//arm goes down
	SetPin(PIN_F2, blink_on);
	SetPin(PIN_F3, !blink_on);
	SetServo(armServo, 0.1);

	//SetServo(armServo, 0.0f);
	//SetPin(PIN_F2, blink_on);
	//SetPin(PIN_F3, !blink_on);
	//Wait(2.0);

}

void dropBall(void)
{
	int i;

	//move arm up halfway
	SetPin(PIN_F2, blink_on);
	SetPin(PIN_F3, !blink_on);
	for(i = 10; i<=55; i += 1)
	{
		SetServo(armServo, (float) i * 0.01);
		Wait(0.05);
	}
	Wait(2.0);	

	//open hand
	SetPin(PIN_F3, blink_on);
	SetPin(PIN_F3, !blink_on);
	SetServo(handServo, 0.2f);
	Wait(5.0);

	//close hand
	SetPin(PIN_F3, blink_on);
	SetPin(PIN_F2, !blink_on);
	SetServo(handServo, 0.70f);
	Wait(2.0);

	//arm goes down
	SetPin(PIN_F2, blink_on);
	SetPin(PIN_F3, !blink_on);
	for(i = 55; i >= 10; i -= 1)
	{
		SetServo(armServo, (float) i * 0.01);
		Wait(0.05);
	}
	SetServo(armServo, 0.1);
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

	grabBall();	
	Wait(3.0);
	dropBall();

	//TBForward(50, 50, pwm_left, pwm_right);
	
	//while(1);

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

