#pragma config(Sensor, S1,     lightSensor,    sensorLightActive)
#pragma config(Sensor, S2,     touchSensor,    sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	while(SensorValue(touchSensor) == 0)
	{

		if(SensorValue(lightSensor) < 43)
		{

			motor[motorC] = 0;
			motor[motorB] = 80;

		}

		else
		{

			motor[motorC] = 80;
			motor[motorB] = 0;

		}

	}

	motor[motorC] = 0;
	motor[motorB] = 0;

}
