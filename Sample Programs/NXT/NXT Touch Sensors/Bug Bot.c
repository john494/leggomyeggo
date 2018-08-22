#pragma config(Sensor, S1,     touchRight,          sensorTouch)
#pragma config(Sensor, S2,     touchLeft,           sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*--------------------------------------------------------------------------------------------------------*\
|*                                                                                                        *|
|*                                             - Bug Bot -                                                *|
|*                                            ROBOTC on NXT                                               *|
|*                                                                                                        *|
|*  This program allows your taskbot to move forward indefinately while monitoring two Touch Sensors.     *|
|*  If the right Touch Sensor is bumped, the robot will back up, turn left, and then continue moving      *|
|*  forward.  Likewise, if the left Touch Sensor is hit, the robot will back up, turn right, and then     *|
|*  continue moving forward.  (The Touch Sensors act like 'feelers' for the robot.)                       *|
|*                                                                                                        *|
|*                                        ROBOT CONFIGURATION                                             *|
|*    NOTES:                                                                                              *|
|*                                                                                                        *|
|*    MOTORS & SENSORS:                                                                                   *|
|*    [I/O Port]              [Name]              [Type]              [Description]                       *|
|*    Port C                  motorC              NXT                 Right motor                         *|
|*    Port B                  motorB              NXT                 Left motor                          *|
|*    Port 1                  touchRight          Touch Sensor        Right mounted                       *|
|*    Port 2                  touchLeft           Touch Sensor        Left mounted                        *|
\*---------------------------------------------------------------------------------------------------4246-*/


task main()
{
  int randTime;                           // Declare variable 'randTime' to hold a random amount of time later.

  wait1Msec(500);                         // Wait 500 milliseconds before running any further code.

  while(true)                             // Infinite loop (also represented by 'while(1)' and 'for(;;)' which is read as 'for ever').
  {
    motor[motorC] = 75;                   /* Motors A and B are run */
    motor[motorB] = 75;                   /* at a power level of 75 */

    if(SensorValue(touchRight) == 1)      // If the Right Touch Sensor is bumped (equal to 1):
    {
      motor[motorC] = -75;                      /* Motors A and B are run  */
      motor[motorB] = -75;                      /* at a power level of -75 */
      wait1Msec(750);                           /* for 750 milliseconds.   */

      motor[motorC] = 75;                       // Motor C is run forward at a power level of 75.
      motor[motorB] = -75;                      // Motor B is run backward at a power level of -75.
      randTime = random(2000);                  // 'randTime' is set to a random integer between 0 and 2000.
      wait1Msec(randTime);                      // Wait 'randTime' amount of milliseconds.
    }

    if(SensorValue(touchLeft) == 1)       // If the Left Touch Sensor is bumped (equal to 1):
    {
      motor[motorC] = -75;                      /* Motors A and B are run  */
      motor[motorB] = -75;                      /* at a power level of -75 */
      wait1Msec(750);                           /* for 750 milliseconds.   */

      motor[motorC] = -75;                      // Motor C is run backward at a power level of 75.
      motor[motorB] = 75;                       // Motor B is run forward at a power level of 75.
      randTime = random(2000);                  // 'randTime' is set to a random integer bteween 0 and 2000.
      wait1Msec(randTime);                      // Wait 'randTime' amount of milliseconds.
    }
  }
}
