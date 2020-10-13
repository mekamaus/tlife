#include "game.h"

Output &operator<<(Output &out, const Game &game) {
  out << game.player_.GetCenter() << game.map_ << game.player_;
  return out;
}

Input &operator>>(Input &in, Game &game) {
  in >> game.player_;
  return in;
}

Persistence &operator<<(Persistence &persistence, const Game &game) {
  persistence << game.player_ << game.map_;
  return persistence;
}

Persistence &operator>>(Persistence &persistence, Game &game) {
  persistence >> game.player_ >> game.map_;
  return persistence;
}

Clock &operator>>(Clock &clock, Game &game) { return clock; }
