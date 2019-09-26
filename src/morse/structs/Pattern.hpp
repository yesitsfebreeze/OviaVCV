#ifndef MORSE_STRUCT_PATTERN
#define MORSE_STRUCT_PATTERN

#include "Step.hpp"
struct MorsePattern
{
  Morse::MorseStep steps[8];
  bool active = true;
  bool current = false;

public:
  bool isActive()
  {
    return this->active;
  }
  void setActive(bool active)
  {
    this->active = active;
  }
  void toggleActive()
  {
    this->active = !this->active;
  }

  bool isCurrent()
  {
    return this->current;
  }
  void setCurrent(bool current)
  {
    this->current = current;
  }
  void toggleCurrent()
  {
    this->current = !this->current;
  }

  Morse::MorseStep *getSteps()
  {
    return this->steps;
  }

  Morse::MorseStep &getStep(int index)
  {
    return this->steps[index];
  }
};