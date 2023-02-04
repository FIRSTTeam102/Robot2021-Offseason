/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardWidget.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTableEntry.h>
#include <frc2/command/CommandScheduler.h>

#include <frc/RobotController.h>

frc::SendableChooser<int> mAutoPos;
frc::SendableChooser<bool> mAutoShoot;
frc::SendableChooser<int> mAutoMovement;
frc::SendableChooser<bool> mAutoShoot2;

void Robot::RobotInit()
{

	mAutoPos.SetDefaultOption("In front of target", 1);
	mAutoPos.AddOption("In front of trench", 2);
	mAutoPos.AddOption("Far away", 3);

	mAutoShoot.SetDefaultOption("Shoot", true);
	mAutoShoot.AddOption("Don't Shoot", false);

	mAutoMovement.AddOption("Pick up (trench only)", 1);
	mAutoMovement.AddOption("Back up", 2);
	mAutoMovement.SetDefaultOption("Delayed back up", 3);

	mAutoShoot2.AddOption("Shoot trench balls", true);
	mAutoShoot2.SetDefaultOption("Don't shoot trench balls", false);

	frc::Shuffleboard::GetTab("Auto")
			.Add("Starting Position", mAutoPos)
			.WithWidget(frc::BuiltInWidgets::kComboBoxChooser)
			.WithPosition(2, 0)
			.WithSize(2, 1);

	frc::Shuffleboard::GetTab("Auto")
			.Add("Initial shot?", mAutoShoot)
			.WithWidget(frc::BuiltInWidgets::kSplitButtonChooser)
			.WithPosition(1, 1)
			.WithSize(3, 1);

	frc::Shuffleboard::GetTab("Auto")
			.Add("Movement", mAutoMovement)
			.WithWidget(frc::BuiltInWidgets::kComboBoxChooser)
			.WithPosition(4, 0)
			.WithSize(2, 1);
	frc::Shuffleboard::GetTab("Auto")
			.Add("Shoot again?", mAutoShoot2)
			.WithWidget(frc::BuiltInWidgets::kSplitButtonChooser)
			.WithPosition(4, 1)
			.WithSize(3, 1);

	//put game specific data on the shuffleboard - start of match = ""
	frc::Shuffleboard::GetTab("Drive Info")
			.Add("CP FMS Color", "No Data")
			.WithPosition(4, 5);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic()
{
	frc2::CommandScheduler::GetInstance().Run();

	std::string driveMsg = "";
	std::string gameData = frc::DriverStation::GetGameSpecificMessage();
	if (gameData.length() > 0)
	{
		switch (gameData[0])
		{
		case 'B':
			driveMsg = "Blue";
			break;
		case 'G':
			driveMsg = "Green";
			break;
		case 'R':
			driveMsg = "Red";
			break;
		case 'Y':
			driveMsg = "Yellow";
			break;
		default:
			printf("NO DATA\n");
			break;
		}
	}
	// Update the network table entry for the drive info tab
	nt::NetworkTableInstance ntInst = nt::NetworkTableInstance::GetDefault();
	auto shuffleTable = ntInst.GetTable("Shuffleboard/Drive Info");
	nt::NetworkTableEntry gameSpecMsgEntry = shuffleTable->GetEntry("CP FMS Color");
	gameSpecMsgEntry.SetString(driveMsg);
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {
	if (frc::RobotController::GetBatteryVoltage().value() < 10.5) {
		for (int i = 0; i < 10; i++) {
			printf("REPLACE BATTERY | REPLACE BATTERY\n");

			throw std::runtime_error{"INTENTIONAL CRASH -- REPLACE BATTERY NOW"};
		}
	}
}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit()
{
	mAutonomousCommand = mContainer.GetAutonomousCommand(mAutoPos.GetSelected(), mAutoShoot.GetSelected(), mAutoMovement.GetSelected(), mAutoShoot2.GetSelected());

	if (mAutonomousCommand != nullptr)
	{
		mAutonomousCommand->Schedule();
	}
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
{
	if (mAutonomousCommand != nullptr)
	{
		mAutonomousCommand->Cancel();
		mAutonomousCommand = nullptr;
	}
	//m_container.GetDeployManipulatorCommand()->Schedule();
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
	return frc::StartRobot<Robot>();
}
#endif
