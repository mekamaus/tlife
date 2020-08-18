#pragma once

#include "bool.h"
#include "control.h"
#include "map.h"
#include "vector.h"

/**
 * Controls the player. Returns whether the given state was changed as a result.
 */
bool control_player(Map map, const Dim2 *size, Pos2 *pos, Pos2 *delta,
                    bool *stride, Control control);
