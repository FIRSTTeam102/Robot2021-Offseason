/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//Autonomous stage 3
#include "commands/auto/BackUp.h"

BackUp::BackUp(DriveTrain* pTankDrive):  mpTankDrive(pTankDrive){
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pTankDrive);
	//ticksPassed = 0;
}

// Called when the command is initially scheduled.
void BackUp::Initialize() {
	ticksPassed = 0;
}

// Called repeatedly when this Command is scheduled to run
void BackUp::Execute() {
	ticksPassed++;
	mpTankDrive->move(-0.5, -0.5);
}

// Called once the command ends or is interrupted.
void BackUp::End(bool interrupted) {
	mpTankDrive->stop();
}

// Returns true when the command should end.
bool BackUp::IsFinished() {
	return (ticksPassed >= 200); //Drives robot backwards for 200 ticks. 200 in this case might need to be changed if the robot does not drive far enough or drives too far
}
