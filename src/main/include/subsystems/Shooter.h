/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Encoder.h>
#include <ctre/Phoenix.h>
#include <frc/Servo.h>
#include "Constants.h"

#define DEMO_MODE

namespace ShooterConstants {
	// Shooter Speeds
#ifdef DEMO_MODE
	float constexpr kSlowSpeed = 0.22;
	float constexpr kMedSpeed = 0.3;
	float constexpr kFastSpeed = 0.5;
#else
	float constexpr kSlowSpeed = 0.4;
	float constexpr kMedSpeed = 0.51;
	float constexpr kFastSpeed = 0.8;
#endif
}

class Shooter : public frc2::SubsystemBase
{
public:
	Shooter();
	void setSpeed(float speed);
	void startMotor();
	void stopMotor();
	bool isRunning();
	void extServo()
	{
		mServo.Set(kOutHood);
		mHoodIn = 0;
	}
	void retrServo()
	{
		mServo.Set(kInHood);
		mHoodIn = 1;
	}
	void toggleServo();

	/**
	 * Will be called periodically whenever the CommandScheduler runs.
	 */
	void Periodic();

private:
	WPI_TalonSRX mShooter1;
	WPI_TalonSRX mShooter2;
	frc::Servo mServo;
	float mSpeed;
	bool mHoodIn;
	bool mIsStarted;
	// Components (e.g. motor controllers and sensors) should generally be
	// declared private and exposed only through public methods.
};