/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/GetRascals.h"
#include "commands/auto/TurnDegrees.h"
#include "commands/auto/MoveLinear.h"
#include "commands/powercell/RaiseArm.h"
#include "commands/powercell/LowerArm.h"
#include "subsystems/Intake.h"
#include "subsystems/Indexer.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
GetRascals::GetRascals(DriveTrain* pDriveTrain, Intake* pIntake, Indexer* pIndexer) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  printf("GET THOSE RASCALS!!!\n");
  AddCommands(TurnDegrees(pDriveTrain, 28, kSlowSpeed), //Straighten out
  LowerArm(pIntake, pIndexer), //Prepare to intake balls
  MoveLinear(pDriveTrain, 150, -1), //Capture balls into intake area
  RaiseArm(pIntake, pIndexer)); //Raise the arm
}
