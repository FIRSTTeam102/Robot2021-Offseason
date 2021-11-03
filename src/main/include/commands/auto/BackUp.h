/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/DriveTrain.h> //used for light stuffs

class BackUp : public frc2::CommandHelper<frc2::CommandBase, BackUp> {
	public:
		explicit BackUp(DriveTrain* pDriveTrain, double distance = 24);

		void Initialize() override;

		void Execute() override;

		void End(bool interrupted) override;

		bool IsFinished() override;

		private:
		DriveTrain* mpDriveTrain;
		double mDistance;
		int ticksPassed;
};
