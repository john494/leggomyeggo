#pragma config(Sensor, port5,  lineDetector,   sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port12, touchLED,       sensorVexIQ_ColorGrayscale)
#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	sleep(3000);

	int threshold = 790;      /* found by taking a reading on both DARK and LIGHT    */
														/* surfaces, adding them together, then dividing by 2. */

	clearTimer(T1);						// Resets timer T1 to start counting at 0

	while(time1[T1] < 14000)  // Loops code while timer T1 has counted less than 10 seconds
	{
		if(getColorValue(lineDetector) < threshold)
		{
			// counter-steer right:
			setMotorSpeed(leftMotor, 50);		//Set the leftMotor (motor1) to half power (50)
			setMotorSpeed(rightMotor, 0);   //Set the rightMotor (motor6) to off (0)
			setTouchLEDColor(touchLED, colorRed);
		}
		else
		{
			// counter-steer left:
			setMotorSpeed(leftMotor, 0);		//Set the leftMotor (motor1) to off (0)
			setMotorSpeed(rightMotor, 50);  //Set the rightMotor (motor6) to half power (50)
			setTouchLEDColor(touchLED, colorGreen);
		}
	}
}