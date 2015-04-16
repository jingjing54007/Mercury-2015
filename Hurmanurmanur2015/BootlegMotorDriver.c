#include "RASLib/inc/common.h"
#include "RASLib/inc/servo.h"
#include "RASLib/inc/servomotor.h"
#include "RASLib/inc/pwm.h"
#include "RASLib/inc/adc.h"

tServoMotor *motor;	//pin D3
tADC *input;	//pin D2

void initBootlegMotor(void)
{
	input = InitializeADC(PIN_D2);
	motor = InitializeServoMotor(PIN_D3, false);
}

//returns number between 0 and 1 for arm's position
float getPosition(void)
{
	float rawPos = ADCRead(PIN_D2);
	return (rawPos*2)-1;
}

//setting from 0 to 1; 1 = fully retracted, 0 = fully extended
void setBootlegMotor(float setting)
{
	float diff = setting - getPosition();
	while(diff > setting + 0.05 || diff < setting - 0.05)
	{
		SetServoMotor(motor, diff);
		diff = setting - getPosition();
	}
}