/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/controlpanel/PositionControlPanel.h"

PositionControlPanel::PositionControlPanel(ControlPanelManipulator *pControlPanel, DriveTrain *pSubsystemDrive) {
  AddRequirements({pControlPanel});
  AddRequirements({pSubsystemDrive});
  // Use addRequirements() here to declare subsystem dependencies.
  mpControlPanel = pControlPanel;
  mpSubsystemDrive = pSubsystemDrive;
}

// Called when the command is initially scheduled.
void PositionControlPanel::Initialize() {
  //Lights::GetInstance()->setMode(kLights_rainbow_bounce); //for light stuffs
  mpControlPanel->resetFinished();
}

// Called repeatedly when this Command is scheduled to run
void PositionControlPanel::Execute() {
  gameData = frc::DriverStation::GetGameSpecificMessage();
  if(gameData.length() > 0)
  {
    switch (gameData[0])
    {
    case 'B' :
      mpControlPanel->positionControl('R');
      break;
    case 'G' :
      mpControlPanel->positionControl('Y');
      break;
    case 'R' :
      mpControlPanel->positionControl('B');
      break;
    case 'Y' :
      mpControlPanel->positionControl('G');
      break;
    default :
      printf("BAD GAME DATA\n");
      break;
    }
  } 
  else {
    mpControlPanel->positionControl('G');
  }
  mpSubsystemDrive->move(0.15, 0.15);
  printf("Running Pos\n");
}

// Called once the command ends or is interrupted.
void PositionControlPanel::End(bool interrupted) {
  printf("Position complete!\n");
  //Lights::GetInstance()->setMode(kLights_enabled); //for light stuffs
  mpControlPanel->stopMotor();
  mpSubsystemDrive->stop();
}

// Returns true when the command should end.
bool PositionControlPanel::IsFinished() {
  return mpControlPanel->getFinished();
}
