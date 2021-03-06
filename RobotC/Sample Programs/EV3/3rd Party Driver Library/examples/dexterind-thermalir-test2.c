#pragma config(Sensor, S1,     TIR,                 sensorI2CCustomFastSkipStates)
#pragma config(Motor,  motorA,          VERTICAL,      tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          HORIZONTAL,    tmotorNormal, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * dexterind-thermalir.h provides an API for the Dexter Industries Thermal Infrared Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Dexter Industries for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 10 June 2011
 * version 0.1
 */

#include "dexterind-thermalir.h"

float data[200];

task main () {
  short X = 0;

  // declare and initialise the sensor
  tTIR tir;
  initSensor(&tir, S1);

  memset(data, 0, sizeof(data));

  displayCenteredTextLine(0, "Dexter Industries");
  displayCenteredTextLine(1, "Thermal Infrared");
  displayCenteredTextLine(3, "Test 1");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to S1");
  sleep(2000);

  eraseDisplay();

  // set emissivity for light skin
  setEmissivity(&tir, TIR_EM_SKIN_LIGHT);

  nMotorEncoderTarget[VERTICAL] = 200;
  motor[VERTICAL] = -20;
  while((nMotorRunState[VERTICAL] != runStateIdle) && (nMotorRunState[VERTICAL] != runStateHoldPosition)) sleep(1);
  nMotorEncoderTarget[HORIZONTAL] = 360;
  motor[HORIZONTAL] = 20;
  while((nMotorRunState[HORIZONTAL] != runStateIdle) && (nMotorRunState[HORIZONTAL] != runStateHoldPosition)) sleep(1);
  sleep(500);
  nMotorEncoder[HORIZONTAL] = 0;
  nMotorEncoder[VERTICAL] = 0;
  playSound(soundBeepBeep);
  while(bSoundActive) sleep(1);
  for (short i = 0; i < 80; i++) {
    sleep(500);
    X = 0;
    memset(data, 0, sizeof(data));
    nMotorEncoderTarget[HORIZONTAL] = 720;
    motor[HORIZONTAL] = -40;
    time1[T1] = 0;
    while((nMotorRunState[HORIZONTAL] != runStateIdle) && (nMotorRunState[HORIZONTAL] != runStateHoldPosition)) {
      readSensor(&tir);
      data[X] = tir.objectTemp;
      X++;
      sleep(20);
    }
    displayBigTextLine(1, "X: %d", X);
    displayBigTextLine(3, "T: %d", time1[T1]);
    nMotorEncoderTarget[VERTICAL] = 5;
    motor[VERTICAL] = 20;

    nMotorEncoderTarget[HORIZONTAL] = 720;
    motor[HORIZONTAL] = 60;

    for (short j = 0; j < 200; j++) {
      if (data[j] != 0) {
        writeDebugStream("%3.2f,", data[j]);
        sleep(5);
      }
    }
    writeDebugStreamLine("");

    while((nMotorRunState[HORIZONTAL] != runStateIdle) && (nMotorRunState[HORIZONTAL] != runStateHoldPosition))
      sleep(1);
  }
  bFloatDuringInactiveMotorPWM = true;
  sleep(10);
}
