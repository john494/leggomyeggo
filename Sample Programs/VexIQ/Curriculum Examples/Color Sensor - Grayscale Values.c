#pragma config(StandardModel, "VEX IQ Clawbot")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	repeat(forever)
	{
		displayTextLine(1, "Light: %d", getColorGrayscale(colorDetector));
		sleep(250);
	}
}
