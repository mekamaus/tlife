#pragma once

#include "center.h"
#include "screen.h"
#include "terminal.h"

class Output {
public:
  Cell &operator[](const Pos2 &pos);
  Output &operator<<(const Center &center);

  friend Terminal &operator>>(Terminal &terminal, Output &output);
  friend Terminal &operator<<(Terminal &terminal, const Output &output);

private:
  /** Screen to render objects to. */
  Screen screen_;

  /** Offset with which to render objects. */
  Pos2 offset_;
};
