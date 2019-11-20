/**
 * SOS morse code on LED 13
 * Used as library tutorial
 * First version with no libraries
 */

#include "Morse.h"

Morse morse(13);

void setup()
{
}

void loop()
{
  morse.dot(); morse.dot(); morse.dot();
  morse.dash(); morse.dash(); morse.dash();
  morse.dot(); morse.dot(); morse.dot();
  delay(3000);
}
