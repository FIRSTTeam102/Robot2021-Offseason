/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Relay.h>
#include "subsystems/Intake.h"
#include "RobotContainer.h"
#include "Constants.h"
#include <frc/DigitalInput.h>


Intake::Intake():
    mIntakeArmMotor{kIntakeArmMotor, frc::Relay::kBothDirections},
    mIntakeRollerMotor{kIntakeRollerMotor}
    // mUpSensor{kIntakeTopSensor},
    // mDownSensor{kIntakeBottomSensor}
 {
}
//lower the intake arm - start the arm motor
void Intake::lowerIntakeArm() {
    printf("Deploying intake\n");
    mIntakeArmMotor.Set(frc::Relay::kReverse);
    // printf("Is arm down - %d\n", isArmDown());
}
//raise the intake arm -  start the arm motor
void Intake::raiseIntakeArm() {
    printf("Retracting intake\n");
    mIntakeArmMotor.Set(frc::Relay::kForward);
}
//stopIntakeArm - stop the intake arm motor by shutting it off
void Intake::stopIntakeArm() {
    mIntakeArmMotor.Set(frc::Relay::kOff);
}
//startRollers - start the intake arms rollers, to capture power cells
void Intake::startRollers() {
    printf("Rollers should be moving\n");
    mIntakeRollerMotor.Set(-kIntakeRollerSpeed);
    printf("Status: %d\n", mIntakeRollerMotor.IsAlive());
}
//startReversRollers - start the intake arm rollers in reverse - this is to
//  spit out power cells in the event the power cell intake needs to be
//  cleared
void Intake::startReverseRollers(){
    mIntakeRollerMotor.Set(kIntakeRollerSpeed);
}
//stopRollers - stop the intake arm roller motors from running
void Intake::stopRollers() {
    mIntakeRollerMotor.Set(0);
}
// This method will be called once per scheduler run
void Intake::Periodic() {}
