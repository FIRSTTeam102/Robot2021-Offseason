/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/powercell/IndexPowerCell.h"

IndexPowerCell::IndexPowerCell(Indexer* pIndexer): mpIndexer{pIndexer} {
  // Use addRequirements() here to declare subsystem dependencies.
  //AddRequirements(Indexer* pIndexer);
}

// Called when the command is initially scheduled.
void IndexPowerCell::Initialize() {
  printf("Indexing power cells\n");
  hasIndexed = false;
}

// Called repeatedly when this Command is scheduled to run
void IndexPowerCell::Execute() {
  printf("Power cell at intake? %d       Enabled? %d      Full? %d\n", mpIndexer->isPowerCellAtIntake(), mpIndexer->isEnabled(), mpIndexer->isFullIndexer());
  if (!mpIndexer->isFullIndexer() && mpIndexer->isPowerCellAtIntake() && mpIndexer->isEnabled()){
    printf("Begin indexing motor\n");
    mpIndexer->moveUpIndexer();
    hasIndexed = true;
  }
  //if (hasIndexed == true && (mpIndexer->isFullIndexer() || (mpIndexer->isPowerCellAtBottom() && !mpIndexer->isPowerCellAtIntake()))) {
  if ((hasIndexed == true && mpIndexer->isPowerCellAtBottom()) || mpIndexer->isFullIndexer()) {
    mpIndexer->stopIndexer();
    printf("Stopping indexer\n");
    hasIndexed = false;
  }
}

// Called once the command ends or is interrupted.
void IndexPowerCell::End(bool interrupted) {
  printf("Stopping indexing!!!!!!!!!!!!!!!!!!!!!!!!");
  mpIndexer->stopIndexer();
}

// Returns true when the command should end.
bool IndexPowerCell::IsFinished() {
  /*if (mpIndexer->isFullIndexer()){ 
    printf("indexer full\n");
    return true;
  }
  if (hasIndexed == false) {
    printf("Has not run yet\n");
    return false;
  }
  if (mpIndexer->isPowerCellAtBottom() && !mpIndexer->isPowerCellAtIntake()){
    printf("indexer - pc at bottom but not at intake - done\n");
    return true;
  }
  printf("index pc - not finished\n");
  return(false);*/
  return false;
}