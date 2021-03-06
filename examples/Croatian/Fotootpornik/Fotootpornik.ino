//==============================================================================
//    E - R A D I O N I C A . C O M,  H.Kolomana 6/A, Djakovo 31400, Croatia
//==============================================================================
// Project   :  Bandit the Racoon Arduino Library
// File      :  BTR Arduino Example
// Author    :  e-r.io 2017
// Licence   :  Open-source ! 
//==============================================================================
//==============================================================================
// To be used with Bandit the Racoon board:
// https://e-radionica.com/en/bandit-the-raccoon-btr.html
// Reads light level with photoresistor and make VU meter for light on LEDs.
// If any questions, 
// just contact hello@e-r.io
//==============================================================================

#include "BTR.h"

// nužno kreirati novu klasu
BTR bandit;

void setup() {
  // postavlja WS2801
  bandit.begin();

  // zapocinje serijsku komunikaciju
  Serial.begin(9600);
}

void loop() {

  // ispisi ocitanja s fotootpornika u SerialMonitoru 
  // ->
  Serial.print(bandit.ldr()); // ispisuje 10-bitna ocitanja (0-1023)
  
  // primjer vlastite funkcije: "VU:metar" s obzirom na očitanje LDR
  // ->
  int vu_metar = map(bandit.ldr(), 0, 1023, 0, 12); // mapiraj raspon očitanja
                                                    // na broj LEDica
  for( int i = 0; i <= vu_metar; i++) {
    bandit.upaliLED(i, "zelena"); // upali samo mapirane LEDice zeleno
  }

  for( int i = 12; i > vu_metar; i--) {
    bandit.upaliLED(i, 0,0,0);    // ugasi preostale LEDice
  }
                           
}
