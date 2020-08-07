#pragma once

#include "block.h"
#include "color.h"
#include "file.h"
#include "scalar.h"
#include <stdio.h>

// A collection of elements in a grid arrangement.
typedef int *Map;

// Returns true if the block at the given row and column is zero, false
// otherwise.
int is_map_cell_empty(Map map, Dim rows, Dim columns, Dim r, Dim c);

// Returns true if the given row and column is inside the map boundaries, false
// otherwise.
int is_inside_map(Dim rows, Dim columns, Pos r, Pos c);

// Returns the block at the given row and column.
Block get_map_block(Map map, Dim rows, Dim columns, Dim r, Dim c);

// Sets the block at the given row and column.
void set_map_block(Map map, Dim rows, Dim columns, Dim r, Dim c, Block value);
