/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Button.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <cameraserver/CameraServer.h>

#include "Constants.h"

#include "subsystems/DriveTrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Indexer.h"
#include "subsystems/Shooter.h"
#include "subsystems/ControlPanelManipulator.h"
#include "subsystems/Lights.h"
// #include "subsystems/Pneumatics.h"

#include "commands/drive/DriveWithXbox.h"
#include "commands/drive/SlowTurn.h"
#include "commands/drive/FlipDrive.h"
#include "commands/powercell/BallJam.h"
#include "commands/powercell/IndexPowerCell.h"
#include "commands/powercell/LowerArm.h"
#include "commands/powercell/PrepShooting.h"
#include "commands/powercell/RaiseArm.h"
#include "commands/powercell/Reset.h"
#include "commands/powercell/ShootPowerCells.h"
#include "commands/powercell/StopShootingPowerCells.h"
#include "commands/controlpanel/ManualControlPanel.h"
#include "commands/controlpanel/RotateControlPanel.h"
#include "commands/controlpanel/PositionControlPanel.h"
#include "commands/controlpanel/StopControlPanel.h"
#include "commands/auto/AutonomousCode.h"
#include "commands/Climb.h"
#include "commands/MoveCameraServo.h"
#include "commands/NextCamera.h"
#include "commands/PreviousCamera.h"
#include "commands/NextCamera.h"
// #include "commands/ToggleLift.h"
#include "commands/limelight/AimLM.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer
{
public:
	RobotContainer();

	frc2::Command *GetAutonomousCommand(int slot, bool shoot, int move, bool shoot2);

	frc::XboxController *GetDriverJoystick()
	{
		return &mDriverController;
	}

private:
	// The robot's subsystems and commands are defined here...

	CameraServo mCameraServo;
	MoveCameraServo mServoCommand{&mCameraServo};

	frc::XboxController mDriverController{0};
	frc2::Button mDriverButtonA{[&] { return mDriverController.GetRawButton(1); }};
	frc2::Button mDriverButtonB{[&] { return mDriverController.GetRawButton(2); }};
	frc2::Button mDriverButtonX{[&] { return mDriverController.GetRawButton(3); }};
	frc2::Button mDriverButtonY{[&] { return mDriverController.GetRawButton(4); }};
	frc2::Button mDriverButtonLB{[&] { return mDriverController.GetRawButton(5); }};
	frc2::Button mDriverButtonRB{[&] { return mDriverController.GetRawButton(6); }};
	frc2::Button mDriverButtonLMenu{[&] { return mDriverController.GetRawButton(7); }};
	frc2::Button mDriverButtonRMenu{[&] { return mDriverController.GetRawButton(8); }};
	frc2::Button mDriverLT{[&] { return (mDriverController.GetRawAxis(2) > 0.5); }};
	frc2::Button mDriverRT{[&] { return (mDriverController.GetRawAxis(3) > 0.5); }};
	frc2::Button mDriverUpDPad{[&] { return (mDriverController.GetPOV() == 0); }};
	frc2::Button mDriverDownDPad{[&] { return (mDriverController.GetPOV() == 180); }};

	frc::XboxController mOperatorController{1};
	frc2::Button mOperatorButtonA{[&] { return mOperatorController.GetRawButton(1); }};
	frc2::Button mOperatorButtonB{[&] { return mOperatorController.GetRawButton(2); }};
	frc2::Button mOperatorButtonX{[&] { return mOperatorController.GetRawButton(3); }};
	frc2::Button mOperatorButtonY{[&] { return mOperatorController.GetRawButton(4); }};
	frc2::Button mOperatorButtonLB{[&] { return mOperatorController.GetRawButton(5); }};
	frc2::Button mOperatorButtonRB{[&] { return mOperatorController.GetRawButton(6); }};
	frc2::Button mOperatorButtonLMenu{[&] { return mOperatorController.GetRawButton(7); }};
	frc2::Button mOperatorButtonRMenu{[&] { return mOperatorController.GetRawButton(8); }};

	frc2::Button mOperatorLT{[&] { return mOperatorController.GetRawAxis(2) > 0.5; }};
	frc2::Button mOperatorRT{[&] { return mOperatorController.GetRawAxis(3) > 0.5; }};
	frc2::Button mOperatorUpDPad{[&] { return (mOperatorController.GetPOV() == 0); }};
	frc2::Button mOperatorDownDPad{[&] { return (mOperatorController.GetPOV() == 180); }};

	//Lights mLights;

	DriveTrain mTankDrive;
	DriveWithXbox mDriveCommand{&mTankDrive};
	SlowTurn mSlowLeftCommand{&mTankDrive, false};
	SlowTurn mSlowRightCommand{&mTankDrive, true};
	FlipDrive mFlipDriveCommand{&mTankDrive};

	Intake mIntake;
	Indexer mIndexer;
	Shooter mShooter;
	BallJam mBallJamCommand{&mIndexer, &mShooter};
	IndexPowerCell mIndexCommand{&mIndexer};
	LowerArm mLowerArmCommand{&mIntake, &mIndexer};
	PrepShooting mPrepShootingSlow{&mIndexer, &mShooter, kSlowSpeed};
	PrepShooting mPrepShootingMed{&mIndexer, &mShooter, kMedSpeed};
	PrepShooting mPrepShootingFast{&mIndexer, &mShooter, kFastSpeed};
	RaiseArm mRaiseArmCommand{&mIntake, &mIndexer};
	Reset mResetCommand{&mIntake, &mIndexer};
	ShootPowerCells mShootCommand{&mIndexer, &mShooter};
	StopShootingPowerCells mStopShootingCommand{&mIndexer, &mShooter};

	ControlPanelManipulator mControlPanel;
	RotateControlPanel mRotateCommand{&mControlPanel, &mTankDrive};
	PositionControlPanel mPositionCommand{&mControlPanel, &mTankDrive};
	StopControlPanel mStopPanelCommand{&mControlPanel, &mTankDrive};
	ManualControlPanel mManualPanelCommand{&mControlPanel};

	LM mLM;
	AimLM mAimLM{&mLM, &mShooter, &mTankDrive};

	Climber mClimber{&mOperatorController};
	Climb mClimbCommand{&mClimber};

	cs::UsbCamera mCamera1;
	cs::UsbCamera mCamera2;
	//cs::UsbCamera mCamera3;
	NextCamera mNextCamCommand{&mCamera1, &mCamera2};
	PreviousCamera mPrevCamCommand{&mCamera1, &mCamera2};

	// Pneumatics mPneumatics;
	// ToggleLift mToggleLift{&mPneumatics};

	void ConfigureButtonBindings();
};
