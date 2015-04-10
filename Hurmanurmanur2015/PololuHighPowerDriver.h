//*****************************************************************************
// Written for Pololu High-Power Motor Driver 18v15 
// https://www.pololu.com/product/755
//
// PWM	DIR		OUTA	OUTB	Operation
// H		L			L			H			Forward
// H		H			H			L			Backward
// L		X			L			L			Brake
//*****************************************************************************

#include "RASDemo.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/pwm.h>

void InitGearMotor(void);

void SetGearMotor(float left, float right);

void StopGearMotor(void);

