#include "rack.hpp"

using namespace rack;

#ifndef MORSE_COMP_BUTTON
#define MORSE_COMP_BUTTON

struct MorseButton : app::SvgSwitch
{
  MorseButton()
  {
    momentary = true;
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Morse/MorseButtonUp.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Morse/MorseButtonDown.svg")));
  }
};

#endif