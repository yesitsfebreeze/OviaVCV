int steps = 8;
int modes = 6;

#include "plugin.hpp"

#include "morse/components/Button.hpp"
#include "morse/components/Knob.hpp"
#include "morse/components/Port.hpp"
#include "morse/components/Lights.hpp"

struct Morse : Module
{
	enum ParamIds
	{
		ENUMS(STEP_BUTTON, 8),
		SELECT_DIAL,
		MODE_BUTTON,
		NUM_PARAMS
	};

	enum InputIds
	{
		CLOCK_INPUT,
		RESET_INPUT,
		ADVANCE_INPUT,
		NUM_INPUTS
	};
	enum OutputIds
	{
		STEPS_OUTPUT,
		ENUMS(STEP_OUTPUT, 8),
		NUM_OUTPUTS
	};

	enum LightIds
	{
		ENUMS(STEP_LIGHT, 8),
		ENUMS(PATTERN_LIGHT, 8),
		ENUMS(MODE_LIGHT, 8),
		CLOCK_INPUT_LIGHT,
		RESET_INPUT_LIGHT,
		ADVANCE_INPUT_LIGHT,
		STEP_OUTPUT_LIGHT,
		NUM_LIGHTS
	};

	enum Modes
	{
		PLAY_MODE,
		EDIT_MODE,
		PITCH_MODE,
		LENGTH_MODE,
		OFFSET_MODE,
		FILL_CHANCE_MODE,
		FILL_POS_MODE,
	};

	bool isInactive = true;
	int currentMode = 0;
	int currentStep = 0;
	int currentPattern = 0;
	bool patternAdvance = true;

#include "morse/helpers/ModeSelector.hpp"
#include "morse/structs/Pattern.hpp"
	MorsePattern patterns[8];

	Morse()
	{
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

		for (int step = 0; step < steps; step++)
		{
			configParam(STEP_BUTTON + step, 0.0, 1.0, 0.0, string::f("Step %d", step + 1));
		}
	}

#include "morse/helpers/IteratePatterns.hpp"
#include "morse/helpers/IterateSteps.hpp"
#include "morse/helpers/decorators/PatternDecorator.hpp"
#include "morse/helpers/decorators/StepDecorator.hpp"
#include "morse/helpers/IterateSteps.hpp"
#include "morse/helpers/HoldDetection.hpp"

#include "morse/tasks/Clock.hpp"
#include "morse/tasks/Sequencing.hpp"
#include "morse/tasks/lights/StepLights.hpp"
#include "morse/tasks/lights/PatternLights.hpp"

	void process(const ProcessArgs &args) override
	{
		// don't process anything if there is no clocking
		if (!inputs[CLOCK_INPUT].isConnected())
		{
			return;
		}

		MorseClock(args);

		// ticks on step change
		auto stepCallback = [&](int key, Morse::MorsePattern &pattern, Morse::MorseStep &step) {
			MorseStepDecorator(args, key, pattern, step);

			MorseStepLights(args, key, step);
		};

		// ticks on pattern change
		auto patternCallback = [&](int key, Morse::MorsePattern &pattern) {
			MorsePatternDecorator(args, key, pattern);
			MorsePatternLights(args, key, pattern);

			if (pattern.isCurrent())
			{
				// iterate over the steps of the pattern
				MorseIterateSteps(pattern, stepCallback);
			}
		};

		MorseIteratePatterns(Morse::patterns, patternCallback);
	}
};

#include "morse/Widget.hpp"

Model *modelMorse = createModel<Morse, MorseWidget>("Morse");