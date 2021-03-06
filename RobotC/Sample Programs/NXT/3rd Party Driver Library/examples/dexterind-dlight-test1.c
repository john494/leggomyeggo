#pragma config(Sensor, S1,     DLIGHT,         sensorI2CCustomFastSkipStates)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * dexterind-dlight.h provides an API for the Dexter In Angle Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * date 31 November 2012
 * version 0.1
 */

#include "dexterind-dlight.h"

task main()
{
  short max = 200;

  // Initialise all of the dLights
  DLIGHTinit(DLIGHT, DLIGHT_I2C_ADDR_ALL);
  sleep(50);

  // Make all the lights white
  DLIGHTsetColor(DLIGHT, DLIGHT_I2C_ADDR_ALL, 0xFF, 0xFF, 0xFF);
  sleep(1000);

  // Make all of the lights red
  DLIGHTsetColor(DLIGHT, DLIGHT_I2C_ADDR_ALL, 0xFF, 0, 0);
  sleep(1000);

  // Make all of the lights...green
  DLIGHTsetColor(DLIGHT, DLIGHT_I2C_ADDR_ALL, 0, 0xFF, 0);
  sleep(1000);

  // Make all of the lights, you guessed it, red, no wait, blue!
  DLIGHTsetColor(DLIGHT, DLIGHT_I2C_ADDR_ALL, 0, 0, 0xFF);
  sleep(1000);

  // Make a nice sort of rainbow effect by cycling through colours
  for (short value = 0; value < max; value++)
  {
    short midpoint = max / 2;
    short currvalue = max - value;
    short red = 0;
    short green = 0;
    short blue = 0;

    if (currvalue <= midpoint)
    {
      red = 255 - ((255 / midpoint) * currvalue);
      green = (255 / (midpoint) * currvalue);
      blue = 0;
    }
    else
    {
      red = 0;
      green = 255 - ((255 / midpoint) * (currvalue - midpoint));
      blue = 255 / (midpoint) * (currvalue - (midpoint));
    }
    if (red < 0 || red > 255)
      red = 0;
    if (green < 0 || green > 255)
      green = 0;
    if (blue < 0 || blue > 255)
      blue = 0;
    DLIGHTsetColor(DLIGHT, DLIGHT_I2C_ADDR_ALL, red, green, blue);
    sleep(50);
  }

  // Make the lights blink!
  // Configure for 1 Hz with a 10% duty rate
  DLIGHTsetBlinking(DLIGHT, DLIGHT_I2C_ADDR_ALL, 1, 10);
  sleep(10);

  // Set the colour
  DLIGHTsetColor(DLIGHT, DLIGHT_I2C_ADDR_ALL, 0, 0xFF, 0xFF);
  sleep(10);

  // Start blinking!
  DLIGHTstartBlinking(DLIGHT, DLIGHT_I2C_ADDR_ALL);
  sleep(5000);

  // Stop the blinking
  DLIGHTstopBlinking(DLIGHT, DLIGHT_I2C_ADDR_ALL);
  sleep(10);

  // Turn off all of the
  DLIGHTdisable(DLIGHT, DLIGHT_I2C_ADDR_ALL);

  //DLIGHTsetColor(DLIGHT, DLIGHT_I2C_ADDR_1, 0xFF, 0, 0);
  //sleep(500);
  //DLIGHTstartBlinking(DLIGHT, DLIGHT_I2C_ADDR_1);
  //DLIGHTsetColor(DLIGHT, DLIGHT_I2C_ADDR_2, 0, 0xFF, 0);
  //sleep(500);
  //DLIGHTstartBlinking(DLIGHT, DLIGHT_I2C_ADDR_2);
  //DLIGHTsetColor(DLIGHT, DLIGHT_I2C_ADDR_3, 0, 0, 0xFF);
  //sleep(500);
  //DLIGHTstartBlinking(DLIGHT, DLIGHT_I2C_ADDR_3);
  //DLIGHTsetColor(DLIGHT, DLIGHT_I2C_ADDR_4, 0xFF, 0xFF, 0xFF);
  //sleep(500);
  //DLIGHTstartBlinking(DLIGHT, DLIGHT_I2C_ADDR_4);
  //sleep(2000);
  //DLIGHTstopBlinking(DLIGHT, DLIGHT_I2C_ADDR_ALL);
}
