/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/SendableCameraWrapper.h>

/* trying to get std::map to work... */
#include <map>
#include <string>
// apparently also need network tables...
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

RobotContainer::RobotContainer() {
	frc::DriverStation::SilenceJoystickConnectionWarning(true);
	// Initialize all of your commands and subsystems here

	// Configure the button bindings
	ConfigureButtonBindings();

	// Tank drive controller init
	mTankDrive.SetDefaultCommand(std::move(mDriveCommand));
	mTankDrive.setDriverJoystick(&mDriverController);

	// mClimber.SetDefaultCommand(std::move(mClimbCommand));

	// mIndexer.SetDefaultCommand(std::move(mIndexCommand));

	// Cameras 0 & 1 init
	// mCamera1 = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
	// mCamera2 = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
	// Get video stream from camera 1
	// frc::CameraServer::GetInstance()->GetServer().SetSource(mCamera1);

	// Shuffleboard info/controls
	// change size to .WithSize(4,4)
	// 	and edit tile size to be > or = 256-ish in "File" -> "Default Tile Size"
	//  (need to change using code though instead of manually every time...)
	// recommended settings:
	// compression=20, fps=15, resolution=320x240
	
	// HOW CAN I DECLARE A STRINGMAP with properties ???
	// looking at ...\wpi\StringMap.h
	//wpi::StringMap<int> testMap = {{"min", 0}, {"max", 1}};
	//std::map<std::string, int> m { {"CPU", 10}, {"GPU", 15}, {"RAM", 20}, };
	// frc::Shuffleboard::GetTab("Drive Info")
	// 		.Add("Camera Stream", mCamera1)
	// 		.WithWidget(frc::BuiltInWidgets::kCameraStream)
	// 		.WithSize(7, 4)
	// 		//.WithProperties(wpi::StringMap<std::string>({"min",0,"max",0}))
	// 		//.WithProperties(testMap)
	// 		.WithPosition(0, 0);
	// frc::Shuffleboard::GetTab("Drive Info")
	// 		.Add("text info here", "sample text?")
	// 		.WithWidget(frc::BuiltInWidgets::kTextView)
	// 		.WithSize(2, 1)
	// 		.WithPosition(2, 5);

	// Camera servo controller
	// mCameraServo.SetDefaultCommand(std::move(mServoCommand));
	// mCameraServo.setServoJoystick(&mOperatorController);
}

void RobotContainer::ConfigureButtonBindings() {
	// Configure your button bindings here

	// mDriverButtonB.WhenHeld(&mPositionControlPanelCommand, true);
	// mDriverButtonX.WhenHeld(&mRotateControlPanelCommand, true);
	// mDriverButtonY.WhenHeld(&mManualControlPanelCommand, false);
	// mDriverButtonLB.WhenHeld(&mSlowLeftCommand, true);
	// mDriverButtonRB.WhenHeld(&mSlowRightCommand, true);
	// mDriverButtonLMenu.WhenPressed(&mNextCamCommand, true);
	mDriverButtonRMenu.WhenPressed(&mFlipDriveCommand, false);
	mDriverLT.WhenPressed(&mIndexOnceCommand, true);
	mDriverRT.WhenHeld(&mShootCommand, false);
	// mDriverButtonLB is mapped to speed boost
	// mDriverButtonRB.WhenHeld(&mLMYawToTarget, true);

	mDriverButtonA.WhenPressed(&mPrepShootingSlow, true);
	// mOperatorButtonA.WhenPressed(&mManualShooting, true);
	mDriverButtonB.WhenPressed(&mPrepShootingMed, true);
	mDriverButtonX.WhenHeld(&mStopShootingCommand, false);
	mDriverButtonY.WhenPressed(&mPrepShootingFast, true);
	// mOperatorButtonLB.WhenHeld(&mBallJamCommand, true);
	// mOperatorButtonRB.WhenHeld(&mShootCommand, false);
	mDriverRightDPad.WhenHeld(&mResetCommand, true);
	mDriverDownDPad.WhenPressed(&mLowerArmCommand, true);
	mDriverUpDPad.WhenPressed(&mRaiseArmCommand, true);
	// mOperatorLT.WhenHeld(&mLMYawToTarget, true);
	// mOperatorRT.WhenHeld(&mIndexOnceCommand, true);
	// must be added- mOperatorButtonLMenu(toggle danger buttons)
	// mOperatorButtonLMenu.WhenPressed(&mPrevCamCommand, true);
	// mOperatorButtonRMenu.WhenPressed(&mNextCamCommand, true);
}

frc2::Command *RobotContainer::GetAutonomousCommand(int slot, bool shoot, int move, bool shoot2) {
	// An example command will be run in autonomous
	// return &m_autonomousCommand;
	// mAutoCommand.setAutoConfig(slot, shoot, move, shoot2);
	// return &mAutoCommand;
	// return new AutonomousCode(&mTankDrive, &mIntake, &mIndexer, &mShooter, &mLM, slot, shoot, move, shoot2);
	return nullptr;
}
