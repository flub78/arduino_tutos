/**
	Class clignoteur
	projet joystick
*/
#ifndef Clignoteur_h
#define Clignoteur_h

#include "Arduino.h"

class Clignoteur
{
  public:
    Clignoteur(int led, unsigned long duration);
    void poll(unsigned long duration);
  private:
    unsigned long _duration;
    int _led;
    unsigned long _lastTransition;
    int _state;
};

#endif
