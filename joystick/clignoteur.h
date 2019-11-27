/**
	Class clignoteur
	projet joystick
*/
#ifndef Clignoteur_h
#define Clignoteur_h

#include "Arduino.h"

/**
	Control of a blinking LED
*/
class Clignoteur
{
  public:
    /**
		Constructor
		
		\param led Arduino pin number of the controlled LED
        \param duration of half period in milliseconds

        The LED will stay alternatively on and off during duration. 100 => 5 Hz		
	*/
    Clignoteur(int led, unsigned long duration);
	
	/**
		Change the blinking frequency by setting a new duration
		
		\param duration of half period in milliseconds
	*/
    void poll(unsigned long duration);
	
  private:
    unsigned long _duration;
    int _led;
    unsigned long _lastTransition;
    int _state;
};

#endif
