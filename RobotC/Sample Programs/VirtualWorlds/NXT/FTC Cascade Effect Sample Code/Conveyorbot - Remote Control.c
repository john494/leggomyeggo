#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     armMotor,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     intakeMotor,   tmotorTetrix, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Conveyorbot - Remote Control
- NOTE: Conveyorbot can be used to pick up 4 of the game objects with its intake and score them
anywhere on the field.
- This program allows you to remotely control your robot using the USB Logitech Joysticks.
- This program also ignores low values that would cause your robot to move when the joysticks fail to
return back to exact center.  You may need to adjust the 'threshold' value to get it just right.

Robot Model(s): TETRIX Conveyorbot (Virtual Worlds)
[I/O Port]          [Name]              [Type]                [Description]
Motor Port D        rightMotor          TETRIX Motor          Right side motor
Motor Port E				leftMotor						TETRIX Motor					Left side motor
Motor Port F 				armMotor						TETRIX Motor					Arm motor
Motor Port G 				intakeMotor					TETRIX Motor 					Intake motor

Sensor Port 2				gyro								HiTechnic Gyro				HiTechnic Gyro
Sensor Port 3				light   						Light Sensor					NXT Light Sensor (Active)
Sensor Port 4				sonar 							Sonar Sensor					NXT Sonar Sensor
----------------------------------------------------------------------------------------------------*/

#pragma debuggerWindows("joystickSimple");
#include "JoystickDriver.c"

task main()
{
	//Integer variable that allows you to specify a "deadzone" where values (both positive or negative)
	//less than the threshold will be ignored.
	int threshold = 10;

	while(1 == 1) //Loop Forever
	{
		//Get the Latest joystick values
		getJoystickSettings(joystick);

		//Driving Control
		if(abs(joystick.joy1_y2) > threshold)     // If the right analog stick's Y-axis readings are either above or below the threshold...
		{
			motor[rightMotor] = joystick.joy1_y2;				// ...move the right side of the robot.
		}
		else                                      // Else the readings are within the threshold, so...
		{
			motor[rightMotor] = 0;											// ...stop the right side of the robot.
		}
		if(abs(joystick.joy1_y1) > threshold)     // If the left analog stick's Y-axis readings are either above or below the threshold...
		{
			motor[leftMotor] = joystick.joy1_y1;				// ...move the left side of the robot.
		}
		else                                      // Else the readings are within the threshold, so...
		{
			motor[leftMotor] = 0;											// ...stop the left side of the robot.
		}

		//Arm Motor Control
		if(joy1Btn(6) == 1)       // If button 6 (RB) is pressed...
		{
			motor[armMotor] = 35;     // ...raise the arm.
		}
		else if(joy1Btn(8) == 1)  // Else, if button 8 (RT) is pressed...
		{
			motor[armMotor] = -35;    // ...lower the arm.
		}
		else                      // Else (neither button is pressed)...
		{
			motor[armMotor] = 0;      // ...stop the arm.
		}

		//Intake Motor Control
		if(joy1Btn(5) == 1)       // If button 5 (LB) is pressed...
		{
			motor[intakeMotor] = 75;     //...run the intake inward.
		}
		else if(joy1Btn(7) == 1)  // Else, if button 7 (LT) is pressed...
		{
			motor[intakeMotor] = -75;    // ...run the intake outward.
		}
		else                      // Else (neither button is pressed)...
		{
			motor[intakeMotor] = 0;      // ...stop rotating the intake.
		}
	}
}
