#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	setMotorSpeed(leftMotor, 50);
	setMotorSpeed(rightMotor, 50);

	while (getColorReflected(colorSensor) > 30)
		sleep(1);

	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
}
