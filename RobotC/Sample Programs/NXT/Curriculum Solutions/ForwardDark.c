#pragma config(Sensor, S1,     lightSensor,    sensorLightActive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	while(SensorValue(lightSensor) > 43)
	{

		motor[motorC] = 50;
		motor[motorB] = 50;

	}

	motor[motorC] = 0;
	motor[motorB] = 0;
	wait1Msec(2000);

}
