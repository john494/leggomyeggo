#pragma config(Sensor, S4,     sonar,               sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                       "Try Me" Program for NXT Motors - Enhanced
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma fileExtension("rtm")
#pragma platform("NXT")

//
// ROBOTC supports procedure "prototypes". These are simply declarations for the "header" of a
// procedure so that the procedure/subroutine can be called before it is actually defined.
//
void initializeGraphs();
void addDataPointFloat(int nXValue, int nEncoderCounts);
void addDataPointBrake(int nXValue, int nEncoderCounts);

//
// Standard 'C' does not support scalar 'const' declarations. ROBOTC does. It's nicer than using
//     "#define kGraphWidth 100"
//
const int kGraphFloatLeft =  0;
const int kGraphBrakeLeft = 50;
const int kGraphTop    		= 56;
const int kGraphBottom 		=  0;
const int kGraphHeight 		= kGraphTop - kGraphBottom + 1;
const int kGraphWidth 		= 100 / 2;

int index;
int nPower;

//
// Note variables can be initialized in the declaration statement with the use of an optional
// "= <epxression>" clause after the declaration.
//
int   nMaxGraphPoint = kGraphHeight;
float fGraphScaler   = 1;
int   nGraphFloat[kGraphWidth];
int   nGraphBrake[kGraphWidth];

task main()
{
	nVolume = 2;

	//
	// Grab LCD screen and initialize display
	//
	initializeGraphs();
	eraseDisplay();
	displayTextLine(0, " Brake vs Float");
	displayTextLine(1, "  Steady State");
	displayTextLine(2, " Speed Analysis");

	//
	// Wait for motor to be connected
	//
	if (false)
	{
		bFloatDuringInactiveMotorPWM = false;
		nMotorEncoder[motorA] = 0;
		motor[motorA] = 100;
		while (nMotorEncoder[motorA] < 10)
		{
			playSound(soundBeepBeep);
			displayTextLine(6, " Connect Motor");
			displayTextLine(7, "  to Port 1");
			wait1Msec(400);
			displayTextLine(6, "");
			displayTextLine(7, "");
			wait1Msec(400);
		}
		motor[motorA] = 0;
		wait1Msec(0x100);
	}

	eraseDisplay();
	for (index = kGraphWidth - 1; index >= 0; --index)
	{
		const int kWaitDurationStop 				= 500;
		const int kWaitDurationRampToSpeed 	= 500;
		const int kWaitDurationMeasure 			= 1000;

		nPower = index * 2 + 2;
		displayTextLine(0, " Float %2d Brake", nPower);
		if (4 == index % 5)
		{
			playTone( 750, 5);
			playTone(1500, 5);
		}
		alive();

		// Wait for motor stopped condition

		bFloatDuringInactiveMotorPWM = false;
		motor[motorA] = 0;
		wait1Msec(kWaitDurationStop);

		// wait for steady state speed
		//
		// Float speed for 0.5 second at selected power level
		//
		bFloatDuringInactiveMotorPWM = true;
		motor[motorA] = nPower;
		wait1Msec(kWaitDurationRampToSpeed); // wait for steady state speed
		nMotorEncoder[motorA] = 0;
		wait1Msec(kWaitDurationMeasure);
		addDataPointFloat(index, nMotorEncoder[motorA]);

		// Wait for motor stopped condition

		bFloatDuringInactiveMotorPWM = false;
		motor[motorA] = 0;
		wait1Msec(kWaitDurationStop);

		//
		// Brake speed for 0.5 second at selected power level
		//
		bFloatDuringInactiveMotorPWM = false;
		motor[motorA] = nPower;
		wait1Msec(kWaitDurationRampToSpeed); // wait for steady state speed
		nMotorEncoder[motorA] = 0;
		wait1Msec(kWaitDurationMeasure);
		addDataPointBrake(index, nMotorEncoder[motorA]);
	}
	displayTextLine(0, " Float vs Brake");
	while (true)
	{
		// wait for user to cancel program
		alive();
	}
}


void initializeGraphs()
{
	//
	// Zero out the histogram entries
	//
	int i;
	for (i = 0; i < kGraphWidth; ++i)
	{
		nGraphFloat[i] = 0;
		nGraphBrake[i] = 0;
	}
	return;
}


void rescaleGraphs(int nCurrentMaximumValue)
{
	int i;

	eraseRect(kGraphFloatLeft, kGraphTop, kGraphFloatLeft + kGraphWidth - 1, kGraphBottom);
	eraseRect(kGraphBrakeLeft, kGraphTop, kGraphBrakeLeft + kGraphWidth - 1, kGraphBottom);
	drawLine(kGraphFloatLeft, kGraphTop - 1, kGraphBrakeLeft + kGraphWidth - 1, kGraphTop - 1);
	nMaxGraphPoint = nCurrentMaximumValue;
	displayString(1, "%d", nMaxGraphPoint);
	if (nCurrentMaximumValue == 0)
		nCurrentMaximumValue = 1;
	fGraphScaler = ((float) kGraphHeight) / nCurrentMaximumValue;

	for (i = 0; i < kGraphWidth; ++ i)
	{
		if (nGraphFloat[i] != 0)
		  setPixel(i + kGraphFloatLeft, kGraphBottom + (int) (nGraphFloat[i] * fGraphScaler));
		if (nGraphBrake[i] != 0)
		  setPixel(i + kGraphBrakeLeft, kGraphBottom + (int) (nGraphBrake[i] * fGraphScaler));
	}
	return;
}

void addDataPointFloat(int nXValue, int nEncoderCounts)
{
	if (nXValue > (kGraphWidth - 1))
		nXValue = kGraphWidth - 1;

	nGraphFloat[nXValue] = nEncoderCounts;
	if (nEncoderCounts < nMaxGraphPoint)
		setPixel(kGraphFloatLeft + nXValue, kGraphBottom + (int) (nEncoderCounts * fGraphScaler));
	else if (nEncoderCounts > nMaxGraphPoint)
		rescaleGraphs(nEncoderCounts);
	return;
}

void addDataPointBrake(int nXValue, int nEncoderCounts)
{
	if (nXValue > (kGraphWidth - 1))
		nXValue = kGraphWidth - 1;

	nGraphBrake[nXValue] = nEncoderCounts;
	if (nEncoderCounts < nMaxGraphPoint)
		setPixel(kGraphBrakeLeft + nXValue, kGraphBottom + (int) (nEncoderCounts * fGraphScaler));
	else if (nEncoderCounts > nMaxGraphPoint)
		rescaleGraphs(nEncoderCounts);
	return;
}
