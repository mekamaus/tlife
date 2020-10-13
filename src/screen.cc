#include "screen.h"
#include "constants.h"
#include "vector_range.h"

Dim Screen::GetLength() const { return (size_.x + 1) * size_.y; }

Screen::Screen() : size_(0, 1) {
  cells_.reserve(1);
  cells_.emplace_back(WHITE, BLACK, "\r\r\r\r\r\0");
}

Dim Screen::GetCellIndex(const Dim2 &pos) const {
  return (size_.x + 1) * pos.y + pos.x;
}

const char SCREEN_PREFIX[] = "\e[0;0H";

Cell &Screen::operator[](const Dim2 &pos) { return cells_[GetCellIndex(pos)]; }

Terminal &operator<<(Terminal &terminal, const Screen &screen) {
  terminal << SCREEN_PREFIX << screen.cells_;
  return terminal;
}

Terminal &operator>>(Terminal &terminal, Screen &screen) {
  terminal >> screen.size_;

  screen.cells_.clear();
  screen.cells_.reserve(screen.GetLength());

  for (const auto &pos : range(screen.size_ + Dim2(1, 0))) {
    screen.cells_.emplace_back(
        WHITE, BLACK,
        pos.x < screen.size_.x
            ? " \b  \b "
            : pos.y < screen.size_.y - 1 ? "\r\r\r\r\r\n" : "\r\r\r\r\r\0");
  }

  return terminal;
}

void Screen::GetCenterOffset(const Center &center, Pos2 *offset) {
  const Pos2 &center_pos = center;
  *offset = center_pos - size_ / 2;
}
