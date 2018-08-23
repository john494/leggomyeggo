#pragma config(StandardModel, "VEX IQ Clawbot")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
  This program will use the VEX IQ Wirless Controller to drive your Clawbot. This program will use
  "Tank Mode" to enable two joysticks to drive the two main motors of the Clawbot.

  The 4 joystick axis on the VEX IQ Wireless Controller return values from -127 to +127.

  Note: You will have to set ROBOTC to enable "Wireless Control" to use the VEX IQ joystick.

                            ROBOT CONFIGURATION: VEX IQ Clawbot
    MOTORS & SENSORS:
    [I/O Port]          [Name]              [Type]                			[Location]
    Port 1        			leftMotor           VEX IQ Motor		      			Left side motor
    Port 6       				rightMotor          VEX IQ Motor		      			Right side motor (reversed)
		Port 10							armMotor						VEX IQ Motor								Arm Up/Down motor
		Port 11							clawMotor						VEX IQ Motor								Claw Open/Close motor
------------------------------------------------------------------------------------------------*/
#include "JoystickDriver.c"

task main()
{
	while(true) //Loop so our joystick values update as quickly as possible.
	{
		getJoystickSettings(joystick);
		setMotorSpeed(leftMotor, 	joystick.joy1_y1);
		setMotorSpeed(rightMotor, joystick.joy1_y2);
	}
}