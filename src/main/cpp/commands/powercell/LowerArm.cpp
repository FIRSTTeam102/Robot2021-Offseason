/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*
   Lower the Intake Mechanisms arm, so it can start collecting power cells
*/
#include "commands/powercell/LowerArm.h"
#include "subsystems/Intake.h"
#include "RobotContainer.h"
#include "Robot.h"

LowerArm::LowerArm(Intake* pIntake, Indexer* pIndexer): mpIntake{pIntake}, mpIndexer{pIndexer} {
  // Use addRequirements() here to declare subsystem dependencies.
    AddRequirements(pIntake);
}

// LowerArm - initialize Called when the command is initially scheduled.
//    start the intakeArmRollers moving forward and lower the intake arm
//    so that power cells can be moved toward the indexer
void LowerArm::Initialize() {
   mpIndexer->enable();
   mpIntake->startRollers();
   counter = 0;
}

// LowerArm - Execute - Called repeatedly when this Command is scheduled to run
//    when the intake arm hits the fully down position, stop the Intake Arm motors
//    from moving, but keep the intake arm rollers (which were started in initialize)
//    running to take in power cells.
void LowerArm::Execute() {
   mpIntake->lowerIntakeArm();
   counter++;
}

// Called once the command ends or is interrupted/cancelled.
void LowerArm::End(bool interrupted) {
   mpIntake->stopIntakeArm();
}

// LowerArm - is finished - Returns true when the command should end.
//   NOTE: LowerArm is expected to be executed while a button is pressed.
//   when the button is released, the command will be cancelled, this
//   command is not expected to finish on it's own.
bool LowerArm::IsFinished() {
   return counter >= 25;
}