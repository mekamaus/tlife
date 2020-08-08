#pragma once

#include "block.h"
#include "bool.h"
#include "file.h"
#include "vector.h"
#include <stdio.h>

// A collection of elements in a grid arrangement.
typedef Block *Map;

// Returns true if the block at the given row and column is zero, false
// otherwise.
bool is_map_block_empty(Map map, const Dim2 *size, const Pos2 *pos);

// Returns the block at the given row and column.
Block get_map_block(Map map, const Dim2 *size, const Pos2 *pos);

// Sets the block at the given row and column.
void set_map_block(Map map, const Dim2 *size, const Pos2 *pos, Block value);
