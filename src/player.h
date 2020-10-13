#pragma once

#include "center.h"
#include "input.h"
#include "map.h"
#include "output.h"
#include "persistence.h"
#include "vector.h"

/** Player state. */
class Player {
public:
  Player(Map &map) : map_(&map), center_(pos_) {}

  friend Input &operator>>(Input &in, const Player &player);
  friend Output &operator<<(Output &out, const Player &player);
  friend Input &operator>>(Input &in, Player &player);
  friend Persistence &operator<<(Persistence &persistence,
                                 const Player &player);
  friend Persistence &operator>>(Persistence &persistence, Player &player);
  friend std::istream &operator>>(std::istream &in, const Player &player);
  friend std::ostream &operator<<(std::ostream &out, const Player &player);

  const Center &GetCenter() const;

private:
  const Shape &GetBody() const;

  Pos2 pos_;
  bool stride_;
  Pos2 target_delta_;
  Map *map_;
  Center center_;
};
