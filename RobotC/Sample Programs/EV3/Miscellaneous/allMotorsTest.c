#pragma config(Motor,  motorA,          motA,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          motB,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          motC,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          motD,          tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task showEncoders()
{
	long encA, encB, encC, encD = 0;
	float rpmA, rpmB, rpmC, rpmD = 0.0;

	while (true)
	{
		encA = getMotorEncoder(motorA);
		encB = getMotorEncoder(motorB);
		encC = getMotorEncoder(motorC);
		encD = getMotorEncoder(motorD);

		rpmA = getMotorRPM(motorA);
		rpmB = getMotorRPM(motorB);
		rpmC = getMotorRPM(motorC);
		rpmD = getMotorRPM(motorD);

		displayTextLine(3, "motorA: %5d (%3.1f rpm)", encA, rpmA);
    displayTextLine(4, "motorA: %5d (%3.1f rpm)", encB, rpmB);
    displayTextLine(5, "motorA: %5d (%3.1f rpm)", encC, rpmC);
    displayTextLine(6, "motorA: %5d (%3.1f rpm)", encD, rpmD);

    displayTextLine(7, "motorA: %s", (getMotorBrakeMode(motorA) == 0) ? "coast" : "brake");
    displayTextLine(8, "motorB: %s", (getMotorBrakeMode(motorB) == 0) ? "coast" : "brake");
    displayTextLine(9, "motorC: %s", (getMotorBrakeMode(motorC) == 0) ? "coast" : "brake");
    displayTextLine(10, "motorD: %s", (getMotorBrakeMode(motorD) == 0) ? "coast" : "brake");
		sleep(100);
	}
}

void doSyncEncoderTest()
{
	displayBigTextLine(0, "Sync Encoder");
	setMotorSyncEncoder(motorA, motorB, 0, 360, 50);
	sleep(3000);
	setMotorSyncEncoder(motorA, motorC, 0, 360, 50);
	sleep(3000);
	setMotorSyncEncoder(motorA, motorD, 0, 360, 50);
	sleep(3000);
	setMotorSyncEncoder(motorB, motorC, 0, 360, 50);
	sleep(3000);
	setMotorSyncEncoder(motorB, motorD, 0, 360, 50);
	sleep(3000);
	setMotorSyncEncoder(motorC, motorD, 0, 360, 50);
	sleep(3000);
}

void doSyncTimeTest()
{
	displayBigTextLine(0, "Sync Time");
	setMotorSyncEncoder(motorA, motorB, 0, 2000, 50);
	sleep(3000);
	setMotorSyncEncoder(motorA, motorC, 0, 2000, 50);
	sleep(3000);
	setMotorSyncEncoder(motorA, motorD, 0, 2000, 50);
	sleep(3000);
	setMotorSyncEncoder(motorB, motorC, 0, 2000, 50);
	sleep(3000);
	setMotorSyncEncoder(motorB, motorD, 0, 2000, 50);
	sleep(3000);
	setMotorSyncEncoder(motorC, motorD, 0, 2000, 50);
	sleep(3000);
}

void doSetBrakeModes()
{
	// set random brake modes
	setMotorBrakeMode(motorA, (rand() % 2));
	setMotorBrakeMode(motorB, (rand() % 2));
	setMotorBrakeMode(motorC, (rand() % 2));
	setMotorBrakeMode(motorD, (rand() % 2));
}

task main()
{
	eraseDisplay();
	startTask(showEncoders);
	while (true)
	{
		doSyncEncoderTest();
		doSyncTimeTest();
		sleep(500);
		doSetBrakeModes();
	}
}
