#pragma once

#include "bool.h"
#include "vector.h"

/** Changes a position to a target. Returns whether the position changed. */
bool change_pos(Pos2 *pos, const Pos2 *target);

/** Changes a dimension to a target. Returns whether the dimension changed. */
bool change_dim(Dim2 *dim, const Dim2 *target);

/** Adjusts a position by a delta. */
void adjust_pos(Pos2 *pos, const Pos2 *delta);
