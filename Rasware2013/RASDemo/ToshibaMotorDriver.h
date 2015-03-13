#include "RASDemo.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/pwm.h>

void TBInit(void);

void TBForward(float left_speed, float right_speed);

void TBLeft(float left_speed, float right_speed);

void TBRight(float left_speed, float right_speed);

void TBBackward(float left_speed, float right_speed);

void TBBrake(void);

void TBCoast(void);
