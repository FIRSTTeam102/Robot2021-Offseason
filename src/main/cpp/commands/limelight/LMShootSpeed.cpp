/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/limelight/LMShootSpeed.h"

LMShootSpeed::LMShootSpeed(Shooter *pShooter, LM *pLM) : mpShooter{pShooter}, mpLM{pLM}
{
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(mpShooter);
}

// Called when the command is initially scheduled.
void LMShootSpeed::Initialize()
{
	rampUpSpeed = 0;
	printf("Aiming shooter\n");
	if (mpLM->isClose())
	{
		mpShooter->retrServo();
	}
	else
	{
		mpShooter->extServo();
	}
}

// Called repeatedly when this Command is scheduled to run
void LMShootSpeed::Execute()
{
	rampUpSpeed += 0.02;
	mpShooter->setSpeed(rampUpSpeed * mpLM->getShootSpeed());
	mpShooter->startMotor();
	printf("RAMP UP PERCENT: %f\n", rampUpSpeed * mpLM->getShootSpeed());
}

// Called once the command ends or is interrupted.
void LMShootSpeed::End(bool interrupted)
{
	if (interrupted)
	{
		mpShooter->setSpeed(mpLM->getShootSpeed());
		mpShooter->startMotor();
	}
}

// Returns true when the command should end.
bool LMShootSpeed::IsFinished()
{
	return (rampUpSpeed >= 1);
}