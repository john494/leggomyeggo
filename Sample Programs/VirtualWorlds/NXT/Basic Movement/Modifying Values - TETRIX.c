#pragma config(StandardModel, "RVW RANGER")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Modifying Values

This program instructs your robot to move forward at half power for 1.5 seconds, brake for 1
second, reverse for 1.5 seconds, and turn left for 0.75 seconds.  There is a two second pause at
the beginning of the program.

Robot Model(s): TETRIX Ranger

[I/O Port]          [Name]              [Type]                		[Description]
mtr_S1_C1_1        rightMotor          TETRIX Motor             Right side motor
mtr_S1_C1_2        leftMotor           TETRIX Motor             Left side motor, reversed

----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  wait1Msec(2000);						  // Robot waits for 2000 milliseconds before executing program

  // Move forward at half power for 1.5 seconds
  motor[rightMotor] = 50;			  // Motor on motorB is run at half (50) power forward
  motor[leftMotor]  = 50;			  // Motor on motorC is run at half (50) power forward
  wait1Msec(1500);				      // Robot runs previous code for 1500 milliseconds before moving on

  // Brake for 1 second
  motor[rightMotor] = 0;				// Motor on motorB is turned off
  motor[leftMotor]  = 0;				// Motor on motorC is turned off
  wait1Msec(1000);				      // Robot runs previous code for 1000 milliseconds before moving on

  // Move reverse at half power for 1.5 seconds
  motor[rightMotor] = -50;			// Motor on motorB is run at half (50) power reverse
  motor[leftMotor]  = -50;			// Motor on motorC is run at half (50) power reverse
  wait1Msec(1500);				      // Robot runs previous code for 1500 milliseconds before moving on

  // Turn left at full power for 0.75 seconds
  motor[rightMotor] = 100;			// Motor on motorB is run at full (100) power forward
  motor[leftMotor]  = -100;		  // Motor on motorC is run at full (-100) power reverse
  wait1Msec(750);					      // Robot runs previous code for 750 milliseconds before moving on
}													      // Program ends, and the robot stops
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
