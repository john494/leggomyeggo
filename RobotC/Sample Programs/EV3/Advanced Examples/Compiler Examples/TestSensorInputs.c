#pragma config(Sensor, S1,     ultrasonic1,    sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     color2,         sensorEV3_Color)
#pragma config(Sensor, S3,     gyro3,          sensorEV3_Gyro)
#pragma config(Sensor, S4,     touch4,         sensorEV3_Touch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

long nSensorValues[4];

task main()
{
	while(true)
	{
		nSensorValues[0] = SensorValue[S1];
		nSensorValues[1] = SensorValue[S2];
		nSensorValues[2] = SensorValue[S3];
		nSensorValues[3] = SensorValue[S4];
		sleep(10);
	}
}
