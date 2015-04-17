#include "RASLib/inc/common.h"
#include "RASLib/inc/servo.h"
#include "RASLib/inc/motor.h"
#include "RASLib/inc/pwm.h"
#include "RASLib/inc/adc.h"

tMotor *motor;	//pin D3
tADC *input;	//pin D2

void initBootlegMotor(void)
{
	input = InitializeADC(PIN_D2);
	motor = InitializeServoMotor(PIN_D3, false);
}

//returns number between 0 and 1 for arm's position
float getPosition(void)
{
	float rawPos = ADCRead(input);
	return rawPos;
}

//setting from 0 to 1; 1 = fully retracted, 0 = fully extended
void setBootlegMotor(float setting)
{
	//SetMotor(motor, -0.2);
	float diff = setting - getPosition();
	while(diff < -0.05 || diff > 0.05)
	{
		SetMotor(motor, diff);
		diff =  setting - getPosition();
	}
	SetMotor(motor, 0);
}

void lowerArm(void)
{
	setBootlegMotor(0.25);
	Wait(2.0);
}

void raiseArm(void)
{
	setBootlegMotor(1.0);
	Wait(2.0);
}

void raiseArmPeak(void)
{
	setBootlegMotor(0.71);
	Wait(2.0);
}