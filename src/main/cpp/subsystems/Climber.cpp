/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"
#include "RobotContainer.h"
#include "Constants.h"

Climber::Climber(frc::XboxController *pOperatorJoystick) :
	mClimbUpMotor{kClimbUpMotor},
	mClimbDownMotor{kClimbDownMotor},
	mTopSensor{kClimberTopSensor},
	mMidSensor{kClimberMidSensor},
	mBotSensor{kClimberBotSensor},
	mpOperatorJoystick{pOperatorJoystick}
{
	mClimbUpMotor.SetInverted(true);
	mClimbDownMotor.SetInverted(true);
}

// Stop all climber motors
void Climber::StopClimb()
{
	mClimbUpMotor.Set(0);
	mClimbDownMotor.Set(0);
}

// Raise the climber
void Climber::Climb()
{
	printf("Climb status: up %d		mid %d		down %d		speed: %F	", isClimbUp(), isClimbMid(), isClimbDown(), ClimbSpeed());
	if (ClimbSpeed() > 0 && !isClimbUp()) {
		printf("Climbing up");
		mClimbUpMotor.Set(ClimbSpeed());
		mClimbDownMotor.Set(0);
	} else if (ClimbSpeed() < 0 && !isClimbDown()) {
		printf("Climbing down");
		mClimbUpMotor.Set(ClimbSpeed() * kTakeUpSlackPercent);
		mClimbDownMotor.Set(ClimbSpeed());
	} else {
		printf("Climbing stopped");
		StopClimb();
	}
	printf("	Up speed %F		Down speed %F\n\n", mClimbUpMotor.Get(), mClimbDownMotor.Get());
}

// This method will be called once per scheduler run
void Climber::Periodic()
{
}