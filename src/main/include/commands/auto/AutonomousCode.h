/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc/DriverStation.h>

#include "commands/auto/BackUp.h"
#include "commands/auto/GetRascals.h"
#include "commands/powercell/AimShooter.h"
#include "commands/powercell/ShootPowerCells.h"
#include "commands/Delay.h"

#include "subsystems/DriveTrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Indexer.h"
#include "subsystems/Shooter.h"

class AutonomousCode
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                  AutonomousCode> {
 public:
  AutonomousCode(DriveTrain* pDriveTrain, Intake* pIntake, Indexer* pIndexer, Shooter* pShooter, int slot, bool shoot, int move, bool shoot2);
  //void setAutoConfig(int slot, bool shoot, int move, bool shoot2);
  //void Initialize() override;
 private:
  DriveTrain* mpDriveTrain;
  Intake* mpIntake;
  Indexer* mpIndexer;
  Shooter* mpShooter;
  int mSlot;
  bool mShoot;
  int mMove;
  bool mShoot2;
  float shootSpeed;
};
