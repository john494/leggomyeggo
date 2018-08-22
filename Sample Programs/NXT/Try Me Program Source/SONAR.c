#pragma config(Sensor, S4,     sonar,               sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                     "Try Me" Program for NXT Sonar (UltraSound) Sensor
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma fileExtension("rtm")
#pragma platform("NXT")
#include "AdvancedSensors.c"    // include library files

//
// Special "distance" values returned by the SONAR device driver to indicate error conditions
//
typedef enum TSonarErrorCodes
{
	sonarNoSensorConnected = 254,
	sonarOutOfRange        = 255
} TSonarErrorCodes;


#pragma platform (NXT, TETRIX)
#pragma fileExtension("rtm")




task main()
{
  tSensors nSonar = S4;

	//
	// Grab LCD screen and initialize display
	//
	displayCenteredBigTextLine(0, "Sonar");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to any port");

  while (!findSensor(nSonar, "LEGO", "Sonar"))
	{
    wait1Msec(20);
  }
	SensorType[nSonar] = sensorSONAR;
	//
	// Wait for sonar Sensor to stablize
	//
	wait1Msec(100);

	displayCenteredTextLine(3, "Port S%1d", (int) nSonar + 1);
	displayCenteredTextLine(4, "Listen Sound !");
	displayTextLine(5, "");
	displayTextLine(6, "");

	while (true)
	{
	  int nValue;

	  nValue = SensorValue[nSonar];
	  switch (nValue)
	  {
	  case sonarNoSensorConnected:  displayCenteredBigTextLine(6, "Discnect");         break;
	  case sonarOutOfRange:         displayCenteredBigTextLine(6, "RangeErr");         break;
	  default:                      displayCenteredBigTextLine(6, "%3d cm ", nValue);   break;
		}
		if (nValue > 250)
	    nValue = 250;
	  playImmediateTone(nValue * 5 + 220, 10);
	  wait1Msec(100);
	}
	return;
}
