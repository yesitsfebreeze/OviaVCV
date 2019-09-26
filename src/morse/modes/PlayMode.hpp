#include "rack.hpp"

#ifndef MORSE_MODES_PLAY
#define MORSE_MODES_PLAY

class MorsePlayMode
{
public:
  static void general(const Module::ProcessArgs &args){};

  static void pattern(const Module::ProcessArgs &args){};

  static void step(const Module::ProcessArgs &args){};
};

#endif