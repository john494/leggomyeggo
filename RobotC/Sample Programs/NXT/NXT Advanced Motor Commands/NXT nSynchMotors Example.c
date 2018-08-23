

//                  Synchronized Motor Examples
//
//  There are three programs below.  The first program sychronizes motors B and C
//  where motor B is the master and motor C is the slave.(Lines 20-31)  The motors
//  in this synchronized example are turned on for an amount of time and then stop.
//
//  The second program(lines 35-52), which is commented out, but can be uncommented
//  and run.  This program uses a combination of synchronized motors and feedback
//  from the motor encoders to travel a specific distance.
//
//  The third program (lines 56-77), also commented out, uses a combination of
//  the sychronized motor function, feedback from encoders, and nMotorTargetEncoder
//  function to accurately travel a specific distance.
//
// 	You can copy any of these examples to use in your own programs



// This program example uses syncronized motors and timing
task main()
{

  nSyncedMotors = synchBC; //motor B is the master, motor C is the slave
  nSyncedTurnRatio = 100; //motors move at 100% alignment to each other

  motor[motorB] = 30; //turn motor B on, which controls motor C at 30% power
  wait1Msec(2000);  // wait for two seconds

  motor[motorB] = 0;  // turn the motors off.

}


/*
// This program example uses synchronized motors and feedback from encoders.
task main()
{

  nSyncedMotors = synchBC; //motor B is the master, motor C is the slave
  nSyncedTurnRatio = 100; //motors move at 100% alignment to each other

  nMotorEncoder[motorB] = 0;

  while(nMotorEncoder[motorB] < 720)
  {
  motor[motorB] = 30; //turn motor B on, which controls motor C at 30% power
  }

  motor[motorB] = 0;  // turn the motors off.

  wait1Msec(3000);

}
*/

/*
// This program example uses synchronized motors, feedback from encoders and the nMotorEncoderTarget function
task main()
{

  nSyncedMotors = synchBC; //motor B is the master, motor C is the slave
  nSyncedTurnRatio = 100; //motors move at 100% alignment to each other

  nMotorEncoder[motorB] = 0; //reset the value of motorB's encoder to zero

  nMotorEncoderTarget[motorB] = 720; //set motorB's target position to 720

  motor[motorB] = 30; //power motorB at 30% power

  while(nMotorRunState[motorB] != runStateIdle)//while motorB is not in an idle position
  {
   //continue to monitor nMotorEncoderTarget's target position
  }

  motor[motorB] = 0;  // turn the motors off.

  wait1Msec(3000);

}
*/
