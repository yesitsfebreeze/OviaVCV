struct MorseHoldDetection
{
  long modeHoldDetection; // 0 when not detecting, downward counter when detecting

  void reset()
  {
    modeHoldDetection = 0l;
  }

  void start(long startValue)
  {
    modeHoldDetection = startValue;
  }

  bool process(float paramValue)
  {
    bool ret = false;
    if (modeHoldDetection > 0l)
    {
      if (paramValue < 0.5f)
        modeHoldDetection = 0l;
      else
      {
        if (modeHoldDetection == 1l)
        {
          ret = true;
        }
        modeHoldDetection--;
      }
    }
    return ret;
  }
};
