#pragma config(StandardModel, "VEX IQ Clawbot")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main()
{
	repeat (forever) {
		tankControl(ChD, ChA, 10);
	}
}
