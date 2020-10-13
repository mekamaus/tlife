#pragma once

#include "vector.h"

class Center {
public:
  explicit Center(const Pos2 &pos) : pos_(&pos) {}

  operator const Pos2 &() const;

private:
  const Pos2 *pos_;
};
