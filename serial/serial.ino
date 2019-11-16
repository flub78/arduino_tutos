/**
   Gestion d'un potentiometre double 
*/
#include "const.h"
#include "Clignoteur.h"
#include "Display.h"

Clignoteur blue(BLUE_LED, 100);
Clignoteur green(GREEN_LED, 100);

Display screen;

/**
 * Initialisation
 */
void setup()
{ 
  // La broche en entrée pour le bouton
  pinMode(BUTTON, INPUT_PULLUP); 

  Serial.begin(9600);

}

/**
 * Boucle principale du programme
 */
void loop()
{
  int ailerons; //déclaration de la variable qui va stocker la valeur numérique de la tension du potentiomètre
  int profondeur;
  int alterna;

  ailerons = map(analogRead(A0), 0, 1023, 20, 2000); 
  profondeur = map(analogRead(A1), 0, 1023, 20, 2000);
  alterna = digitalRead(BUTTON); 

  screen.dashboard(ailerons, profondeur, alterna);
  delay(10);

  green.poll(ailerons);
  blue.poll(profondeur);
  digitalWrite(RED_LED, !alterna);
}



