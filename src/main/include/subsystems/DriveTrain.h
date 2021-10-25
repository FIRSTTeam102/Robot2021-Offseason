/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include <frc/Encoder.h>



class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();
  void stop();
  void move(double left, double right);
  void tankDrive();
  void arcadeDrive();
  void toggleDrive();
  void setDriverJoystick(frc::XboxController* pDriverJoystick){
    mpDriverJoystick = pDriverJoystick;
  };
  bool flipDrive();
  void resetEncs() { mLeftEnc.Reset(); mRightEnc.Reset(); }
  int getLEncs() { return mLeftEnc.Get(); }
  int getREncs() { return mRightEnc.Get(); }
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();



 private:

  frc::XboxController* mpDriverJoystick;

  WPI_TalonSRX mDriveLeft1;
  WPI_TalonSRX mDriveLeft2;
  WPI_TalonSRX mDriveRight1;
  WPI_TalonSRX mDriveRight2;

  frc::Encoder mLeftEnc{8,9};
  frc::Encoder mRightEnc{7,6};

  frc::SpeedControllerGroup mLeft{mDriveLeft1, mDriveLeft2};
  frc::SpeedControllerGroup mRight{mDriveRight1, mDriveRight2};

  frc::DifferentialDrive mDrive{mLeft, mRight};
 
  bool on = false;
  bool inverted = false;


  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
