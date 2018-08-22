#pragma config(Sensor, port12,  touchLED,      sensorVexIQ_LED)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
  This program shows off the "Blink Time" ability of the Touch LED. Instead of having to program
  the touch LED to blink yourself, you can set the On/Off time to enable "Blinking Mode".

  The "setTouchLEDBlinkTime" On and Off parameters are in 50ms increments (20 = 1 second)

  Setting either the On or Off time to zero will disable the blinking mode.

                            ROBOT CONFIGURATION: VEX IQ Clawbot
    MOTORS & SENSORS:
    [I/O Port]          [Name]              [Type]                			[Location]
    port 12							touchLED						VEX IQ Touch LED						Detect Touches and Set Colors
------------------------------------------------------------------------------------------------*/

task main()
{
	setTouchLEDRGB(touchLED, 200, 100, 0);
  setTouchLEDBlinkTime(touchLED, 40, 10);
  sleep(10000);
  setTouchLEDBlinkTime(touchLED, 0, 0);
}
