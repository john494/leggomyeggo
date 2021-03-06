#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, encoder)
#pragma config(Motor,  motor10,         armMotor,      tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor11,         clawMotor,     tmotorVexIQ, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
  This program will use the VEX IQ Wirless Controller to drive your Clawbot. This program uses
  If/Else statements to provide a "threshold" for the transmitter - this allows your robot to
  come to a stop even if the joysticks on the Wireless Controller haven't perfectly returned to
  their zero position.

  Note: You will have to set ROBOTC to enable "Wireless Control" to use the VEX IQ joystick.

                            ROBOT CONFIGURATION: VEX IQ Clawbot
    MOTORS & SENSORS:
    [I/O Port]          [Name]              [Type]                			[Location]
    Port 1        			leftMotor           VEX IQ Motor		      			Left side motor
    Port 6       				rightMotor          VEX IQ Motor		      			Right side motor (reversed)
		Port 10							armMotor						VEX IQ Motor								Arm Up/Down motor
		Port 11							clawMotor						VEX IQ Motor								Claw Open/Close motor
------------------------------------------------------------------------------------------------*/

task main()
{
	int threshold = 10;
	while(true)
	{
		//If the ChannelA (left Y-Axis) is greater than the threshold value,
		//then we'll set the speed of the motor to vlaue from the joystick.
		if(getJoystickValue(ChA) > threshold || getJoystickValue(ChA) < -threshold)
		{
			setMotorSpeed(leftMotor, getJoystickValue(ChA));
		}
		else  //If less than the threshold, we'll set the motor to zero.
		{
			setMotorSpeed(leftMotor, 0);
		}

		//If the ChannelD (right Y-Axis) is greater than the threshold value,
		//then we'll set the speed of the motor to vlaue from the joystick.
		if(getJoystickValue(ChD) > threshold || getJoystickValue(ChD) < -threshold)
		{
			setMotorSpeed(rightMotor, getJoystickValue(ChD));
		}
		else  //If less than the threshold, we'll set the motor to zero.
		{
			setMotorSpeed(rightMotor, 0);
		}

		//If Button "L-Up" is pressed in, we'll set the arm motor to run in reverse.
		if(getJoystickValue(BtnLUp) == 1)
		{
			setMotorSpeed(armMotor, -127);
		}
		//If the "L-Up" isn't pressed, but "L-Down" is, we'll set the motor to run forward.
		else if(getJoystickValue(BtnLDown) == 1)
		{
			setMotorSpeed(armMotor, 127);
		}
		else  //If neither button is pressed, we'll set the motor off.
		{
			setMotorSpeed(armMotor, 0);
		}

		////If Button "L-Up" is pressed in, we'll set the arm motor to run in reverse.
		//if(getJoystickValue(BtnRUp) == 1)
		//{
		//	setMotorSpeed(clawMotor, -127);
		//}
		////If the "L-Up" isn't pressed, but "L-Down" is, we'll set the motor to run forward.
		//else if(getJoystickValue(BtnRDown) == 1)
		//{
		//	setMotorSpeed(clawMotor, 127);
		//}
		//else	//If neither button is pressed, we'll set the motor off.
		//{
		//	setMotorSpeed(clawMotor, 0);
		//}
	}
}
