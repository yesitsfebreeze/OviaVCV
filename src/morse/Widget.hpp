struct MorseWidget : ModuleWidget
{
  MorseWidget(Morse *module)
  {
    setModule(module);
    setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Morse/Morse.svg")));

    addParam(createParamCentered<MorseKnob>(Vec(96.9, 34.5), module, Morse::SELECT_DIAL));
    addParam(createParamCentered<MorseButton>(Vec(23.1, 35.0), module, Morse::MODE_BUTTON));

    addInput(createInputCentered<MorsePort>(Vec(15.7, 280.2), module, Morse::CLOCK_INPUT));
    addChild(createLightCentered<MorseLight>(Vec(15.7, 260.5), module, Morse::CLOCK_INPUT_LIGHT));

    addInput(createInputCentered<MorsePort>(Vec(43.9, 280.2), module, Morse::RESET_INPUT));
    addChild(createLightCentered<MorseLight>(Vec(43.9, 260.5), module, Morse::RESET_INPUT_LIGHT));

    addInput(createInputCentered<MorsePort>(Vec(72.2, 280.2), module, Morse::ADVANCE_INPUT));
    addChild(createLightCentered<MorseLight>(Vec(72.2, 260.5), module, Morse::ADVANCE_INPUT_LIGHT));

    addOutput(createOutputCentered<MorsePort>(Vec(100.5, 280.2), module, Morse::STEPS_OUTPUT));
    addChild(createLightCentered<MorseLight>(Vec(100.5, 260.5), module, Morse::STEP_OUTPUT_LIGHT));

    static const Vec StepPos[8] = {
        Vec(23.1, 70.5),
        Vec(23.1, 121.7),
        Vec(23.1, 172.9),
        Vec(23.1, 224.0),
        Vec(96.9, 224.0),
        Vec(96.9, 172.9),
        Vec(96.9, 121.7),
        Vec(96.9, 70.5),
    };

    static const Vec PatternLightPos[8] = {
        Vec(49.59, 93.58),
        Vec(49.59, 129.36),
        Vec(49.59, 165.13),
        Vec(49.5964, 200.91),
        Vec(70.4037, 200.9116),
        Vec(70.4037, 165.1371),
        Vec(70.4037, 129.3626),
        Vec(70.4037, 93.5882),
    };

    static const Vec StepOutPos[8] = {
        Vec(15.7, 319.4),
        Vec(43.9, 319.4),
        Vec(72.2, 319.4),
        Vec(100.5, 319.4),
        Vec(15.7, 348.7),
        Vec(43.9, 348.7),
        Vec(72.2, 348.7),
        Vec(100.5, 348.7),
    };

    for (int step = 0; step < steps; step++)
    {
      addParam(createParamCentered<LEDBezel>(StepPos[step], module, Morse::STEP_BUTTON + step));
      addChild(createLightCentered<MorseLightLarge>(StepPos[step], module, Morse::STEP_BUTTON + step));
      addOutput(createOutputCentered<MorsePort>(StepOutPos[step], module, Morse::STEP_OUTPUT + step));
      addChild(createLightCentered<MorseLightSmall>(PatternLightPos[step], module, Morse::PATTERN_LIGHT + step));
    }

    static const Vec ModeLightPos[6] = {
        Vec(45.97, 29.5),
        Vec(58.57, 29.5),
        Vec(71.17, 29.5),
        Vec(45.97, 40.5),
        Vec(58.57, 40.5),
        Vec(71.17, 40.5),
    };

    for (int mode = 0; mode < modes; mode++)
    {
      addChild(createLightCentered<MorseLightSmall>(ModeLightPos[mode], module, Morse::MODE_LIGHT + mode));
    }
  }
};