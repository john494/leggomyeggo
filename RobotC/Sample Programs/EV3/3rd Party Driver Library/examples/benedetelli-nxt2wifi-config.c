#pragma config(Sensor, S4,     NXT2WIFI,       sensorHighSpeed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * benedettelli-nxt2wifi.h provides an API for Daniele's NXT2WiFi Sensor. This program
 * allows you to configure the NXT2WIFI using the provided SSID and passphrase
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Daniele Benedettelli for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER
 * Xander Soldaat (xander_at_botbench.com)
 * 22 July 2012
 * version 0.1
 */
#define __RS485_DEBUG__
#include "common.h"
#include "benedettelli-nxt2wifi.h"

// Use DHCP? You should.
bool useDHCP = true;

// Leave this to false, unless you know what you're doing.
bool useAdHoc = false;

// Set one of the security options below to true
bool useWPA = false;
bool useWPA2 = true;
bool useWEP104 = false;
bool useOpen = false;

string ipaddress = "192.168.0.55";
string netmask = "255.255.255.0";
string DNS1 = "192.168.0.1";
string DNS2 = "192.168.0.2";
string gateway = "192.168.0.1";

const string ssid = "SSID";
const string passphrase = "PASSWORD";

task main ()
{
  // initialise the port, etc
  RS485initLib();
  displayTextLine(0, "Stat: disconnected");
  displayTextLine(2, "-------------------");

  N2WchillOut();
  N2WsetDebug(true);
  N2WchillOut();

  // Disconnect if already connected
  N2WDisconnect();
  sleep(100);

  // Delete any pre-existing custom profiles and reset the device
  N2WDelete();
  N2WchillOut();
  N2WReset();
  sleep(4000);

  // enable DHCP
  if (useDHCP)
  {
    N2WsetDHCP(true);
  }
  else
  {
    N2WsetDHCP(false);
    N2WchillOut();
    N2WsetIPAddress(ipaddress);
    N2WchillOut();
    N2WsetMask(netmask);
    N2WchillOut();
    N2WsetDNS1(DNS1);
    N2WchillOut();
    N2WsetDNS2(DNS2);
    N2WchillOut();
    N2WsetGateway(gateway);
  }

  sleep(100);
  // Enable or disable AdHoc
  N2WsetAdHoc(useAdHoc);
  sleep(100);
  // SSID to connect to
  N2WsetSSID(ssid);
  sleep(100);

  if (useWPA)
    N2WSecurityWPAPassphrase(passphrase);
  else if (useWPA2)
    N2WSecurityWPA2Passphrase(passphrase);
  else if (useWEP104)
    N2WSecurityWEP104(passphrase);
  else if (useOpen)
    N2WSecurityOpen();

  displayTextLine(0, "Stat: Calculating");
  displayTextLine(3, "This can take up");
  displayTextLine(4, "to 30 seconds");
  sleep(100);

  // Save this profile to the custom profile
  N2WSave();
  sleep(100);
  // Load the custom profile
  N2WLoad();

  sleep(100);
  N2WConnect(true);
  displayTextLine(0, "Stat: Connecting");

  while (!N2WConnected())
    sleep(500);

  sleep(3000);

  N2WgetIP(ipaddress);
  displayTextLine(3, "My IP address is");
  displayTextLine(4, ipaddress);
  displayTextLine(0, "Stat: Configured");
  N2WchillOut();
  N2WSave();
  playSound(soundBeepBeep);
  while(true) sleep(1);
}
