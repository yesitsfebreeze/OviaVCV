#ifndef MORSE_TASKS_CLOCKING
#define MORSE_TASKS_CLOCKING
dsp::SchmittTrigger clockTrigger;

void MorseClocking(const Module::ProcessArgs &args)
{
  if (inputs[CLOCK_INPUT].isConnected())
  {
    lights[CLOCK_INPUT_LIGHT].setSmoothBrightness(clockTrigger.isHigh(), args.sampleTime);
    // todo: move to lights/sequence file
    lights[STEP_OUTPUT_LIGHT].setSmoothBrightness(clockTrigger.isHigh(), args.sampleTime);

    if (clockTrigger.process(inputs[CLOCK_INPUT].getVoltage()))
    {

      this->currentStep += 1;
      this->patternAdvance = false;

      if (this->currentStep >= 8)
      {
        this->currentStep = 0;

        this->currentPattern += 1;
        this->patternAdvance = true;

        if (this->currentPattern >= 8)
        {
          this->currentPattern = 0;
        }
      }
    }
  }
}
#endif