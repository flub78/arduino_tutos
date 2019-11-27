/**
	Class Display
	projet joystick
*/
#ifndef Display_h
#define Display_h

#include "Arduino.h"

class Display
{
  public:
    /**
		Constructor
	*/
    Display();
	/**
		Display the current value of three integer values
	*/
    void dashboard(int ailerons, int profondeur, int alterna);
};

#endif
