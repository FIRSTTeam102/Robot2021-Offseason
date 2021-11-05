/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/powercell/ManualShooting.h"

ManualShooting::ManualShooting(Shooter *pShooter)
{
	AddCommands(AimShooter(pShooter, frc::SmartDashboard::GetNumber("Flywheel Speed", 0.0)));
}