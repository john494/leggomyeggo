#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main()
{
	resetTimer(T1);
	repeatUntil (getTimer(T1, seconds) >= 60) {
		tankControl(JoyY2, JoyY1, 10);
		armControl(motorA, Btn5, Btn7, 75);
	}
}
