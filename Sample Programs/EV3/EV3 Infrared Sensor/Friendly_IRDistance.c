#pragma config(Sensor, S4,     irSensor,       sensorEV3_IRSensor)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
This program assumes you are using the standard LEGO Education robot
Sensor Ports:
S4 = IR (Infrared)

Motor Ports:
A = Arm Motor
B = Right Motor
C = Left Motor
*/

task main()
{
	long nDistance = 0;

	while (true)
	{
		// Distance returned in percent.  The returned value will depend on the material
	  // that the sensor is pointed at.  You have to do some tests yourself
	  // to determine which return value corresponds to what distance.
		nDistance = getIRDistance(irSensor);

	  writeDebugStreamLine("Distance detected: %d", nDistance);
		sleep(100);
	}
	return;
}
