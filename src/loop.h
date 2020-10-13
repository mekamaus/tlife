#pragma once

#include "clock.h"
#include "game.h"
#include "input.h"
#include "output.h"
#include "persistence.h"
#include "terminal.h"

class Loop {
public:
  Loop(Game &game, Input &input, Output &output, Persistence &persistence)
      : game_(&game), input_(&input), output_(&output),
        persistence_(&persistence) {}

  /** Runs the loop until exit. */
  void Run();

private:
  Clock *clock_;
  Terminal *terminal_;
  Game *game_;
  Input *input_;
  Output *output_;
  Persistence *persistence_;
};
