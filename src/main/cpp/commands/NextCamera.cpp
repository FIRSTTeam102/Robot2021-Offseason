/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/shuffleboard/Shuffleboard.h>
#include "commands/NextCamera.h"

NextCamera::NextCamera(cs::UsbCamera* Camera1, cs::UsbCamera* Camera2)
  : mCamera1{Camera1},
    mCamera2{Camera2},
    mCameraSource{1} 
 {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void NextCamera::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void NextCamera::Execute() {
  printf("Current camera: %d    ", mCameraSource);
  if (mCameraSource == 1) {
    frc::CameraServer::GetServer().SetSource(*mCamera2);
    mCameraSource = 2;
    printf ("Camera 2 \n");
  }
  else {
    frc::CameraServer::GetServer().SetSource(*mCamera1);
    mCameraSource = 1;
    printf ("Camera 1 \n");
  }
}

// Called once the command ends or is interrupted.
void NextCamera::End(bool interrupted) {}

// Returns true when the command should end.
bool NextCamera::IsFinished() { return true; }
