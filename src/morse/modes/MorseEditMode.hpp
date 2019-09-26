#include "rack.hpp"

using namespace rack;

#ifndef MORSE_EDIT_MODE
#define MORSE_EDIT_MODE

void MorseEditMode(Module::ProcessArgs &args, Morse &morse)
{
  morse.isInactive = false;
}

#endif