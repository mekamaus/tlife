#pragma once

#include "block.h"
#include "bool.h"
#include "vector.h"
#include <stdio.h>

// A collection of blocks in a grid arrangement.
typedef Block *Map;

// Returns the block at the given row and column.
Block get_map_block(const Map map, const Dim2 *size, const Dim2 *pos);

// Sets the block at the given row and column.
void set_map_block(Map map, const Dim2 *size, const Dim2 *pos, Block value);
