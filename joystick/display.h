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
    Display();
    void dashboard(int ailerons, int profondeur, int alterna);
};

#endif
