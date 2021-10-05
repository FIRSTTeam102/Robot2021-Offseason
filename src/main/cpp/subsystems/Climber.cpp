/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"
#include "RobotContainer.h"
#include "Constants.h"

Climber::Climber(frc::XboxController* pOperatorJoystick):  
    mClimbUpMotor{kClimbUpMotor},
    mClimbDownMotor{kClimbDownMotor},
    mTopSensor{kClimberTopSensor},
    mMidSensor{kClimberMidSensor},
    mBotSensor{kClimberBotSensor},
    mpOperatorJoystick{pOperatorJoystick}
{
    mClimbUpMotor.SetInverted(true);
    mClimbDownMotor.SetInverted(true);
}
//stop all climber motors
void Climber::StopClimb(){
    mClimbUpMotor.Set(0);
    mClimbDownMotor.Set(0);
}

//raise the climber
void Climber::Climb(){
    if (ClimbSpeed() > 0 && !isClimbUp()) {
        mClimbUpMotor.Set(ClimbSpeed());
        mClimbDownMotor.Set(0);
        //mClimbUpMotor.Set(-ClimbSpeed());
        //mClimbDownMotor.Set(ClimbSpeed()); //For unraveling winch
    }
    else if (ClimbSpeed() < 0 && !isClimbDown()) {
        mClimbUpMotor.Set(ClimbSpeed() * kTakeUpSlackPercent);
        mClimbDownMotor.Set(ClimbSpeed());
    }
    else {
        StopClimb();
    }
}
// This method will be called once per scheduler run
void Climber::Periodic()  {

}