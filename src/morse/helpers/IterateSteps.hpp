#ifndef MORSE_HELP_ITERATE_STEPS
#define MORSE_HELP_ITERATE_STEPS
void MorseIterateSteps(Morse::MorsePattern &pattern, std::function<void(int key, Morse::MorsePattern &pattern, Morse::MorseStep &step)> callback)
{
  for (int c = 0; c < 8; c++)
  {
    Morse::MorseStep &step = pattern.getStep(c);
    callback(c, pattern, step);
  }
}
#endif