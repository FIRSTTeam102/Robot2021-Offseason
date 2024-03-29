/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/Shooter.h"
#include "Constants.h"

Shooter::Shooter() : 
	mShooter1{kFlyMotor1},
	mShooter2{kFlyMotor2},
	mServo{kHoodServo}
{
	mShooter2.Set(ControlMode::Follower, kFlyMotor1);
	mShooter1.SetInverted(true);
	mShooter2.SetInverted(true);

	frc::Shuffleboard::GetTab("Drive Info")
	.Add("Fly Wheel Speed","Stopped")
	.WithPosition (3,4);

	wpi::StringMap<std::shared_ptr<nt::Value>> demoScaleSliderProps = {
		std::make_pair("Min", nt::Value::MakeDouble(0.0)),
		std::make_pair("Max", nt::Value::MakeDouble(1.00)),
		std::make_pair("Block increment", nt::Value::MakeDouble(0.05))
	};

	mShuffleboardSpeed = frc::Shuffleboard::GetTab("Demo")
		.Add("Shooter speed", 0.8)
		.WithWidget(frc::BuiltInWidgets::kNumberSlider)
		.WithProperties(demoScaleSliderProps)
		.GetEntry();

	frc::SmartDashboard::PutNumber("Flywheel Speed", 0.0);
}

// This method will be called once per scheduler run
void Shooter::Periodic() {
	// printf("Shooter should be: %d\n", mHoodIn);
}

void Shooter::setSpeed(float speed) {
	mSpeed = speed;
}

void Shooter::startMotor() {
	mShooter1.Set(mSpeed);
	mIsStarted = true;
}

void Shooter::stopMotor() {
	mShooter1.Set(0);
	mIsStarted = false;
}

bool Shooter::isRunning() {
	return mIsStarted;
}

void Shooter::toggleServo() {
	if (mHoodIn) {
		extServo();
		mHoodIn = false;
	}
	else {
		retrServo();
		mHoodIn = true;
	}
}