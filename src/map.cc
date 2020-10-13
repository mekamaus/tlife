#include "map.h"
#include "constants.h"
#include "vector_range.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

Map::Map(Dim width, Dim height) : size_(width, height), dummy_(0) {
  for (const auto &pos : range(size_)) {
    (void)pos;
    blocks_.emplace_back(0);
  }
}

Block &Map::operator[](const Pos2 &pos) {
  if (pos.x < 0 || pos.x >= size_.x || pos.y < 0 || pos.y >= size_.y) {
    return dummy_;
  }

  return blocks_[size_.x * pos.y + pos.x];
}

const Block &Map::operator[](const Pos2 &pos) const {
  if (pos.x < 0 || pos.x >= size_.x || pos.y < 0 || pos.y >= size_.y) {
    return dummy_;
  }

  return blocks_[size_.x * pos.y + pos.x];
}

std::istream &operator>>(std::istream &in, Map &map) {
  in >> map.blocks_;
  return in;
}

std::ostream &operator<<(std::ostream &out, const Map &map) {
  out << map.blocks_;
  return out;
}

Persistence &operator>>(Persistence &persistence, Map &map) {
  if (access(persistence.map_file, F_OK) == -1) {
    return persistence;
  }

  std::ifstream fin(persistence.map_file, std::ios::in | std::ios::binary);
  fin >> map;
  fin.close();

  return persistence;
}

Persistence &operator<<(Persistence &persistence, const Map &map) {
  std::ofstream fout(persistence.map_file, std::ios::out | std::ios::binary);
  fout << map;
  fout.close();

  return persistence;
}

Output &operator<<(Output &out, const Map &map) {
  for (const Dim2 &pos : range(map.size_)) {
    (void)pos;
    //
  }
  return out;
}
