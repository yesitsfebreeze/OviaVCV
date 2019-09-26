struct MorseStep
{
  bool active = true;

public:
  bool isActive()
  {
    return this->active;
  }
  void setActive(bool active)
  {
    this->active = active;
  }
  void toggle()
  {
    this->active = !this->active;
  }
};