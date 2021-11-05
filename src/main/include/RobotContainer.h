/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc/GenericHID.h>
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
#include "commands/powercell/IndexSingleCell.h"
#include "commands/powercell/LowerArm.h"
#include "commands/powercell/PrepShooting.h"
#include "commands/powercell/ManualShooting.h"
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

	frc::XboxController *GetDriverJoystick() { return &mDriverController; }

private:
	void ConfigureButtonBindings();

	// The robot's subsystems and commands are defined here...

	frc::XboxController mDriverController{0};
	frc2::Button mDriverButtonA{[&] { return mDriverController.GetAButton(); }};
	frc2::Button mDriverButtonB{[&] { return mDriverController.GetBButton(); }};
	frc2::Button mDriverButtonX{[&] { return mDriverController.GetXButton(); }};
	frc2::Button mDriverButtonY{[&] { return mDriverController.GetYButton(); }};
	frc2::Button mDriverButtonLB{[&] { return mDriverController.GetBumper(frc::GenericHID::JoystickHand::kLeftHand); }};
	frc2::Button mDriverButtonRB{[&] { return mDriverController.GetBumper(frc::GenericHID::JoystickHand::kRightHand); }};
	frc2::Button mDriverButtonLMenu{[&] { return mDriverController.GetBackButton(); }};
	frc2::Button mDriverButtonRMenu{[&] { return mDriverController.GetStartButton(); }};
	frc2::Button mDriverLT{[&] { return (mDriverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > 0.5); }};
	frc2::Button mDriverRT{[&] { return (mDriverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > 0.5); }};
	frc2::Button mDriverUpDPad{[&] { return (mDriverController.GetPOV() == 0); }};
	frc2::Button mDriverLeftDPad{[&] { return (mDriverController.GetPOV() == 90); }};
	frc2::Button mDriverDownDPad{[&] { return (mDriverController.GetPOV() == 180); }};
	frc2::Button mDriverRightDPad{[&] { return (mDriverController.GetPOV() == 270); }};

	frc::XboxController mOperatorController{1};
	frc2::Button mOperatorButtonA{[&] { return mOperatorController.GetAButton(); }};
	frc2::Button mOperatorButtonB{[&] { return mOperatorController.GetBButton(); }};
	frc2::Button mOperatorButtonX{[&] { return mOperatorController.GetXButton(); }};
	frc2::Button mOperatorButtonY{[&] { return mOperatorController.GetYButton(); }};
	frc2::Button mOperatorButtonLB{[&] { return mOperatorController.GetBumper(frc::GenericHID::JoystickHand::kLeftHand); }};
	frc2::Button mOperatorButtonRB{[&] { return mOperatorController.GetBumper(frc::GenericHID::JoystickHand::kRightHand); }};
	frc2::Button mOperatorButtonLMenu{[&] { return mOperatorController.GetBackButton(); }};
	frc2::Button mOperatorButtonRMenu{[&] { return mOperatorController.GetStartButton(); }};
	frc2::Button mOperatorLT{[&] { return mOperatorController.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > 0.5; }};
	frc2::Button mOperatorRT{[&] { return mOperatorController.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > 0.5; }};
	frc2::Button mOperatorUpDPad{[&] { return (mOperatorController.GetPOV() == 0); }};
	frc2::Button mOperatorLeftDPad{[&] { return (mOperatorController.GetPOV() == 90); }};
	frc2::Button mOperatorDownDPad{[&] { return (mOperatorController.GetPOV() == 180); }};
	frc2::Button mOperatorRightDPad{[&] { return (mOperatorController.GetPOV() == 270); }};

	// Lights mLights;

	CameraServo mCameraServo;
	MoveCameraServo mServoCommand{&mCameraServo};

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
	IndexSingleCell mIndexOnceCommand{&mIndexer};
	LowerArm mLowerArmCommand{&mIntake, &mIndexer};
	PrepShooting mPrepShootingSlow{&mIndexer, &mShooter, kSlowSpeed};
	PrepShooting mPrepShootingMed{&mIndexer, &mShooter, kMedSpeed};
	PrepShooting mPrepShootingFast{&mIndexer, &mShooter, kFastSpeed};
	ManualShooting mManualShooting{&mShooter};
	RaiseArm mRaiseArmCommand{&mIntake, &mIndexer};
	Reset mResetCommand{&mIntake, &mIndexer};
	ShootPowerCells mShootCommand{&mIndexer, &mShooter};
	StopShootingPowerCells mStopShootingCommand{&mIndexer, &mShooter};

	ControlPanelManipulator mControlPanel;
	RotateControlPanel mRotateControlPanelCommand{&mControlPanel, &mTankDrive};
	PositionControlPanel mPositionControlPanelCommand{&mControlPanel, &mTankDrive};
	StopControlPanel mStopControlPanelCommand{&mControlPanel, &mTankDrive};
	ManualControlPanel mManualControlPanelCommand{&mControlPanel};

	LM mLM;
	AimLM mAimLM{&mLM, &mShooter, &mTankDrive};

	Climber mClimber{&mOperatorController};
	Climb mClimbCommand{&mClimber};

	cs::UsbCamera mCamera1;
	cs::UsbCamera mCamera2;
	// cs::UsbCamera mCamera3;
	NextCamera mNextCamCommand{&mCamera1, &mCamera2};
	PreviousCamera mPrevCamCommand{&mCamera1, &mCamera2};

	// Pneumatics mPneumatics;
	// ToggleLift mToggleLift{&mPneumatics};
};
