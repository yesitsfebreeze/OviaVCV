#include "rack.hpp"

using namespace rack;

#ifndef MORSE_COMP_KNOB
#define MORSE_COMP_KNOB

struct MorseKnob : RoundKnob
{
  MorseKnob()
  {
    minAngle = -0.9 * M_PI;
    maxAngle = 0.9 * M_PI;
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Morse/MorseKnob.svg")));
  }
};

#endif