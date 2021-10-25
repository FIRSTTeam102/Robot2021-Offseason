/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/CameraServo.h"
#include <frc/Servo.h>
CameraServo::CameraServo():
    mCameraServoX{kCameraServoXIndex}, mCameraServoY{kCameraServoYIndex}
{
    cameraServoXPosition = 0.5;
    mCameraServoX.Set(cameraServoXPosition);
    cameraServoYPosition= 0.18;
    mCameraServoY.Set(cameraServoYPosition);
}

// This method will be called once per scheduler run
void CameraServo::Periodic() {}
void CameraServo::controlServoWithJoystick()
{
    //get the raw joystick x & y value

    double joyStickX = mpServoJoystick->GetRawAxis(4); 
    double joyStickY = mpServoJoystick->GetRawAxis(5);
    //printf("Joystick: %f, %f\n", joyStickX, joyStickY);
    double currServoXPos = mCameraServoX.Get();
    double currServoYPos = mCameraServoY.Get();
    
    if  (joyStickX >= -0.5 && joyStickX <= 0.5){
        //we might not really want a change
        joyStickX = 0;
        //printf("X Deadband triggered\n");
    }
    if (joyStickY >= -0.5 && joyStickY <= 0.5){
        //we might not really want a change - not touching the joystick
        joyStickY = 0;
        //printf("Y Deadband triggered\n");
    }
    horizontalPower = joyStickX/50;
    verticalPower = joyStickY/50;
    if(cameraServoXPosition >= 1 && horizontalPower > 0){ //Prevents servo position from exceeding range
       //do nothing on the horizontal move
       //printf("X too high\n");
    }
    else if(cameraServoXPosition <= 0 && horizontalPower < 0){
       //do nothing on the horizontal move
       //printf("X too low\n");
    }
    else {
        //the servo new position = old position + horizontalPower
      mCameraServoX.Set(currServoXPos - horizontalPower);
      //printf("Moving X to %f\n", currServoXPos - horizontalPower);
    }

    if(cameraServoYPosition >= 1 && verticalPower > 0){ //Prevents servo position from exceeding range
      //do nothing on the vertical
    }
    else if(cameraServoYPosition <= 0 && verticalPower < 0){
       //do nothing on the vertical
    }
    else {
        mCameraServoY.Set(currServoYPos - verticalPower );
    }
    // printf("Camera servo position: (%f, %f)\n", mCameraServoX.Get(), mCameraServoY.Get());
}
