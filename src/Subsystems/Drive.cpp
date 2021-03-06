// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Drive.h"
#include "../RobotMap.h"
#include "../Commands/driveCommand.h"
#include "Robot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Drive::Drive() : Subsystem("Drive") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftMotor1 = RobotMap::driveleftMotor1;
    leftMotor2 = RobotMap::driveleftMotor2;
    rightMotor1 = RobotMap::driverightMotor1;
    rightMotor2 = RobotMap::driverightMotor2;
    gyroDrive = RobotMap::drivegyroDrive;


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Drive::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
		SetDefaultCommand(new driveCommand());

}    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND



// Put methods for controlling this subsystem
// here. Call these from Commands.
double Drive::deadband(double JoystickVal, double DeadbandCutOff) {
	if (JoystickVal < DeadbandCutOff && JoystickVal > DeadbandCutOff*(-1)) {
		return 0;
	}
	else {
		return (JoystickVal - (abs(JoystickVal)/JoystickVal*DeadbandCutOff))/(1-DeadbandCutOff);
	}
}

void Drive::driveMethod(double left, double right) {
	Robot::drive->leftMotor1->Set(left);
	Robot::drive->leftMotor2->Set(left);
	Robot::drive->rightMotor1->Set(right*-1);
	Robot::drive->rightMotor2->Set(right*-1);
	SmartDashboard::PutNumber("Left2 pos",leftMotor2->GetEncPosition());
	SmartDashboard::PutNumber("Right2 pos",rightMotor2->GetEncPosition());
	SmartDashboard::PutNumber("Right2 volt",rightMotor2->GetEncVel());
	SmartDashboard::PutNumber("Left2 volt",leftMotor2->GetEncVel());
}

void Drive::ResetEncoders() {
		Robot::drive->leftMotor2->SetEncPosition(0);
		Robot::drive->rightMotor2->SetEncPosition(0);
}

bool Drive::CompareEncoders() {
	if (Robot::drive->leftMotor2->GetEncPosition() >= 1000 && Robot::drive->rightMotor2->GetEncPosition() >= 1000) {
		return true;
	}
	return false;
}

double Drive::getLeftEncPos() {
	return Robot::drive->leftMotor2->GetEncPosition();
}

double Drive::getRightEncPos() {
	return Robot::drive->rightMotor2->GetEncPosition();
}
