
task main()
{

	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;

	nMotorEncoderTarget[motorB] = 2520;
	nMotorEncoderTarget[motorC] = 2520;

	motor[motorB] = 50;
	motor[motorC] = 50;
	wait1Msec(8000);	//Run for three seconds
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;

	motor[motorC] = 0;
	motor[motorB] = 100;
  wait1Msec(3000);
  //First Left and move
  nMotorEncoderTarget[motorB] = 1095;
	nMotorEncoderTarget[motorC] = 1095;
  motor[motorB] = 50;
	motor[motorC] = 50;
	wait1Msec(8000);	//Run for three seconds

	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
		motor[motorC] = 0;
	motor[motorB] = 100;
  wait1Msec(3000);

   nMotorEncoderTarget[motorB] = 1825;
	nMotorEncoderTarget[motorC] = 1825;
  motor[motorB] = 50;
	motor[motorC] = 50;
	wait1Msec(8000);	//Run for three seconds

}
