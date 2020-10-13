#include "loop.h"

void ProcessFrame(Clock &clock, Terminal &terminal, Game &game, Input &input,
                  Output &output, Persistence &persistence) {
  clock >> game;
  input >> game;
  persistence << game;

  terminal >> output;
  output << game;
  terminal << output;
}

void Loop::Run() {
  while (true) {
    ProcessFrame(*clock_, *terminal_, *game_, *input_, *output_, *persistence_);
    clock_++;
  }
}
