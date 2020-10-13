#include "clock.h"
#include "constants.h"

const Clock &Clock::operator++() {
  Tick();
  return *this;
}

Clock &Clock::operator++(int dummy) {
  Tick();
  return *this;
}

void Clock::Tick() {
  tick_time_ += DurationSecond / TARGET_FPS;
  sleep_until(tick_time_);
}
