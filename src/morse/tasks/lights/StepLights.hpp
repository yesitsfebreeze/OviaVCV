#ifndef MORSE_TASKS_STEP_LIGHTS
#define MORSE_TASKS_STEP_LIGHTS

void MorseStepLights(const Module::ProcessArgs &args, int key, Morse::MorseStep &step)
{
  if (this->currentStep == key)
  {
    if (step.isActive())
    {
      lights[STEP_LIGHT + key].setSmoothBrightness(1, args.sampleTime);
    }
    else
    {
      lights[STEP_LIGHT + key].setSmoothBrightness(0.1, args.sampleTime);
    }
  }
  else
  {
    lights[STEP_LIGHT + key].setSmoothBrightness(0, args.sampleTime);
  }
}

#endif