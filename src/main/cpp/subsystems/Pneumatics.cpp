/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Pneumatics.h"

Pneumatics::Pneumatics() {}

void Pneumatics::toggleLift()
{
	mEnabled = !mEnabled;
	mLift.Set(mEnabled);
}

// This method will be called once per scheduler run
void Pneumatics::Periodic() {}