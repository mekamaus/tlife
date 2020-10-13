#pragma once

#include "clock.h"
#include "input.h"
#include "map.h"
#include "output.h"
#include "persistence.h"
#include "player.h"

/** Game state. */
class Game {
public:
  Game(Dim width, Dim height) : map_(width, height), player_(map_) {}

  friend Output &operator<<(Output &out, const Game &game);
  friend Input &operator>>(Input &in, Game &game);
  friend Persistence &operator<<(Persistence &persistence, const Game &game);
  friend Persistence &operator>>(Persistence &persistence, Game &game);
  friend Clock &operator>>(Clock &clock, Game &game);

private:
  Map map_;
  Player player_;
};
