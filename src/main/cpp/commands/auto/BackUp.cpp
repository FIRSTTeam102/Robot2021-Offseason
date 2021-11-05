/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Autonomous stage 3
#include "commands/auto/BackUp.h"

BackUp::BackUp(DriveTrain* pDriveTrain, double distance):  mpDriveTrain(pDriveTrain), mDistance(distance) {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(mpDriveTrain);
}

// Called when the command is initially scheduled.
void BackUp::Initialize() {
	mpDriveTrain->resetEncs();
}

// Called repeatedly when this Command is scheduled to run
void BackUp::Execute() {
	ticksPassed++;
	mpDriveTrain->move(-0.5, -0.5);
	printf("Backing up, gone %i\n", mpDriveTrain->getREncs());
}

// Called once the command ends or is interrupted.
void BackUp::End(bool interrupted) {
	mpDriveTrain->stop();
}

// Returns true when the command should end.
bool BackUp::IsFinished() {
	return mpDriveTrain->getREncDist() >= mDistance; // inches
}
