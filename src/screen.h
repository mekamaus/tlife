#pragma once

#include "cell.h"
#include "center.h"
#include "terminal.h"
#include "vector.h"
#include <vector>

/** Screen state. */
class Screen {
public:
  Screen();
  Screen(const Screen &) = delete;
  Screen &operator=(const Screen &) = delete;

  Cell &operator[](const Dim2 &pos);

  friend Terminal &operator<<(Terminal &terminal, const Screen &screen);
  friend Terminal &operator>>(Terminal &terminal, Screen &screen);

  void GetCenterOffset(const Center &center, Pos2 *offset);

private:
  /** Gets the number of cells in screen data. */
  Dim GetLength() const;

  /** Gets the index of the cell at a position. */
  Dim GetCellIndex(const Dim2 &pos) const;

  std::vector<Cell> cells_;
  Vector2<Dim> size_;
};
