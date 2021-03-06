#pragma config(Sensor, S4,     sonar4,         sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          motorLeft,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          motorRight,    tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	// Distance to maintain to the target (30 cm)
	const int distanceToMaintain = 30;

	int currentDistance = 0;

	while(true)
	{
		// Read the sensor
		currentDistance = SensorValue[sonar4];
		displayCenteredBigTextLine(4, "Dist: %3d cm", currentDistance);

		// We're too far away, move forward
		if ((distanceToMaintain - currentDistance) < -2)
		{
			motor[motorLeft] = 30;
			motor[motorRight] = 30;
		}
		// We're too close, move backwards
		else if ((distanceToMaintain - currentDistance) > 2)
		{
			motor[motorLeft] = -30;
			motor[motorRight] = -30;
		}
		// We're good, don't go anywhere
		else
		{
			motor[motorLeft] = 0;
			motor[motorRight] = 0;
		}

		//Loop to monitor value in Sensor debugger window
		sleep(50);
	}
}
