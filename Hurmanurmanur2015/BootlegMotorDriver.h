#include "RASLib/inc/common.h"
#include "RASLib/inc/servo.h"
#include "RASLib/inc/motor.h"
#include "RASLib/inc/pwm.h"
#include "RASLib/inc/adc.h"

void initBootlegMotor(void);
float getPosition(void);
void setBootlegMotor(float setting);
void raiseArm(void);
void lowerArm(void);
void raiseArmPeak(void);