#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	setLEDColor(ledGreenFlash);

	setMotorSpeed(leftMotor, 50);
	setMotorSpeed(rightMotor, 50);
	sleep(3000);
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(2000);

	setLEDColor(ledOrange);

	setMotorSpeed(leftMotor, -50);
	setMotorSpeed(rightMotor, -50);
	sleep(3000);
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
}
