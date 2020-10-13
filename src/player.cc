#include "player.h"
#include "constants.h"
#include "control.h"
#include <fstream>
#include <stdio.h>
#include <unistd.h>

std::istream &operator>>(std::istream &in, const Player &player) {
  in >> player.pos_;
  return in;
}

std::ostream &operator<<(std::ostream &out, const Player &player) {
  out << player.pos_;
  return out;
}

Input &operator>>(Input &in, Player &player) {
  Control control;
  in >> control;

  // TODO: add rest of logic
  Block &target_block = (*player.map_)[player.pos_ + player.target_delta_];
  if (control[Control::BUILD]) {
    target_block << BLOCK_WALL;
  }

  if (control[Control::DESTROY]) {
    target_block << BLOCK_EMPTY;
  }

  if (control[Control::MOVEMENT]) {
    // player.target_delta_;
  }

  if (control[Control::EXIT]) {
    //
  }

  return in;
}

const Shape &Player::GetBody() const {
  if (target_delta_.y > 0) {
    return PLAYER_BODY_FRONT;
  } else if (target_delta_.y < 0) {
    return PLAYER_BODY_BACK;
  } else if (target_delta_.x < 0) {
    return PLAYER_BODY_LEFT;
  } else {
    return PLAYER_BODY_RIGHT;
  }
}

Output &operator<<(Output &out, const Player &player) {
  out[player.pos_ + BODY_OFFSET] << PURPLE << player.GetBody();
  out[player.pos_ + HEAD_OFFSET] << LIGHT_OLIVE << PLAYER_HEAD;
  out[player.pos_ + player.target_delta_] << WHITE << EMPTY_TARGET;

  return out;
}

Persistence &operator<<(Persistence &persistence, const Player &player) {
  std::ofstream fout(persistence.player_file, std::ios::out | std::ios::binary);
  fout << player;
  fout.close();

  return persistence;
}

Persistence &operator>>(Persistence &persistence, Player &player) {
  if (access(persistence.player_file, F_OK) == -1) {
    return persistence;
  }

  std::ifstream fin(persistence.player_file, std::ios::in | std::ios::binary);
  fin >> player;
  fin.close();

  return persistence;
}
