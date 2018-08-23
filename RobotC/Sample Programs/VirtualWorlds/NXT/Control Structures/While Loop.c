#pragma config(StandardModel, "RVW REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
While Loop

This program uses a "while" loop to instruct the robot to traverse a square 5 times by repeating moving
forward and turning behaviors 20 times. There is a two second pause at the beginning of the program.

A "while" loop checks the condition (the code following 'while' between the parenthesis) each time
before the code inside of the braces is run(or skipped, if conditions are not met).

The integer variable 'i' is needed to keep track of the number of times that the "while" loop has run.

Robot Model(s): NXT REMBOT

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        rightMotor          NXT Motor             Right side motor
Motor Port 3        leftMotor           NXT Motor             Left side motor

----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);						        // Robot waits for 2000 milliseconds before executing program

	int i = 0;									        // Declares integer variable 'i' and initializes it to 0

	while(i < 20)	//This while() loop repeats the code below while 'i' is less than 20
	{

		//Move forward at half power for 2 seconds
		motor[rightMotor] = 50;			      // Motor on motorB is run at half (50) power forward
		motor[leftMotor]  = 50;			      // Motor on motorC is run at half (50) power forward
		wait1Msec(2000);				          // Robot runs previous code for 2000 milliseconds before moving on

		//Turn Left at half power for 0.5 seconds
		motor[rightMotor] = 50;     	    // Motor on motorB is run at half (50) power forward
		motor[leftMotor]  = -50;    	    // Motor on motorC is run at half (-50) power reverse
		wait1Msec(1000);        	          // Robot runs previous code for 500 milliseconds before moving on

		i++;										          // Increment 'i' by 1 (same as "i = i + 1")

	}

}		                                  // Program ends, and the robot stops
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
