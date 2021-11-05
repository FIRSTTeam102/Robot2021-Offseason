/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>
#include "commands/powercell/AimShooter.h"
#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

class ManualShooting : public frc2::CommandHelper<frc2::ParallelCommandGroup, ManualShooting>
{
public:
	ManualShooting(Shooter *pShooter);
};