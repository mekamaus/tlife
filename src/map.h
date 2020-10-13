#pragma once

#include "block.h"
#include "output.h"
#include "persistence.h"
#include "vector.h"
#include <vector>

/** Block grid map. */
class Map {
public:
  Map(Dim width, Dim height);

  Block &operator[](const Pos2 &pos);
  const Block &operator[](const Pos2 &pos) const;
  friend Persistence &operator<<(Persistence &persistence, const Map &map);
  friend Persistence &operator>>(Persistence &persistence, Map &map);
  friend std::ostream &operator<<(std::ostream &out, const Map &map);
  friend std::istream &operator>>(std::istream &in, Map &map);
  friend Output &operator<<(Output &out, const Map &map);

private:
  const Vector2<Dim> size_;
  std::vector<Block> blocks_;
  Block dummy_;
};
