/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "subsystems/ControlPanelManipulator.h"
#include <frc/smartdashboard/SmartDashboard.h>

ControlPanelManipulator::ControlPanelManipulator():
    //controlMotor{controlPanelMotorIndex},
	controlMotor{0},
	colorSensor{frc::I2C::Port::kOnboard}
{
    turnCounter = 0;
	previousColor = 0;
	//IMPORTANT!!!!!!! ALL VALUES MUST HAVE AT LEAST SLIGHTLY DIFFERENT RED VALUES (check blue vs green)
	blue.red = 0.13;
  	blue.green = 0.43;
  	blue.blue = 0.43;
  	red.red = 0.56;
  	red.green = 0.32;
  	red.blue = 0.11;
  	yellow.red = 0.33;
  	yellow.green = 0.56;
  	yellow.blue = 0.11;
  	green.red = 0.14;
  	green.green = 0.60;
  	green.blue = 0.26;
	matching.AddColorMatch(blue);
	matching.AddColorMatch(red);
	matching.AddColorMatch(yellow);
	matching.AddColorMatch(green);
	finished = false;
	colorSensor.ConfigureColorSensor(rev::ColorSensorV3::ColorResolution::k13bit, rev::ColorSensorV3::ColorMeasurementRate::k25ms);
}

void ControlPanelManipulator::resetFinished() {
	finished = false;
	previousColor = getReadColor();
}

/* turns to a color specified by "targetColor" */
void ControlPanelManipulator::positionControl(char targetColor) { //land on color after 3 rotations
	currentColor = getReadColor();
	if (targetColor != currentColor || !hasMovedColors()) { //if not on target color
		controlMotor.Set(1); //spin motor?
		//Stage previous colors (used to be in the middle)
		/*for (int i = 3; i >= 0; i--) {
			prevColors[i+1] = prevColors[i];
		}
		prevColors[0] = currentColor;*/
		previousColor = currentColor;
	}
	else {
		controlMotor.Set(0); //stop motor?
		finished = true; //run "is finished"
	}
	//printf("%c vs %c (prev %c)\n", currentColor, targetColor, prevColors[4]);
	printf("%c vs %c (prev %c)\n", currentColor, targetColor, previousColor);
}

/* rotates the control panel >= 3 times */
void ControlPanelManipulator::rotationControl() { //rotate 3 times
	currentColor = getReadColor();
	//if(hasMovedColors()){ //if new color reached
	if (hasMovedColors()) {
		turnCounter += 1; //+1 1/8th of a rotation
		previousColor = currentColor;
	}
	if (turnCounter < 24) { //8 colors per rotation (x3)
		controlMotor.Set(1);
	}
	else { //turnCounter starts at 0; if rotated >= 3 times
		controlMotor.Set(0); //stop motor
		turnCounter = 0; //reset turnCounter
		finished = true;//run is finished
	}
	printf("Iter #%d\nHas moved: %d\nCurrent color: %c\nPrevious color: %c\n", turnCounter, hasMovedColors(), currentColor, previousColor);
	printColor();
	//printf("Iter %d\n",turnCounter);
}

bool ControlPanelManipulator::hasMovedColors() {
	//printf("Was: %c / Is: %c\n",previousColor,currentColor);
	switch(previousColor){
	case 'Y':
		if(currentColor == 'B'){
			return true;
		}
		break;
	case 'B':
		if(currentColor == 'G'){
			return true;
		}
		break;
	case 'G':
		if(currentColor == 'R'){
			return true;
		}
		break;
	case 'R':
		if(currentColor == 'Y'){
			return true;
		}
		break;
	}

	return false;
}

void ControlPanelManipulator::printColor() {
	frc::SmartDashboard::PutNumber("Red", matching.MatchClosestColor(colorSensor.GetColor(), confidence).red);
	frc::SmartDashboard::PutNumber("Green", matching.MatchClosestColor(colorSensor.GetColor(), confidence).green);
	frc::SmartDashboard::PutNumber("Blue", matching.MatchClosestColor(colorSensor.GetColor(), confidence).blue);
	frc::SmartDashboard::PutNumber("Confidence", confidence);
	frc::SmartDashboard::PutNumber("Color", getReadColor());
	printf("Printing color\n");
}

char ControlPanelManipulator::getReadColor() {
	rawColor = matching.MatchClosestColor(colorSensor.GetColor(), confidence);
	if (rawColor == blue) {
		return 'B';
	}
	else if (rawColor == green) {
		return 'G';
	}
	else if (rawColor == red) {
		return 'R';
	}
	else if (rawColor == yellow) {
		return 'Y';
	}
	else {
		return 'X';
	}
}

bool ControlPanelManipulator::getFinished() {
	return finished;
}

// This method will be called once per scheduler run
void ControlPanelManipulator::Periodic() {}
