/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
// // /* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/limelight/LMYawToTarget.h"
#include "subsystems/LM.h"

LM::LM() : m_LimelightHasTarget(false)
{
	Kp = -0.1f;
	min_command = 0.05f;
	table->PutNumber("ledMode", 0);
	table->PutNumber("pipeline", 0);
}

double LM::getShootSpeed()
{
	//return 0.5;
	//if (ty>=22.29) {
	if (ty >= 23.46)
	{
		printf("Close close\n");
		return 0.405;
	}
	else if (ty >= 19.45)
	{
		printf("Far close\n");
		return 0.3725;
	}
	//else if (ty>=14.08) {
	else if (ty >= 15.42)
	{
		printf("Close med\n");
		return 0.39;
	}
	else if (ty >= 12.65)
	{
		printf("Far med\n");
		return 0.395;
	}
	else if (ty >= 9)
	{ //if this is changed, change isClose() in LM.h
		printf("Far\n");
		return 0.425;
	}
	else
	{
		printf("Super close\n");
		return 0.5;
	}
}

//This method will be called continuously until Limelight rotated to target
bool LM::CheckR()
{
	if (-0.5 < tx && tx < 0.5)
	{
		return true;
	}
	return false;
}

// This method will be called once per scheduler run
void LM::Periodic()
{

	tx = table->GetNumber("tx", 0.0);
	ty = table->GetNumber("ty", 0.0);
	ta = table->GetNumber("ta", 0.0);
	tv = table->GetNumber("tv", 0.0);

	if (m_LimelightHasTarget == true)
	{
		heading_error = -tx;
		steering_adjust = 0.0f;
		if (tx > 0.0)
		{
			steering_adjust = 0.25;
			//steering_adjust = Kp*heading_error - min_command;
		}
		else if (tx < 0.0)
		{
			steering_adjust = -0.2;
			//steering_adjust = Kp*heading_error + min_command;
		}
		left_command = steering_adjust;
		right_command = -steering_adjust;
		//printf("%f, %f\n", left_command, right_command);
	}

	if (tv < 1.0)
	{
		m_LimelightHasTarget = false;
	}
	else
	{
		m_LimelightHasTarget = true;
	}
}