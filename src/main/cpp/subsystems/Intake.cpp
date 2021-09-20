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
    mIntakeArmMotor{kIntakeMotor,frc::Relay::kBothDirections},
    mIntakeRollerMotor{kIntakeRollerMotor, frc::Relay::kBothDirections},
    mUpSensor{kIntakeTopSensor},
    mDownSensor{kIntakeBottomSensor}
 {
}
//lower the intake arm - if the arm is not
//   already in the down position, start the arm motor forward
//   if the arm is already down, make sure the arm motor is not running
void Intake::lowerIntakeArm() {
    printf("Deploying intake\n");
    printf("Is arm down - %d\n", isArmDown());
}
//raise the intake arm - if the arm is not already
//  in the fully upright position, start the arm motor in reverse
//  if the arm is already all the way up, make sure the arm motor
//  is not running.
void Intake::raiseIntakeArm() {
    printf("Retracting intake\n");
}
//stopIntakeArm - stop the intake arm motor by shutting it off
void Intake::stopIntakeArm(){
    mIntakeArmMotor.Set(frc::Relay::kOff);
}
//startRollers - start the intake arms rollers, to capture power cells
void Intake::startRollers() {
    printf("Rollers should be moving\n");
    mIntakeRollerMotor.Set(frc::Relay::kReverse);
    printf("Status: %d", mIntakeRollerMotor.IsAlive());
}
//startReversRollers - start the intake arm rollers in reverse - this is to
//  spit out power cells in the event the power cell intake needs to be
//  cleared
void Intake::startReverseRollers(){
    mIntakeRollerMotor.Set(frc::Relay::kForward);
}
//stopRollers - stop the intake arm roller motors from running
void Intake::stopRollers() {
    mIntakeRollerMotor.Set(frc::Relay::kOff);
}
// This method will be called once per scheduler run
void Intake::Periodic() {}
