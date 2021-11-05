/*----------------------------------------------------------------------------* /
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/limelight/LMYawToTarget.h"

LMYawToTarget::LMYawToTarget(LM *pLM, DriveTrain *pDriveTrain) : mpLM{pLM}, mpDriveTrain{pDriveTrain}
{
	// Use addRequirements() here to declare subsystem dependencies.
	// AddRequirements(pLM);
	AddRequirements(pDriveTrain);
}

// Called when the command is initially scheduled.
void LMYawToTarget::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void LMYawToTarget::Execute()
{
	printf("adjusting w/ limelight \n");
	mpDriveTrain->move(mpLM->left_command, mpLM->right_command);
}

// Called once the command ends or is interrupted.
void LMYawToTarget::End(bool interrupted)
{
	mpDriveTrain->stop();
}

// Returns true when the command should end.
bool LMYawToTarget::IsFinished()
{
	return mpLM->CheckR();
}