#pragma once

#include <iostream>

typedef unsigned short BlockValue;

/** An element in a Map. */
typedef struct Block {
public:
  Block(BlockValue value) : value_(value) {}
  // TODO: may have to un-delete this, since vector.reserve() uses the copy
  // constructor
  Block &operator=(const Block &other) = delete;
  Block &operator<<(BlockValue value);

  friend std::istream &operator>>(std::istream &in, std::vector<Block> &blocks);
  friend std::ostream &operator<<(std::ostream &out,
                                  const std::vector<Block> &blocks);

private:
  BlockValue value_;
} Block;

/** An empty block. */
const BlockValue BLOCK_EMPTY = 0;

/** A wall block. */
const BlockValue BLOCK_WALL = 1;
