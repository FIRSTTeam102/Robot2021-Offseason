/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#pragma once

#include <frc/Encoder.h>
#include <frc/SerialPort.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */


// Drive motor controllers (TalonSRX)
int constexpr kTopLeftMotor = 1;
int constexpr kTopRightMotor = 3;
int constexpr kBottomLeftMotor = 2;
int constexpr kBottomRightMotor = 4;

// Control panel motor controller (TalonSRX)
int constexpr kControlPanelMotor = 5;

// Shooter Motor Controllers (TalonSRX)
int constexpr kFlyMotor1 = 10;
int constexpr kFlyMotor2 = 11;
int constexpr kHoodServo = 2;
double constexpr kOutHood = 0.5;
double constexpr kInHood = 0.2;

// Climb Motor Controllers (PWMVictorSPX)
// up raises the climb system, down retracts it & lifts the robot
int constexpr kClimbUpMotor = 4;
int constexpr kClimbDownMotor = 5;
double constexpr kTakeUpSlackPercent = 0.3;

// Intake Arm & Roller Motor Controllers (SpikeRelay)
int constexpr kIntakeArmMotor = 0;
int constexpr kIntakeRollerMotor = 12;
double constexpr kIntakeRollerSpeed = 0.5;

// Index motor
int constexpr kIndexChannel = 13;
double constexpr kIndexSpeed = 0.5;

// PWM Signals
int constexpr kCameraServoXIndex = 1;
int constexpr kCameraServoYIndex = 0;


// Digital IO channels
// Indexer Distance Sensors (Digital Input)
int constexpr kDIOIntake = 1;
// int constexpr kDIOBottom = 1;
int constexpr kDIOTop = 0;

// Intake Limit Switches
// int constexpr kIntakeTopSensor = 3;
// int constexpr kIntakeBottomSensor = 4;

// Climber magnetic senors
int constexpr kClimberTopSensor = 4;
int constexpr kClimberMidSensor = 3;
int constexpr kClimberBotSensor = 2;

// OI Indexes (joysticks/buttons)
int constexpr kDriverJoystick = 0;
int constexpr kOperatorJoystick = 1;


// Calibrated values
// Distance from starting line to rendevous points (ball pickup)
int constexpr kStartToBallDist = 220;

// Shooter Speeds
float constexpr kSlowSpeed = 0.4;
float constexpr kMedSpeed = 0.51;
float constexpr kFastSpeed = 0.8;

// Indexer Constants
int constexpr kMaxPowerCellTravelTime = 100;

// Color values
float constexpr kBlueR = 0.13;
float constexpr kBlueG = 0.43;
float constexpr kBlueB = 0.43;
float constexpr kRedR = 0.56;
float constexpr kRedG = 0.32;
float constexpr kRedB = 0.11;
float constexpr kYelR = 0.33;
float constexpr kYelG = 0.56;
float constexpr kYelB = 0.11;
float constexpr kGrnR = 0.14;
float constexpr kGrnG = 0.60;
float constexpr kGrnB = 0.26;

// Indexer bottom sensor timeout
// Spins 760 rpms (diameter 1.5"), bottom sensor ~2" in
// Band moves 60"/s
// Ball moves 19"/s
// Timeout = (gap + 7" - 2") / 19" = (gap + 5") / 19"       7" for ball, sensor is 2" in already
// Need a timeout so they are indexed far enough
double constexpr kIndexerGap = 2;
double constexpr kBottomIndexerTimeout = (kIndexerGap + 0) / 19;

// Light codes
int constexpr kLights_off = 0;
int constexpr kLights_auto = 1;
int constexpr kLights_shoot = 2;
int constexpr kLights_disabled = 3;
int constexpr kLights_enabled = 4;
int constexpr kLights_green_loop = 5;
int constexpr kLights_rainbow_loop = 6;
int constexpr kLights_fire = 7;
int constexpr kLights_rainbow_bounce = 8;
