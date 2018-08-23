#pragma config(StandardModel, "VEX IQ Clawbot")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
  This program will set the drive motors to a number of different strength options.
  You can adjust the strength of a motor in the scenario of a gripper arm trying to pick up a
  delicate object. By lowering the strength of the motor, it will allow you to apply less force.

  The strength of the motor is a value ranging between 0-255, where each "count" equates to roughly
  15mA (current). A value of 66 would be approx. 1A fuse setting.

  The default value is 255 (full strength).

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
	//************* Try to apply resistance to the motor while running *********************//

	//Engage the Claw at Power 50.
	setMotorSpeed(clawMotor, 50);
	setMotorStrength(clawMotor, 130);  //Approx. 2Amp Fuse Setting
	sleep(5000);

	//Disengage the claw
	setMotorSpeed(clawMotor, 0);
	sleep(500);

	//Engage the Claw at Power 50, but with lower fuse setting.
	setMotorSpeed(clawMotor, 60);
	setMotorStrength(clawMotor, 65);  //Approx. 1Amp Fuse Setting
	sleep(5000);


}
