#pragma once

#include "control.h"
#include "keyboard.h"
#include <pthread.h>
#include <vector>

/** Input control key. */
typedef unsigned char Key;

typedef struct ControlBinding {
  Control::Value control;
  std::vector<Key> keys;
} ControlBinding;

/** Input state. */
class Input {
public:
  Input(const std::vector<ControlBinding> &control_bindings);
  Input(const Input &other) = delete;
  Input &operator=(const Input &other) = delete;
  ~Input();

  typedef struct Config {
    std::vector<ControlBinding> bindings;
  } Config;

  friend void *read_loop_func(void *input_data);

  Input &operator>>(Control &control);

private:
  Keyboard keyboard_;
  Control bindings_[256];
  Control control_;
  pthread_t read_thread_;
  pthread_mutex_t lock_;
};
