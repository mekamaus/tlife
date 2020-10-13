#pragma once

class Control {
public:
  typedef unsigned long long Flags;

  typedef enum Value {
    STEP,
    STRIDE,
    MOVEMENT,
    L,
    D,
    U,
    R,
    BUILD,
    DESTROY,
    CONSTRUCT,
    EXIT,
    STOP,
  } Value;

  Control() : flags_(0) {}
  Control(const Control &other) = delete;

  Control &operator=(Flags flags);
  Control &operator|=(Value value);
  bool operator[](Value value);
  Control &operator>>(Control &other);

private:
  Flags flags_;
};
