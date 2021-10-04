/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include <ctre/Phoenix.h>
#include <frc/Relay.h>
#include "Constants.h"


class Intake : public frc2::SubsystemBase {
 public:
  Intake();

  void lowerIntakeArm();
  void raiseIntakeArm();
  void stopIntakeArm();
  void startRollers();
  void startReverseRollers();
  void stopRollers();
  // bool isArmUp() { return !mUpSensor.Get(); }
  // bool isArmDown() { return !mDownSensor.Get(); }

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  frc::Relay mIntakeArmMotor;
  frc::Relay mIntakeRollerMotor;
  // frc::DigitalInput mUpSensor;
  // frc::DigitalInput mDownSensor;
};
