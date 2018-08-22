#pragma config(Sensor, S1,     touchSensor,    sensorTouch)
#pragma config(Sensor, S2,     compassSensor,  sensorVirtualCompass)
#pragma config(Sensor, S3,     lineFollower,   sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,    sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Sector 2 - West Road Insertion Point (Standard ROBOTC)
- This program will cause the robot pick up the Charge Cube along West Road using feedback from
	the Sonar Sensor.
- It will be up to you to deliver the Charge Cube to the Communication Tower Pad in Sector 2.
- Remember that you can press the "Reset" button in the lower-left corner of the Operation Reset
	window to return to the Insertion Point every time you modify your ROBOTC code.
*	Please note that the values in this program were written for Mammalbot using a high-end computer.
	You may need to adjust the values in this program for your computer.

Robot Model: Mammalbot

[I/O Port]          [Name]              [Type]                   [Description]
Motor Port A        gripperMotor        Motor        		    		 Front gripper motor
Motor Port B        rightMotor          Motor w/ Encoder       	 Right side motor
Motor Port C        leftMotor           Motor w/ Encoder       	 Left side motor
Sensor Port 4				sonarSensor					Sonar Sensor						 Sensor facing front center
----------------------------------------------------------------------------------------------------*/

//Every program has a task main(). All commands that the robot follows go between the curly braces.
task main()
{	//The program begins.
	wait1Msec(2000);		//The robot will wait for 2 seconds before executing commands.

  while(SensorValue[sonarSensor] > 20)	//while the robot is more than 20 cm away from an object...
	{
		//...move forward.
		motor[rightMotor] = 50;
		motor[leftMotor] = 50;
	}

	//Stop
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;

	//Enter the code for the robot to turn toward Sector 2 here:


	//Enter the code for the robot to drive forward into Sector 2 here:


	//Enter the code for the robot to turn toward the Communication Tower pad here:


	//Enter the code for the robot to drive to the Communication Tower pad here:


}	//The program ends.