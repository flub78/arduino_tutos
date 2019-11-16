/**
	Class Display
	projet joystick
*/

#include "Display.h"

Display::Display() {
}

void Display::dashboard(int ailerons, int profondeur, int alterna) {
  Serial.print("ailerons: ");
  Serial.println(ailerons);
  Serial.print("profondeur: ");
  Serial.println(profondeur);
  Serial.print("alterna: ");
  Serial.println(alterna);
  Serial.println("");
}

