/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ToggleLift.h"

ToggleLift::ToggleLift(Pneumatics *pPneumatics) : mpPneumatics{pPneumatics}
{
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pPneumatics);
}

// Called when the command is initially scheduled.
void ToggleLift::Initialize()
{
	mpPneumatics->toggleLift();
}

// Called repeatedly when this Command is scheduled to run
void ToggleLift::Execute() {}

// Called once the command ends or is interrupted.
void ToggleLift::End(bool interrupted) {}

// Returns true when the command should end.
bool ToggleLift::IsFinished() { return true; }