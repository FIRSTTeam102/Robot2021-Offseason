/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include <frc/Encoder.h>
#include <networktables/NetworkTableEntry.h>



class DriveTrain : public frc2::SubsystemBase {
	public:
		DriveTrain();
		void stop();
		void move(double left, double right);
		void tankDrive();
		void arcadeDrive();
		void toggleDrive();
		void setDriverJoystick(frc::XboxController* pDriverJoystick) {
			mpDriverJoystick = pDriverJoystick;
		};
		bool flipDrive();
		void resetEncs() { mLeftEnc.Reset(); mRightEnc.Reset(); }
		int getLEncs() { return mLeftEnc.Get(); }
		int getREncs() { return mRightEnc.Get(); }
		int getLEncDist() { return mLeftEnc.GetDistance(); }
		int getREncDist() { return mRightEnc.GetDistance(); }
		/* * Will be called periodically whenever the CommandScheduler runs. */
		void Periodic();

		double EncoderDistancePerPulse = 6 /* wheel diameter (in) */ * 3.14159 / 360 /* encoder CPR */ * 0.61538461538 /* 24:39 magic number - it went 39in when it was supposed to go 24in */;

	private:

		nt::NetworkTableEntry mShuffleboardSpeedScale;

		frc::XboxController* mpDriverJoystick;

		WPI_TalonSRX mDriveLeft1;
		WPI_TalonSRX mDriveLeft2;
		WPI_TalonSRX mDriveRight1;
		WPI_TalonSRX mDriveRight2;

		frc::Encoder mLeftEnc{8,9};
		frc::Encoder mRightEnc{7,6};

		frc::MotorControllerGroup mLeft{mDriveLeft1, mDriveLeft2};
		frc::MotorControllerGroup mRight{mDriveRight1, mDriveRight2};

		frc::DifferentialDrive mDrive{mLeft, mRight};
	
		bool on = false;
		bool inverted = false;

		// Components (e.g. motor controllers and sensors) should generally be
		// declared private and exposed only through public methods.
};
