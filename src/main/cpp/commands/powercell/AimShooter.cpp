/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/powercell/AimShooter.h"

AimShooter::AimShooter(Shooter *pShooter, float speed) : mpShooter{pShooter}, mSpeed{speed}
{
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(mpShooter);
}

// Called when the command is initially scheduled.
void AimShooter::Initialize()
{
	rampUpSpeed = 0;
	if (mSpeed != ShooterConstants::kFastSpeed)
	{
		mpShooter->extServo();
	}
	else
	{
		mpShooter->retrServo();
	}
	printf("Aiming shooter\n");
}

// Called repeatedly when this Command is scheduled to run
void AimShooter::Execute()
{
	rampUpSpeed += 0.02;
	mpShooter->setSpeed(rampUpSpeed * mSpeed);
	mpShooter->startMotor();
	printf("RAMP UP PERCENT: %f\n", rampUpSpeed);
}

// Called once the command ends or is interrupted.
void AimShooter::End(bool interrupted)
{
	if (interrupted)
	{
		mpShooter->setSpeed(mSpeed);
		mpShooter->startMotor();
	}
}

// Returns true when the command should end.
bool AimShooter::IsFinished()
{
	return (rampUpSpeed >= 1);
}