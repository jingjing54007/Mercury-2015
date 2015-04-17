#include "RASLib/inc/common.h"
#include "RASLib/inc/motor.h"
#include "RASLib/inc/time.h"
#include "RASLib/inc/pwm.h"
#include "RASLib/inc/servo.h"
#include "PololuHighPowerDriver.h"
#include "WallFollowingHg.h"
#include "BootlegMotorDriver.h"

// duty cycles for driving 
double forward = 50;
double left = 50;
double right = 50;
double back = 50;
double motorSpeed = 0.5;	//default speed = 0.5; fast = 0.75; slow = 0.25

tBoolean blink_on = true;
static tPWM *pwm_left;
static tPWM *pwm_right;

static tServo *handServo;
static tServo *armServo;

// heartbeat
void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}
void grabBall(void)
{
	SetPin(PIN_F2, blink_on);
	SetPin(PIN_F3, !blink_on);

	//Open hand
	SetPin(PIN_F3, blink_on);
	SetPin(PIN_F3, !blink_on);
	SetServo(handServo, 0.2f);
	Wait(1.0);

	lowerArm();
	
	//Close hand
	SetPin(PIN_F3, blink_on);
	SetPin(PIN_F2, !blink_on);
	SetServo(handServo, 0.65f);
	Wait(1.0);

	
	//arm goes up
	SetPin(PIN_F2, blink_on);
	SetPin(PIN_F3, !blink_on);
	raiseArm();

}

void dropBall(void)
{
	//move arm up halfway
	SetPin(PIN_F2, blink_on);
	SetPin(PIN_F3, !blink_on);
	raiseArmPeak();

	//open hand and wait for ball to drop
	SetPin(PIN_F3, blink_on);
	SetPin(PIN_F3, !blink_on);
	SetServo(handServo, 0.2f);
	Wait(3.0);

	//close hand
	SetPin(PIN_F3, blink_on);
	SetPin(PIN_F2, !blink_on);
	SetServo(handServo, 0.65f);
	Wait(2.0);

	//arm goes down
	raiseArm();
}

void manualControl(void)
{
	char input;
	int manual = 1;
	/*
	while(manual)
	{
		scanf("%c", input);
			switch(input) 
				{
				case 'w':
					SetGearMotor(motorSpeed, motorSpeed);
					break;
				case 's':
					SetGearMotor(-motorSpeed, -motorSpeed);
					break;
				case 'a':
					SetGearMotor(-motorSpeed, motorSpeed);
					break;
				case 'd':
					SetGearMotor(motorSpeed, -motorSpeed);
					break;
				case 'p':
					grabBall();
					break;
				case 'o':
					dropBall();
					break;
				case 'ESC':
					manual = 0;
					break;
				case ']':
					motorSpeed = 0.25;
					break;
				case '[':
					motorSpeed = 0.5;
					break;
				default:

					//stop motors
			}
		}*/
}

int main(void) {

	//char input;
	PIDStruct s;
	
	CallEvery(blink, 0, 0.5);
	
	//armServo = InitializeServo(PIN_B2);
	handServo = InitializeServo(PIN_B3);
	InitGearMotor();
	initializeIRSensors();
	initBootlegMotor();

	//grabBall();	
	//Wait(3.0);
	//dropBall();

	//while(1);

	//while(1) __asm("");

	//SetGearMotor(.5, .5);
	//setBootlegMotor(0.7);

	grabBall();
	dropBall();

	while(true)
	{
		//grabBall();

		//float hup = getPosition();
		//Printf("%f \n", (hup));
//		runPID(&s, 0);
		//get input somehow?
//		if(input == 32)		//also needs input to activate sprinting speed
//			manualControl();
		//setBootlegMotor(0.5);
		//Wait(2.0);
		//setBootlegMotor(1.0);
	}

}

