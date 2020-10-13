#include "input.h"

void *read_loop_func(void *input_data) {
  Input &input = *(Input *)input_data;
  while (true) {
    pthread_mutex_lock(&input.lock_);
    input.control_ = input.bindings_[input.keyboard_.GetChar()];
    pthread_mutex_unlock(&input.lock_);
  }
  pthread_exit(NULL);
}

Input::Input(const std::vector<ControlBinding> &control_bindings) {
  for (const ControlBinding &binding : control_bindings) {
    for (const Key &key : binding.keys) {
      bindings_[key] |= binding.control;
    }
  }

  pthread_mutex_init(&lock_, NULL);
  pthread_create(&read_thread_, NULL, &read_loop_func, this);
}

Input::~Input() {
  pthread_cancel(read_thread_);
  pthread_join(read_thread_, NULL);
  pthread_mutex_destroy(&lock_);
}

Input &Input::operator>>(Control &control) {
  pthread_mutex_lock(&lock_);
  control_ >> control;
  pthread_mutex_unlock(&lock_);

  return *this;
}
