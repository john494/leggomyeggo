#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                            - Single Joystick Control with Thresholds -                             *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses both the Left and the Right joysticks to run the robot using "tank control".    *|
|*  It also uses a threshold value to ignore low readings from the joystick.  This eliminates         *|
|*  "noise" from joysticks that have not returned exactly to (0,0) which is common.                   *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*    3)  'abs(z)' is the ABSOLUTE VALUE of 'z'.                                                      *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 3          leftMotor            VEX Motor           Left motor                     *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{
  int threshold = 10;   // helps to eliminate 'noise' from a joystick that isn't perfectly at (0,0)
                        // feel free to change this to match your needs.

  while(1 == 1)
  {
    if(abs(vexRT[Ch3]) > threshold)         // If the left joystick is greater than or less than the threshold:
    {
      motor[leftMotor]  = (vexRT[Ch3])/2;   // Left Joystick Y value / 2.
    }
    else                                    // If the left joystick is within the threshold:
    {
      motor[leftMotor]  = 0;                // Stop the left motor (cancel noise)
    }

    if(abs(vexRT[Ch2]) > threshold)         // If the right joystick is greater than or less than the threshold:
    {
      motor[rightMotor] = (vexRT[Ch2])/2;   // Right Joystick Y value / 2.
    }
    else                                    // If the right joystick is within the threshold:
    {
      motor[rightMotor] = 0;                // Stop the right motor (cancel noise)
    }
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
