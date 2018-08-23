#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)//remember to enable external motor/servo controllers under Robot/Platform Type
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, PIDControl, reversed, encoder)


// TETRIX nMotorEncoder Example
// The program below demonstrates how to use the nMotorEndocer function
// There are three steps to using the function
//    1. Zero out the encoder using "nMotorEncoder(motorX) = 0"   Lines 16 and 17.
//    2. Place the function into a conditional statement like a while loop.  Line 19
//    3. Turn the motors off. Lines 25 and 26.

task main()
{

  nMotorEncoder[motorE] = 0;  //clear the TETRIX encoders in motors D and E
  nMotorEncoder[motorD] = 0;

  while (nMotorEncoder[motorE] < 1440) //while the encoder wheel turns one revolution
  {
    motor[motorE] = 30; //turn both motors on at 30 percent power
    motor[motorD] = 30;
  }

  motor[motorE] = 0; //turn both motors off
  motor[motorD] = 0;

  wait1Msec(3000); // wait 3 seconds to see feedback from the debugger screens
                    // open the "NXT Devices" window to see the distance the encoder
                    //spins. The robot will coast a little bit.
}
