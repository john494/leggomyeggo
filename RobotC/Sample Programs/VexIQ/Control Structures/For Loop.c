#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
  This program uses a "for" loop to instruct the robot to traverse a square 5 times by repeating
  moving forward and turning behaviors 20 times.
  There is a two second pause at the beginning of the program.

    1)  A "for" loop is more condensed than a "while" loop; it declares and initializes the
        variable, makes a comparison for the condition, and increments the variable all in the
        first line (declaration).
    2)  The integer variable 'i' is needed to keep track of the number of times that the "for"
        loop has run.

                            ROBOT CONFIGURATION: VEX IQ Clawbot
    MOTORS & SENSORS:
    [I/O Port]          [Name]              [Type]                			[Location]
    Port 1        			leftMotor           VEX IQ Motor		      			Left side motor
    Port 6       				rightMotor          VEX IQ Motor		      			Right side motor (reversed)

------------------------------------------------------------------------------------------------*/

task main()
{
	for(int i = 0; i < 20; i++)   /* This for() loop:  declares the integer 'i' and initializes it to 0,                           */
	{                             /* repeats the code as long as 'i' is less than 20, and increments 'i' by 1 after each iteration */

		//Move forward at half power for 2 seconds
		setMotorSpeed(leftMotor, 50);		//Set the leftMotor (motor1) to half power (50)
		setMotorSpeed(rightMotor, 50);  //Set the rightMotor (motor6) to half power (50)
		sleep(2000);										//Wait for 2 seconds before continuing on in the program.

		//Turn Left at half power for 0.5 seconds
		setMotorSpeed(leftMotor, -50);	//Set the leftMotor (motor1) to half power reversed (-50)
		setMotorSpeed(rightMotor, 50);  //Set the rightMotor (motor6) to half power (50)
		sleep(500);											//Wait for 0.5 seconds before continuing on in the program.
	}
}														        // Program ends, and the robot stops
