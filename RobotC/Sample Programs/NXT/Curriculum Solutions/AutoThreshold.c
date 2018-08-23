#pragma config(Sensor, S1,     touchSensor,    sensorTouch)
#pragma config(Sensor, S2,     lightSensor,    sensorLightActive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/* This program is designed to find a good threshold value for the NXT light sensor.
It requires the user to follow the nxt screen's instructions, then hit the touch sensor to continue.
If the touch sensor is accidentally pressed, the program will have to be restarted.
When the program asks, put the NXT light sensor over either the light surface or the dark surface that you want to compare.
The program will read the two sensor values and average them to find a good middle threshold, then display that threshold value.*/

task main()
{

	int lightValue;
	int darkValue;
	int sumValue;
	int thresholdValue;

	while(SensorValue(touchSensor) == 0)
	{
		displayStringAt(0,31,"Read Light Now");
	}

	lightValue = SensorValue(lightSensor);

	wait1Msec(1000);

	while(SensorValue(touchSensor) == 0)
	{
		displayStringAt(0,31,"Read Dark Now");
	}

	darkValue = SensorValue(lightSensor);

	sumValue = lightValue + darkValue;
	thresholdValue = sumValue/2;

	displayStringAt(0,31,"%d", thresholdValue);
	wait1Msec(60000);
}
