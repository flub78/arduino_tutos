/**
	Class clignoteur
	projet joystick
*/

#include "Clignoteur.h"

Clignoteur::Clignoteur(int led, unsigned long duration) {
  pinMode(led, OUTPUT);
  _duration = duration * 1000;
  _led = led;
  _lastTransition = micros();
  _state = LOW;
}

void Clignoteur::poll(unsigned long duration) {
  _duration = duration * 1000;

  unsigned long now = micros();
  unsigned long sinceLast = now - _lastTransition;
  
  if (sinceLast > _duration) {
    _lastTransition = now;
    if (_state == LOW) {
      _state =  HIGH;
    } else {
      _state =  LOW;      
    }
    digitalWrite(_led, _state);
  } else {
  }
}
