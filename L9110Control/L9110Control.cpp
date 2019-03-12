#include "Arduino.h"
#include "L9110Control.h"

L9110Control::L9110Control(int pinIa, int pinIb)
{
  pinMode(pinIa, OUTPUT);
  pinMode(pinIb, OUTPUT);
  _pinIa = pinIa;
  _pinIb = pinIb;
}

void L9110Control::forward()
{
  digitalWrite(_pinIa,HIGH);
  digitalWrite(_pinIb,LOW);
}

void L9110Control::backward()
{
  digitalWrite(_pinIa,LOW);
  digitalWrite(_pinIb,HIGH);
}

void L9110Control::stop()
{
  digitalWrite(_pinIa,LOW);
  digitalWrite(_pinIb,LOW);
}
