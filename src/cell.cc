#include "cell.h"

Terminal &operator<<(Terminal &terminal, const std::vector<Cell> &cells) {
  terminal << (char *)&cells.front();
  return terminal;
}

ColorBytes &ColorBytes::operator<<(Color color) {
  bytes_[0] = '0' + color / 100;
  bytes_[1] = '0' + (color / 10) % 10;
  bytes_[2] = '0' + color % 10;
  return *this;
}

ColorSequence &ColorSequence::operator<<(Color color) {
  color_ << color;
  return *this;
}

Cell &Cell::operator<<(Color color) {
  foreground_ << color;
  return *this;
}

Cell &Cell::operator<<(const Shape &shape) {
  shape_ = shape;
  return *this;
}
