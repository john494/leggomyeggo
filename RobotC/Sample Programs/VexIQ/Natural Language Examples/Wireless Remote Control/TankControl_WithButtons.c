#pragma config(StandardModel, "VEX IQ Clawbot")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main()
{
	repeat (forever) {
		tankControl(ChD, ChA, 10);
		armControl(motor10, BtnLUp, BtnLDown, 75);
		armControl(motor11, BtnRUp, BtnRDown, 75);
	}
}
