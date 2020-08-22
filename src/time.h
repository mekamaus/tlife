#pragma once

/** Time, defined in UTC milliseconds. */
typedef unsigned long Time;

/** Duration, defined in milliseconds. */
typedef unsigned long Duration;

/** Duration of a second. */
extern const Duration DurationSecond;

/** Gets the current time. */
Time get_time();

/** Sleeps until a given time. */
void sleep_until(Time until);
