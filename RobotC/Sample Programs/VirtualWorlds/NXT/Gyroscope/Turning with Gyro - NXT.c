#pragma config(StandardModel, "RVW REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Turning with Gyroscope
This program instructs your robot turn to the right until the desired number of degrees has been reached,
stop for two seconds, then turn to the left for until the desired number of degrees has been reached.
There is a two second pause at the beginning of the program.

Robot Model(s): NXT REMBOT

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        rightMotor          NXT Motor             Right side motor
Motor Port 3        leftMotor           NXT Motor             Left side motor
Sensor Port 2     	gyro				        HiTechnic Gyro

----------------------------------------------------------------------------------------------------*/

// This program turns the robot right for a specified 'degrees', stops the robot for two seconds,
// then turns to the left for the same amount of 'degrees'.

task main()
{
  wait1Msec(2000);
  int degrees = 900;                     // 'degrees' is how many degrees we want to turn

  int goal = (SensorValue[gyro] + degrees);  // 'goal' is be the current gyro reading + our turning degrees

  while(SensorValue[gyro] < goal)   		// while the gyro sensor reading is less than our goal:
  {
																				// turn RIGHT in place (point turn):
    motor[rightMotor] = -20;           	// set motorB to speed -20
    motor[leftMotor]  =  20;            // set motorC to speed 20
  }
                                        // stop the robot:
  motor[rightMotor] = 0;                // set motorB to speed 0
  motor[leftMotor]  = 0;                // set motorC to speed 0

  wait1Msec(2000);

  goal = (SensorValue[gyro] - degrees);  // 'goal' is be the current gyro reading - our turning degrees

  while(SensorValue[gyro] > goal)   		 // while the gyro sensor reading is less than our goal:
  {
																				 // turn LEFT in place (point turn):
    motor[rightMotor] = 	20;            // set motorB to speed 20
    motor[leftMotor]  =  -20;            // set motorC to speed -20
  }

}
