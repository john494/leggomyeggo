#pragma config(Sensor, S4,     sonarSensor,         sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*--------------------------------------------------------------------------------------------------------*\
|*                                                                                                        *|
|*                                   - Smooth Sonar Tracking Program -                                    *|
|*                                            ROBOTC on NXT                                               *|
|*                                                                                                        *|
|*  This program is much smoother compared to the 'Bad Sonar Sensing Program'.  It uses the values read   *|
|*  in by the Sonar Sensor to adjust the speed of the motors so that the robot comes to a smooth halt     *|
|*  when it reaches the desired distance in cm (in this case '35').  It also maintains this distance      *|
|*  by reversing when the object comes closer than the specified distance.                                *|
|*                                                                                                        *|
|*                                        ROBOT CONFIGURATION                                             *|
|*    NOTES:                                                                                              *|
|*    1)  The Sonar Sensor should be somewhere on the FRONT of the robot, facing FORWARD.                 *|
|*                                                                                                        *|
|*    MOTORS & SENSORS:                                                                                   *|
|*    [I/O Port]              [Name]              [Type]              [Description]                       *|
|*    Port C                  motorC              NXT                 Right motor                         *|
|*    Port B                  motorB              NXT                 Left motor                          *|
|*    Port 4                  sonarSensor         Sonar Sensor        Front mounted, front facing         *|
\*---------------------------------------------------------------------------------------------------4246-*/


task main()
{
  int speed = 0;          // Will hold the speed of the motors.
  int sonarValue = 0;     // Will hold the values read in by the Sonar Sensor.
  int distance = 35;      // Specified distance to be at 35 centimeters.

  while(true)        // (infinite loop, also represented by 'while(1)' or, if you are feeling devious, 'for(;;)' which is read as 'for ever').
  {
    sonarValue = SensorValue(sonarSensor);                // Store Sonar Sensor values in 'sonarValue' variable.
    displayCenteredTextLine(0, "Sonar Reading");       /* Display Sonar Sensor values */
    displayCenteredBigTextLine(2, "%d", sonarValue);   /* to LCD screen using %d.     */

    wait1Msec(100);                                       // Only update the screen every 100 milliseconds.

    speed = (SensorValue(sonarSensor) - distance);        // Variable 'speed' is set to the reading of the Sonar Sensor - some distance in centimeters (here we used 35cm).

    if(speed > 100)
    {
      speed = 100;                                        // Check to see if calculated speed is greater than 100, if so make it 100.
    }

    displayCenteredTextLine(5, "%d", speed);           /* Display variable 'speed' to the LCD.       */
    displayCenteredTextLine(7, "Motor Speed");         /* (which is the current speed of the motors) */

    motor[motorC] = speed;                                // Set Motor C is run at a power level equal to 'speed'.
    motor[motorB] = speed;                                // Set motor B is run at a power level equal to 'speed'.
  }
}


/*


                 NXT Display
						 __________________
						|   Sonar  Value   |
						|      ##  ##      |
						|      ##  ##      |
						|                  |
						|        ##        |
						|___Motor__Speed___|

*/