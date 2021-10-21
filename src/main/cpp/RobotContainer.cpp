/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <frc/shuffleboard/Shuffleboard.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/SendableCameraWrapper.h>
#include "RobotContainer.h"

RobotContainer::RobotContainer()
{
	// Initialize all of your commands and subsystems here

	// Configure the button bindings
	ConfigureButtonBindings();

	// Tank drive controller init
	mTankDrive.SetDefaultCommand(std::move(mDriveCommand));
	mTankDrive.setDriverJoystick(&mDriverController);

	mClimber.SetDefaultCommand(std::move(mClimbCommand));
	// mIndexer.SetDefaultCommand(std::move(mIndexCommand));

	// Cameras 0 & 1 init
	mCamera1 = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
	mCamera2 = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
	// Get video stream from camera 1
	frc::CameraServer::GetInstance()->GetServer().SetSource(mCamera1);

	// Shuffleboard info/controls
	// change size to .WithSize(4,4) and edit tile size to be >= 256-ish in "File" -> "Default Tile Size"
	frc::Shuffleboard::GetTab("Drive Info")
			.Add("Camera Stream", mCamera1)
			.WithWidget(frc::BuiltInWidgets::kCameraStream)
			.WithSize(4, 3)
			.WithPosition(4, 0);

	// Camera servo controller
	mCameraServo.SetDefaultCommand(std::move(mServoCommand));
	mCameraServo.setServoJoystick(&mOperatorController);
}

void RobotContainer::ConfigureButtonBindings()
{
	// Configure your button bindings here

	mDriverButtonB.WhenHeld(&mPositionControlPanelCommand, true);
	mDriverButtonX.WhenHeld(&mRotateControlPanelCommand, true);
	mDriverButtonY.WhenHeld(&mManualControlPanelCommand, false);
	// mDriverButtonLB.WhenHeld(&mSlowLeftCommand, true);
	// mDriverButtonRB.WhenHeld(&mSlowRightCommand, true);
	mDriverButtonRMenu.WhenPressed(&mFlipDriveCommand, false);
	mDriverLT.WhenPressed(&mIndexOnceCommand, true);
	mDriverRT.WhenHeld(&mShootCommand, false);

	mOperatorButtonA.WhenPressed(&mPrepShootingSlow, true);
	mOperatorButtonB.WhenPressed(&mPrepShootingMed, true);
	mOperatorButtonX.WhenHeld(&mStopShootingCommand, false);
	mOperatorButtonY.WhenPressed(&mPrepShootingFast, true);
	mOperatorButtonLB.WhenHeld(&mBallJamCommand, true);
	mOperatorButtonRB.WhenHeld(&mShootCommand, false);
	mOperatorRightDPad.WhenHeld(&mResetCommand, true);
	mOperatorDownDPad.WhenPressed(&mLowerArmCommand, true);
	mOperatorUpDPad.WhenPressed(&mRaiseArmCommand, true);
	mOperatorLT.WhenHeld(&mAimLM, true);
	// must be added- mOperatorButtonLMenu(toggle danger buttons)
	// mOperatorButtonLMenu.WhenPressed(&mPrevCamCommand, true);
	mOperatorButtonRMenu.WhenPressed(&mNextCamCommand, true);
}

frc2::Command *RobotContainer::GetAutonomousCommand(int slot, bool shoot, int move, bool shoot2)
{
	// An example command will be run in autonomous
	// return &m_autonomousCommand;
	// mAutoCommand.setAutoConfig(slot, shoot, move, shoot2);
	// return &mAutoCommand;
	return new AutonomousCode(&mTankDrive, &mIntake, &mIndexer, &mShooter, slot, shoot, move, shoot2);
}
