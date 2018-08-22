#pragma config(Sensor, S1,     HTSPB,                sensorI2CCustom9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*   HiTechnic Experimenter's Kit for the SuperPro

Experiment 5 - Ambient Canceling Light Sensor

This program reads the light level with a reference light source on and also off,
calculates the background light level to create an ambient (background) canceling light sensor.

*/

#include "hitechnic-superpro.h"

task main() {
  short wlight;
  short wolight;
  short lightdelta;

  // The data to be written: 0x3F = 111111 binary,
  // makes all digital ports outputs.
  HTSPBsetupIO(HTSPB, 0x3F);

  while(true) {
    // Switch off LED on port B0
    HTSPBwriteIO(HTSPB, 0x00);
    sleep(30);
    wolight = HTSPBreadADC(HTSPB, 0, 10);

    // Switch on LED on port B0
    HTSPBwriteIO(HTSPB, 0x01);
    sleep(30);
    wlight = HTSPBreadADC(HTSPB, 0, 10);

    // Calculate the difference
    lightdelta = wlight - wolight;

    eraseDisplay();
    displayTextLine(1, "L_On : %4d", wlight);
    displayTextLine(2, "L_Off: %4d", wolight);
    displayTextLine(4, "L_Delta: %4d", lightdelta);
    sleep(30);
  }
}
