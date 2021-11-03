// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Delay.h"

Delay::Delay(int ticks): mTicks(ticks) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Delay::Initialize() {
  counter = 0;
}

// Called repeatedly when this Command is scheduled to run
void Delay::Execute() {
  counter++;
}

// Called once the command ends or is interrupted.
void Delay::End(bool interrupted) {}

// Returns true when the command should end.
bool Delay::IsFinished() {
  return counter >= mTicks;
}
