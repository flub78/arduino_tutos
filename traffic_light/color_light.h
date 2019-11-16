/*
  color_light.h
  Manage a three color traffic light based on a clock

  A color light is defined by a cycle
    * number of clock ticks with green on
    * number of ticks with yellow on
    * number of tick with red on.

  By default the tick will be one second.

  To protect the crossing of two roads red = green + orange + security

  And two traffic light should have a phase difference in their cycles. The idea is to have the green on one starting when
  the red starts on the other. We want some security margin with red on for everybody for a few seconds 

  Ex:

  light 1:                  Light 2 (crossing):
    green for 10 sec          red
    orange for 2 sec          red
    security red for 2 sec    red
    red for 10 sec            green for 10 sec
    red for  2 sec            orange for 2 sec
    security red for 2 sec    red

The whole cycle is 28 sec. Phase difference is 14 sec.

In real life, we would create a cycle object and pass that to the treffic light. It would provide a way to change the traffic lignt configuration.

*/

#ifndef COLOR_LIGHT_H
#define COLOR_LIGHT_H

#include "Arduino.h"

class ColorLight
{
  public:
    ColorLight(int red_pin, int yellow_pin, int green_pin);
    void dot();
    void dash();
  private:
    int _red_pin, _yellow_pin, _green_pin;
};

#endif

