#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (getTouchValue(touchSensor) != 1)
	{
		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, 50);
	}
}