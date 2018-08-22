#pragma config(Sensor, S1,     lightSensor,    sensorLightActive)
#pragma config(Sensor, S2,     touchSensor,    sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	nMotorEncoder[motorC] = 0;
	nMotorEncoder[motorB] = 0;

	while(nMotorEncoder[motorC] < 1800 && nMotorEncoder[motorB] < 1800)
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
