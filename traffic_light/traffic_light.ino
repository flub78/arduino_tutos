/**
   Traffic light

   Clignotement de la diode 13
   et affiche quelques traces sur le moniteur série
*/

#include "color_light.h"

const int GREEN = 13;
const int ORANGE = 12;
const int RED = 11;

int cnt = 0;
int on = 0;
const int DELAY = 2000;

ColorLight light1(RED, ORANGE, GREEN);

void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN, OUTPUT);         // declared as digital output
  pinMode(ORANGE, OUTPUT);        // declared as digital output
  pinMode(RED, OUTPUT);           // declared as digital output
  Serial.begin(9600);
  Serial.println("Welcome");// envoi d'un message
}

void green() {
    digitalWrite(RED, LOW);       // switching off the GREEN
    digitalWrite(GREEN, HIGH);      // switching on the GREEN  
}

void orange() {
    digitalWrite(GREEN, LOW);       // switching off the GREEN
    digitalWrite(ORANGE, HIGH);      // switching on the GREEN  
}

void red() {
    digitalWrite(ORANGE, LOW);       // switching off the GREEN
    digitalWrite(RED, HIGH);      // switching on the GREEN  
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(cnt++);

  on = (on + 1) % 2;
  
  if ((cnt % 10) > 8) {
    orange();
  } else if ((cnt % 10) > 4) {
    green();
  } else {
    red();
  }

  delay(DELAY);                  // stopping the program for 1000 milliseconds
}
