//*****************************************************************************
//
// TOSHIBA TB66215FNG DRIVER
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE AUTHORS OF THIS FILE
// SHALL NOT, UNDER ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
// OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
//
// Written by: 
// The student branch of the 
// IEEE - Robotics and Automation Society 
// at the University of Texas at Austin
//
// Website: ras.ece.utexas.edu
// Contact: ut.ieee.ras@gmail.com
//
//*****************************************************************************

#include "RASLib/inc/common.h"
#include "RASLib/inc/motor.h"
#include "RASLib/inc/pwm.h"

void TBInit(void);

void TBForward(float left_speed, float right_speed);

void TBLeft(float left_speed, float right_speed);

void TBRight(float left_speed, float right_speed);

void TBBackward(float left_speed, float right_speed);

void TBBrake(void);

void TBCoast(void);
