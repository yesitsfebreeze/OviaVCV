#ifndef MORSE_TASKS_PATTERN_LIGHTS
#define MORSE_TASKS_PATTERN_LIGHTS

void MorsePatternLights(const Module::ProcessArgs &args, int key, Morse::MorsePattern &pattern)
{
  if (pattern.isCurrent())
  {
    lights[PATTERN_LIGHT + key].setSmoothBrightness(1, args.sampleTime);
  }
  else
  {
    lights[PATTERN_LIGHT + key].setSmoothBrightness(0, args.sampleTime);
  }
}

#endif