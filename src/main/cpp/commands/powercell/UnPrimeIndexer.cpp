/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/powercell/UnPrimeIndexer.h"

UnPrimeIndexer::UnPrimeIndexer(Indexer* pIndexer): mpIndexer{pIndexer} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pIndexer);
}

// Called when the command is initially scheduled.
void UnPrimeIndexer::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void UnPrimeIndexer::Execute() {
  mpIndexer->movePowerCellsToBottom();
}

// Called once the command ends or is interrupted.
void UnPrimeIndexer::End(bool interrupted) {
  mpIndexer->stopIndexer();
}

// Returns true when the command should end.
bool UnPrimeIndexer::IsFinished() {
  return (mpIndexer->isPowerCellAtBottom() || mpIndexer->isEmptyIndexer());
}
