#ifndef MORSE_HELPERS_DECORATORS_PATTERN
#define MORSE_HELPERS_DECORATORS_PATTERN

void MorsePatternDecorator(const Module::ProcessArgs &args, int key, Morse::MorsePattern &pattern)
{

  // advance the pattern indexer it its not actie
  if (!this->patternAdvance == true)
  {
    return;
  }

  if (!pattern.isActive())
  {
    // pattern.setCurrent(false);
    this->currentPattern++;
    return;
  }

  if (this->currentPattern == key)
  {
    pattern.setCurrent(true);
  }
  else
  {
    pattern.setCurrent(false);
  }
}

#endif