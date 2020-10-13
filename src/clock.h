#pragma once

#include "time.h"

class Clock {
public:
  Clock() : tick_time_(get_time()) {}

  const Clock &operator++();
  Clock &operator++(int dummy);

private:
  void Tick();

  Time tick_time_;
};
