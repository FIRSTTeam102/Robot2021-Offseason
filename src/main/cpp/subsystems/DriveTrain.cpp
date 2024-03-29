/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/shuffleboard/Shuffleboard.h>
#include "subsystems/DriveTrain.h"
#include "RobotContainer.h"
#include "Constants.h"


DriveTrain::DriveTrain():
	mDriveLeft1{kTopLeftMotor}, 
	mDriveLeft2{kBottomLeftMotor}, 
	mDriveRight1{kTopRightMotor}, 
	mDriveRight2{kBottomRightMotor}
 {
	mDriveLeft1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	mDriveLeft2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	mDriveRight1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	mDriveRight2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

	frc::Shuffleboard::GetTab("Drive Info")
	.Add("Drive Front",inverted)
	.WithWidget(frc::BuiltInWidgets::kBooleanBox)
	.WithPosition (0,4);

	mLeftEnc.SetDistancePerPulse(EncoderDistancePerPulse);
	mRightEnc.SetDistancePerPulse(EncoderDistancePerPulse);

	wpi::StringMap<std::shared_ptr<nt::Value>> demoScaleSliderProps = {
		std::make_pair("Min", nt::Value::MakeDouble(0.10)),
		std::make_pair("Max", nt::Value::MakeDouble(1.00)),
		std::make_pair("Block increment", nt::Value::MakeDouble(0.05))
	};

	mShuffleboardSpeedScale = frc::Shuffleboard::GetTab("Demo")
		.Add("Demo Speed Scale", 0.85)
		.WithWidget(frc::BuiltInWidgets::kNumberSlider)
		.WithProperties(demoScaleSliderProps)
		.GetEntry();
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}

void DriveTrain::tankDrive(){
	double speedPercent = 0.84;
	if (mpDriverJoystick->GetLeftBumper()) { // LB
		speedPercent = 1.00; // Turbo pressed
	}

	double leftSpeed = speedPercent * mpDriverJoystick->GetLeftY(); // Cap: 690rpm
	double rightSpeed = speedPercent * mpDriverJoystick->GetRightY(); // Cap: 697rpm
	if (!inverted) {
		mDrive.TankDrive(-leftSpeed, -rightSpeed,true);
	} else {
		mDrive.TankDrive(rightSpeed, leftSpeed, true);
	}
	//printf("Driving: %f, %f\n", leftSpeed, rightSpeed);
}

void DriveTrain::arcadeDrive(){
	double speedPercent = mShuffleboardSpeedScale.GetDouble(0.85);
	double rotationPercent = 0.74;
	if (mpDriverJoystick->GetLeftBumper()) { // LB
		speedPercent = 1.00; // Turbo pressed
	}
	// if (mpDriverJoystick->GetRightBumper()) { // RB
	// 	rotationPercent = 0.8; // Turbo pressed
	// }

	// @fixme: wtf why are these inverted
	double speed = speedPercent * mpDriverJoystick->GetLeftY(); // Cap: 690rpm
	double rotation = rotationPercent * mpDriverJoystick->GetRightX(); // Cap: 697rpm
	if (!inverted) {
		mDrive.ArcadeDrive(rotation, speed, true);
	} else {
		mDrive.ArcadeDrive(rotation, -speed, true);
	}
}

void DriveTrain::stop(){
	mDrive.TankDrive(0, 0, false);
}

void DriveTrain::move(double left, double right){
	mDrive.TankDrive(left, right, false);
	printf("Moving: %f, %f\n", left, right);
}

void DriveTrain::toggleDrive(){
	printf("On: %d\n", on);
	if (on == true) {
		mDrive.TankDrive(-1, -1, true);
		if (mpDriverJoystick->GetAButton() == true) {
			//while (p_driverJoystick->GetAButton() == true);
			on = false;
		}
	}
	else {
		mDrive.TankDrive(0, 0, true);
		if (mpDriverJoystick->GetAButton() == true) {
			//while (p_driverJoystick->GetAButton() == true);
			on = true;
		}
	}
}

bool DriveTrain::flipDrive() {
	inverted = !inverted;
	return inverted;
}