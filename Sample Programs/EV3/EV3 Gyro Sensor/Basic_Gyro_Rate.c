#pragma config(Sensor, S4,     Gyro,           sensorEV3_Gyro, modeEV3Gyro_Rate)
#pragma config(Motor,  motorB,          motorLeft,     tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Gyro modes
0 - modeEV3Gyro_Angle
1 - modeEV3Gyro_Rate
2 - modeEV3Gyro_Fast
3 - modeEV3Gyro_RateAndAngle
4 - modeEV3Gyro_Calibration - Not utilized
*/

task main()
{
	int gyroRate = 0;

	// The code below will turn the motor proportionally to the gyro rate
	while (true)
	{
		// Read the current rate value in degrees/second
		gyroRate = SensorValue[Gyro];

		displayCenteredBigTextLine(4, "Gyro: %d", gyroRate);
		// Clip the value of the gyro to -100 to +100 (min and max motor speeds)
		if (gyroRate > 100)
			gyroRate = 100;
		else if (gyroRate < -100)
			gyroRate = -100;

		// Set motor speeds to the rate of the gyro
		motor[motorLeft] = gyroRate;
		sleep(50);
	}
}