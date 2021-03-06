#pragma config(Sensor, S1,     touchSensor,    sensorTouch)
#pragma config(Sensor, S2,     compassSensor,  sensorVirtualCompass)
#pragma config(Sensor, S3,     lineFollower,   sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,    sensorSONAR)
#pragma config(Motor,  motorA,          vacuumMotor,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
C6 Lift Road Insertion Point (Standard ROBOTC)
- This program will cause the robot to track the line from Sector 1 to the intersection with the
	Lift and Tunnel.
- It will be up to you to choose whether to take the Lift or the path with the Tunnel and write the
	ROBOTC code to cause the robot to do so. Note that if you take the lift, you should plan on having
	the robot stop and wait for several seconds before moving on.
- Remember that you can press the "Reset" button in the lower-left corner of the Operation Reset
	window to return to the Insertion Point every time you modify your ROBOTC code.
*	Please note that the values in this program were written for Mammalbot using a high-end computer.
	You may need to adjust the values in this program for your computer.

Robot Model: Mammalbot

[I/O Port]          [Name]              [Type]                   [Description]
Motor Port B        rightMotor          Motor        		    		 Right side motor
Motor Port C        leftMotor           Motor          		   	   Left side motor
Sensor Port 3				lineFollower				Line Following Sensor		 Sensor facing bottom center
----------------------------------------------------------------------------------------------------*/

//Every program has a task main(). All commands that the robot follows go between the curly braces.
task main()
{	//The program begins.
	wait1Msec(2000);		//The robot will wait for 2 seconds before executing commands.

	//threshold is an integer variable that stores a value that is in between the white and black...
	//...line following values. It allows the robot to make decisions to track the line.
	int threshold = 25;

	//While less than 6675 counts of the right encoder have elapsed...
	while(nMotorEncoder[rightMotor] < 6675)
	{
		//...track the line.
		if(SensorValue[lineFollower] > threshold) //If the sensor sees white...
		{
			//...counter-steer right.
			motor[leftMotor]  = 50;
			motor[rightMotor] = 0;
		}
		else //Else, the sensor sees dark...
		{
			//...counter-steer left.
			motor[leftMotor]  = 0;
			motor[rightMotor] = 50;
		}
	}

	//Stop
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;

	wait1Msec(1000);		//The robot will wait for 1 second before executing other commands.

	//Choose whether the robot should ride the Lift or travel the Tunnel. Add your code here:


}	//The program ends.
