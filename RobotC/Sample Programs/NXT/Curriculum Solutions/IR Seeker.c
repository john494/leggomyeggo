#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S2,     IRSeeker2,           sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNone, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
  while(1 == 1)
  {
    if(SensorValue[IRSeeker2] == 5)
    {
      motor[motorD] = 25;
      motor[motorE] = 25;
    }

    if(SensorValue[IRSeeker2] > 5)
    {
      motor[motorD] = -20;
      motor[motorE] = 20;
    }

    if(SensorValue[IRSeeker2] < 5)
    {
      motor[motorD] = 20;
      motor[motorE] = -20;
    }
  }
}
