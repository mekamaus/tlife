#pragma once

#include "vector.h"
#include <ostream>

class Terminal {
public:
  Terminal(std::ostream &out) : out_(&out) {}

  Terminal &operator>>(Vector2<Dim> &size);
  Terminal &operator<<(const char *str);

private:
  std::ostream *out_;
};

/** Sets the cursor visibility. */
void set_cursor_visibility(int visible);
