
void vexIqGyroZeroAngle()
{
	for (int i = 0; i < 12; ++i)
	{
		if (SensorType[i] != sensorVexIQ_Gyro)
			continue;

		resetGyro(i);
	}
}

int nGyroAngle[12];
int nGyroRange[12];
TI2CGyroSensitivity nGyroSensitivity[12];
void readGyro()
{
	for (int i = 0; i < 12; ++i)
	{
		if (SensorType[i] != sensorVexIQ_Gyro)
			continue;

		nGyroAngle[i] = getGyroDegrees(i);
		nGyroRange[i] = getGyroRate(i);
		nGyroSensitivity[i] = getGyroSensitivity(i);
	}
}

task main()
{
	vexIqGyroZeroAngle();

	while (true)
	{
		readGyro();
		sleep(50);
	}
	return;
}
