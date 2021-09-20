/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*
   Stop the intake mechanisms rollers and raise the arm
*/
#include "commands/powercell/RaiseArm.h"
#include "subsystems/Intake.h"

RaiseArm::RaiseArm(Intake* pIntake, Indexer* pIndexer): mpIntake{pIntake}, mpIndexer{pIndexer} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pIntake);
}

// RaiseArm Initialize: Called when the command is initially scheduled.
//   stop the intake arm rollers and start to raise the intake arm
void RaiseArm::Initialize() {
  mpIntake->stopRollers();
  mpIndexer->disable();
  counter = 0;
}
  
// RaiseArm Execute: Called repeatedly when this Command is scheduled to run
//   continue to raise the intake arm until it reaches the fully raised position
void RaiseArm::Execute() {
  mpIntake->raiseIntakeArm();
  counter++;
}

// RaiseArm: Called once the command ends or is interrupted.
//   if raise arm is cancelled before the arm is all the way up
//   it would mean lower arm was requested, in which case we want
//   to stop the arm motors (as opposed to sudden change of direction)
void RaiseArm::End(bool interrupted) {
  mpIntake->stopIntakeArm();
}

// RaiseArm IsFinished - Returns true when the command should end.
bool RaiseArm::IsFinished() { 
  return counter >= 25;
}
