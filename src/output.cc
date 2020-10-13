#include "output.h"

Cell &Output::operator[](const Pos2 &pos) {
  return screen_[Dim2(pos.x, pos.y)];
}

Output &Output::operator<<(const Center &center) {
  screen_.GetCenterOffset(center, &offset_);
  return *this;
}

Terminal &operator>>(Terminal &terminal, Output &output) {
  return terminal >> output.screen_;
}

Terminal &operator<<(Terminal &terminal, const Output &output) {
  return terminal << output.screen_;
}
