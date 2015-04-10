#include "RASDemo.h"
#include "ToshibaMotorDriver.h"
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/pwm.h>

// duty cycles for driving 
float forward = 50;
float left = 50;
float right = 50;
float back = 50;

tBoolean blink_on = true;

// heartbeat
void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
    SetPin(PIN_F2, blink_on);
}
int main(void) {

	CallEvery(blink, 0, 0.5);	

// Initialize PWMs on Toshiba Driver
	TBInit();	
	
// Bringing the robot through its paces	

	TBForward(50, 50);
	Wait(1.5);
	TBForward(100, 100);
	Wait(1.5);

	// gradual slow down
	for (int j = 100; j >= 0; j -= 1) {
		TBForward(j, j);
		Wait(.05);
	}
	
	TBLeft(50, 50);
	Wait(1.0);
	TBLeft(100, 100);
	Wait(1.0);

	TBRight(50, 50);
	Wait(1.0);
	TBRight(100, 100);
	Wait(1.0);
	
	// now slalom
	for (int j = 0; j < 10; j += 1) {
		TBLeft(50, 50);
		Wait(0.5);
		TBRight(50, 50);
		Wait(0.5);
	}
	
	TBBackward(50, 50);
	Wait(1.5);
	TBBackward(100, 100);
	Wait(1.5);
	
	// coast and brake hard
	TBCoast();
	Wait(1.5);
	TBForward(100, 100);
	Wait(1.5);
	TBBrake();
	
	while(1);
}
