/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/powercell/IndexSingleCell.h"

IndexSingleCell::IndexSingleCell(Indexer* pIndexer) : mpIndexer{pIndexer} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pIndexer);
}

// Called when the command is initially scheduled.
void IndexSingleCell::Initialize() {
	timer = 0;
	mpIndexer->moveUpIndexer();
}

// Called repeatedly when this Command is scheduled to run
void IndexSingleCell::Execute() {
	/*if (mpIndexer->isPowerCellAtTop()) {
		printf("Cell is already at top of indexer, aborting!\n");
		End(false);
		return;
	}*/
	timer++;
	printf("Indexing single cell\n");
}

// Called once the command ends or is interrupted.
void IndexSingleCell::End(bool interrupted) {
	mpIndexer->stopIndexer();
	mpIndexer->addPowerCell();
}

// Returns true when the command should end.
bool IndexSingleCell::IsFinished() { 
	return (timer >= 9);
}