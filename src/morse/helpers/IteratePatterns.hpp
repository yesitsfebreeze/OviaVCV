#ifndef MORSE_HELP_ITERATE_PATTERNS
#define MORSE_HELP_ITERATE_PATTERNS
void MorseIteratePatterns(Morse::MorsePattern *patterns, std::function<void(int key, Morse::MorsePattern &pattern)> callback)
{
  for (int c = 0; c < 8; c++)
  {
    Morse::MorsePattern &pattern = patterns[c];
    callback(c, pattern);
  }
}
#endif