#include "block.h"
#include <vector>

Block &Block::operator<<(BlockValue value) {
  value_ = value;
  return *this;
}

std::istream &operator>>(std::istream &in, std::vector<Block> &blocks) {
  in.read((char *)&blocks.front(), sizeof(Block) * blocks.size());
  return in;
}

std::ostream &operator<<(std::ostream &out, const std::vector<Block> &blocks) {
  out.write((char *)&blocks.front(), sizeof(Block) * blocks.size());
  return out;
}
