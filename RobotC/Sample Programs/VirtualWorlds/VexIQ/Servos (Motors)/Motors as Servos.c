#pragma config(StandardModel, "VEX IQ Clawbot")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
  The VEX IQ Motors can be used in "Servo" mode to make them run to a specific position at full speed.
  After the VEX IQ Motor in "Servo" mode has completed its movement, it hold it's position like
  a standard hobby servo motor.

  You can give a Servo any position value, positive or negative. Note that VEX IQ motors will move
  960 positions in one full rotation of the motor.

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
	resetMotorEncoder(armMotor); //Take current position as zero.

	setServoTarget(armMotor, 300);  //Enable Servo Mode and move to position 60.
	sleep(2000);
	setServoTarget(armMotor, 120);   //Enable Servo Mode and move to position 10.
	sleep(2000);
}