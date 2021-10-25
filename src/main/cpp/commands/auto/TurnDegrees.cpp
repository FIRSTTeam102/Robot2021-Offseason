/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/TurnDegrees.h"

TurnDegrees::TurnDegrees(DriveTrain* pDriveTrain, double degrees, double speed): mpDriveTrain{pDriveTrain}, mDegrees{degrees}, mSpeed{speed} {
  // Use addRequirements() here to declare subsystem dependencies.
  //Degrees positive for right (clockwise), negative for left (counterclockwise)
  AddRequirements(pDriveTrain);
  mTarget = (int) (degrees*23.0/6.0);
  printf("Target: %d\n", mTarget);
}

// Called when the command is initially scheduled.
void TurnDegrees::Initialize() {
  mpDriveTrain->resetEncs();
}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute() {
  printf("Target: %d\n", mTarget);
  if (mDegrees > 0) {
    mpDriveTrain->move(mSpeed, -mSpeed);
  }
  else {
    mpDriveTrain->move(-mSpeed, mSpeed);
  }
}

// Called once the command ends or is interrupted.
void TurnDegrees::End(bool interrupted) {
  mpDriveTrain->stop();
}

// Returns true when the command should end.
bool TurnDegrees::IsFinished() {
  if (mDegrees > 0) {
    return (mpDriveTrain->getREncs() <= -mTarget);
  }
  else {
    return (mpDriveTrain->getREncs() >= -mTarget);
  }
}
