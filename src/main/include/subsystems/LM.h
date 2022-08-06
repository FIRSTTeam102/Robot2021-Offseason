/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

class LM : public frc2::SubsystemBase
{
public:
	LM();

	double getShootSpeed();

	bool limeLightHasTarget() { return m_LimelightHasTarget; }

	bool isClose() { return (ty < 9); }

	float left_command;
	float right_command;

	std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

	/**
			* Will be called periodically whenever the CommandScheduler runs.
			*/
	void Periodic();
	bool CheckR();

private:
	bool m_LimelightHasTarget; //True if acquired target

	double tx;
	double ty;
	double ta;
	bool tv;

	float heading_error;
	float steering_adjust = 0.0f;

	float Kp;
	float min_command;
};