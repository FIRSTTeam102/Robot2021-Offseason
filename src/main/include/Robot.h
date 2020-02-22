/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/SendableCameraWrapper.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "RobotContainer.h"
#include "subsystems/Intake.h"
#include "subsystems/Indexer.h"
#include "subsystems/Shooter.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

  RobotContainer* GetRobotContainer(){
    return &m_container;
  };

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc2::Command* m_autonomousCommand = nullptr;

  RobotContainer m_container;
  frc::SendableChooser<int> mAutoPos;
  frc::SendableChooser<bool> mAutoShoot;
  frc::SendableChooser<int> mAutoMovement;
  frc::SendableChooser<bool> mAutoShoot2;
  frc::SendableChooser<int> mIntake;
  frc::SendableChooser<int> mIndexer;
  frc::SendableChooser<int> mShooter;

 // frc::SendableHelper<SendableCameraWrapper> mCameraWrap;
};
