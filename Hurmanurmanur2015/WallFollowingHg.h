#include "RASLib/inc/common.h"
#include "RASLib/inc/gpio.h"
#include "RASLib/inc/time.h"
#include "RASLib/inc/motor.h"
#include "RASLib/inc/adc.h"
#include "PololuHighPowerDriver.h"
#include <stdlib.h>

void blinkLED(void);	//we don't really need this probably
void initializeIRSensors(void);
void runPID(PIDStruct* s, int goalDeltaTicks);