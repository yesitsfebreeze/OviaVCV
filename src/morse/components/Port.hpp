#include "rack.hpp"

using namespace rack;

#ifndef MORSE_COMP_PORT
#define MORSE_COMP_PORT

struct MorsePort : app::SvgPort
{
  MorsePort()
  {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Morse/MorsePort.svg")));
  }
};

#endif