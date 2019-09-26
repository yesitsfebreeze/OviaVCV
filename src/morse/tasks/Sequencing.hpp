void MorseSequencing(const Module::ProcessArgs &args)
{
  if (inputs[CLOCK_INPUT].isConnected())
  {
    lights[CLOCK_INPUT_LIGHT].setSmoothBrightness(clockTrigger.isHigh(), args.sampleTime);
    lights[STEP_OUTPUT_LIGHT].setSmoothBrightness(clockTrigger.isHigh(), args.sampleTime);

    // External Clock
    if (clockTrigger.process(inputs[CLOCK_INPUT].getVoltage()))
    {
      // todo: change this to multiplied value of active patterns
      int numSteps = steps;

      this->currentStep += 1;

      if (this->currentStep >= numSteps)
      {
        this->currentStep = 0;
      }
    }
  }
}