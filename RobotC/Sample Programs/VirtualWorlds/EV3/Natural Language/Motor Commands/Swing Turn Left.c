#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	setMotor(rightMotor, 50);
	stopMotor(leftMotor);
	wait(2500, milliseconds);
	stopAllMotors();
}
