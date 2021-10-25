/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/shuffleboard/Shuffleboard.h>
#include "commands/powercell/PrepShooting.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
PrepShooting::PrepShooting(Indexer* pIndexer, Shooter* pShooter, float shooterSpeed) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

  AddCommands(AimShooter(pShooter, shooterSpeed)/*, PrimeIndexer(pIndexer)*/);

  //update the shuffle board driver info: Fly Wheel Speed
  std::string shootRange = "";
  if (shooterSpeed == kSlowSpeed) { shootRange = "Close";} 
  else if (shooterSpeed == kMedSpeed) {shootRange = "Medium";}
  else if (shooterSpeed == kFastSpeed) {shootRange = "Far";}
  else shootRange = "Unknown";

  nt::NetworkTableInstance ntInst = nt::NetworkTableInstance::GetDefault();
  auto shuffleTable = ntInst.GetTable("Shuffleboard/Drive Info");
  nt::NetworkTableEntry shootRangeEntry = shuffleTable->GetEntry("Fly wheel Speed");
  shootRangeEntry.SetString(shootRange);

}
