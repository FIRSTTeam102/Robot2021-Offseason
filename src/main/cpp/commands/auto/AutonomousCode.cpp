/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutonomousCode.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html

AutonomousCode::AutonomousCode(DriveTrain* pDriveTrain, Intake* pIntake, Indexer* pIndexer, Shooter* pShooter, LM* pLimelight, int slot, bool shoot, int move, bool shoot2): mpDriveTrain{pDriveTrain}, mpIntake{pIntake}, mpIndexer{pIndexer}, mpShooter{pShooter}, mpLimelight{pLimelight} {printf("Running auto\n");
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  pDriveTrain->stop();
  if (shoot) { //Shoot initial cells
    printf("balls balls balls balls balls\n");
    AddCommands(LMYawToTarget(mpLimelight, mpDriveTrain), LMYawToTarget(mpLimelight, mpDriveTrain));
    AddCommands(AimShooter(mpShooter, ShooterConstants::kFastSpeed), Delay(75));
    AddCommands(ShootPowerCells(mpIndexer, mpShooter, true));
  }
  //if (mShoot && mSlot == 2 && mMove == 1) { //Shot old balls, near trench, going to pick up trench balls
  if (slot == 2 && move == 1) { //Not necessarily shot old balls, near trench, going to pick up trench balls
    printf("Going to trench\n");
    AddCommands(GetRascals(mpDriveTrain, mpIntake, mpIndexer));
    if (shoot2) { //Shoot again
      printf("Shooting from trench\n");
      AddCommands(TurnDegrees(mpDriveTrain, -11.5, ShooterConstants::kSlowSpeed), AimShooter(mpShooter, ShooterConstants::kMedSpeed), ShootPowerCells(mpIndexer, mpShooter));
    }
  }
  else if (move == 2) { //Back up the whole time 
    printf("Backing up\n");
    AddCommands(BackUp(mpDriveTrain));
  }
  else { //Wait until very end to back up
    printf("Waiting\n");
    if (frc::DriverStation::GetMatchTime() < 1.5) {
      printf("Backing up\n");
      AddCommands(BackUp(mpDriveTrain));
    }
  }
}

/*void AutonomousCode::Initialize() {
  printf("Running auto\n");
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  if (mSlot == 2 || mSlot == 3) {
    shootSpeed = kMedAuto;
  }
  else {
    shootSpeed = kSlowAuto;
  }
  if (mShoot) { //Shoot initial cells
    printf("Shooting\n");
    AddCommands(AimShooter(mpShooter, shootSpeed), ShootPowerCells(mpIndexer, mpShooter));
  }
  //if (mShoot && mSlot == 2 && mMove == 1) { //Shot old balls, near trench, going to pick up trench balls
  if (mSlot == 2 && mMove == 1) { //Not necessarily shot old balls, near trench, going to pick up trench balls
    printf("Going to trench\n");
    //AddCommands(GetRascals(mpDriveTrain, mpIntake));
    if (mShoot2) { //Shoot again
      printf("Shooting from trench\n");
      AddCommands(TurnDegrees(mpDriveTrain, -11.5), AimShooter(mpShooter, kFastAuto), ShootPowerCells(mpIndexer, mpShooter));
    }
  }
  else if (mMove == 2) { //Back up the whole time
    printf("Backing up\n");
    AddCommands(BackUp(mpDriveTrain));
  }
  else { //Wait until very end to back up
    printf("Waiting\n");
    if (frc::DriverStation::GetInstance().GetMatchTime() < 1.5) {
      printf("Backing up\n");
      AddCommands(BackUp(mpDriveTrain));
    }
  }
}*/

/*void AutonomousCode::setAutoConfig(int slot, bool shoot, int move, bool shoot2) {
  mSlot = slot;
  mShoot = shoot;
  mMove = move;
  mShoot2 = shoot2;
  printf("Auto config completed: %d, %d, %d, %d\n", mSlot, mShoot, mMove, mShoot2);
}*/