#include "RASDemo.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/pwm.h>

void TBForward(float Lspeed, float Rspeed, tPWM *left, tPWM *right);

void TBLeft(float speed);

void TBRight(float speed);

void TBBackward(float speed);