#include "rack.hpp"

using namespace rack;

#ifndef MORSE_COMP_LIGHTS
#define MORSE_COMP_LIGHTS

int ledcolor[3] = {0xf7, 0x32, 0x65}; // f73265

struct MorseLight : GrayModuleLightWidget
{
  MorseLight()
  {
    box.size = Vec(7, 7);
    addBaseColor(nvgRGB(ledcolor[0], ledcolor[1], ledcolor[2]));
  }
};

struct MorseLightLarge : MorseLight
{
  MorseLightLarge()
  {
    box.size = Vec(12, 12);
  }
};

struct MorseLightSmall : MorseLight
{
  MorseLightSmall()
  {
    box.size = Vec(4, 4);
  }
};

#endif