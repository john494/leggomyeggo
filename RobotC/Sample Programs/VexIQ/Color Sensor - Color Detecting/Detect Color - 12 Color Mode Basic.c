#pragma config(Sensor, port5,  colorDetector,  sensorVexIQ_Color12Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
	This program will show the VEX IQ Color sensor in "12 Color" mode. This mode will return a specific
	color values as opposed to a "Hue" value. This is helpful for detecting specific colors.

	The 12 valid color names are:
	colorRedViolet / colorRed / colorDarkOrange / colorOrange /	colorDarkYellow /	colorYellow /
	colorLimeGreen / colorGreen /	colorBlueGreen / colorBlue / colorDarkBlue /  colorViolet

	The "getColorValue" command will return one of the 12 named colors, so a simple "equal to"
	works the best. This program uses 12 if/else blocks to do the comparison.

	ROBOT CONFIGURATION: VEX IQ Clawbot
	MOTORS & SENSORS:
	[I/O Port]          [Name]              [Type]                			[Location]
	Port 5       				colorDetector       VEX IQ Color		      			Color Detector (12 Color Mode)
------------------------------------------------------------------------------------------------*/

task main()
{
	while(true)
	{
		if(getColorName(colorDetector) == colorRedViolet)  		 //Color #1
		{
			displayTextLine(1, "Color: Red Violet");
		}
		else if(getColorName(colorDetector) == colorRed)  //Color #2
		{
			displayTextLine(1, "Color: Red");
		}
		else if(getColorName(colorDetector) == colorDarkOrange)  //Color #3
		{
			displayTextLine(1, "Color: Dark Orange");
		}
		else if(getColorName(colorDetector) == colorOrange)  //Color #4
		{
			displayTextLine(1, "Color: Orange");
		}
		else if(getColorName(colorDetector) == colorDarkYellow)  //Color #5
		{
			displayTextLine(1, "Color: Dark Yellow");
		}
		else if(getColorName(colorDetector) == colorYellow)  //Color #6
		{
			displayTextLine(1, "Color: Yellow");
		}
		else if(getColorName(colorDetector) == colorLimeGreen)  //Color #7
		{
			displayTextLine(1, "Color: Lime Green");
		}
		else if(getColorName(colorDetector) == colorGreen)  //Color #8
		{
			displayTextLine(1, "Color: Green");
		}
		else if(getColorName(colorDetector) == colorBlueGreen)  //Color #9
		{
			displayTextLine(1, "Color: Blue Green");
		}
		else if(getColorName(colorDetector) == colorBlue)  //Color #10
		{
			displayTextLine(1, "Color: Blue");
		}
		else if(getColorName(colorDetector) == colorDarkBlue)  //Color #11
		{
			displayTextLine(1, "Color: Dark Blue");
		}
		else if(getColorName(colorDetector) == colorViolet)  //Color #12
		{
			displayTextLine(1, "Color: Violet");
		}
		sleep(25);	//Small Delay to allow a new color to be detected.
	}
}
