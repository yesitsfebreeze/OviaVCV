#include "rack.hpp"

using namespace rack;

extern Plugin *pluginInstance;

extern Model *modelMorse;

// struct Trigger : dsp::SchmittTrigger
// {
//   // implements a 0.1V - 1.0V SchmittTrigger (see include/dsp/digital.hpp) instead of
//   //   calling SchmittTriggerInstance.process(math::rescale(in, 0.1f, 1.f, 0.f, 1.f))
//   bool process(float in)
//   {
//     if (state)
//     {
//       // HIGH to LOW
//       if (in <= 0.1f)
//       {
//         state = false;
//       }
//     }
//     else
//     {
//       // LOW to HIGH
//       if (in >= 1.0f)
//       {
//         state = true;
//         return true;
//       }
//     }
//     return false;
//   }
// };

// struct UpTrigger : dsp::SchmittTrigger
// {
//   // implements a reversed 0.1V - 1.0V SchmittTrigger (see include/dsp/digital.hpp) instead of
//   //   calling SchmittTriggerInstance.process(math::rescale(in, 0.1f, 1.f, 0.f, 1.f))
//   bool process(float in)
//   {
//     if (state)
//     {
//       // HIGH to LOW
//       if (in >= 1.0f)

//       {
//         state = false;
//       }
//     }
//     else
//     {
//       // LOW to HIGH
//       if (in <= 0.1f)
//       {
//         state = true;
//         return true;
//       }
//     }
//     return false;
//   }
// };

struct HoldDetect
{
  long modeHoldDetect; // 0 when not detecting, downward counter when detecting

  void reset()
  {
    modeHoldDetect = 0l;
  }

  void start(long startValue)
  {
    modeHoldDetect = startValue;
  }

  bool process(float paramValue)
  {
    bool ret = false;
    if (modeHoldDetect > 0l)
    {
      if (paramValue < 0.5f)
        modeHoldDetect = 0l;
      else
      {
        if (modeHoldDetect == 1l)
        {
          ret = true;
        }
        modeHoldDetect--;
      }
    }
    return ret;
  }
};
