#include "control.h"

Control &Control::operator=(Flags flags) {
  flags_ = flags;
  return *this;
}

Control &Control::operator|=(Value value) {
  flags_ |= 1 << value;
  return *this;
}

bool Control::operator[](Value value) { return !!(flags_ & (1 << value)); }

Control &Control::operator>>(Control &other) {
  other.flags_ = flags_;
  flags_ = 0;
  return *this;
}
