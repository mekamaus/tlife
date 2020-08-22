#include "time.h"
#include <time.h>
#include <unistd.h>

const Duration DurationSecond = 1e3;

Time get_time() {
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  return ts.tv_sec * 1e3 + ts.tv_nsec / 1e6;
}

void sleep_until(Time until) {
  Time time = get_time();
  if (time < until) {
    usleep(until - time);
  }
}
