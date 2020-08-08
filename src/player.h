#pragma once

#include "bool.h"
#include "controls.h"
#include "map.h"
#include "vector.h"

void read_player(const Filename filename, Pos2 *pos, Pos2 *delta);

void write_player(const Filename filename, const Pos2 *pos, const Pos2 *delta);

void control_player(Map map, const Dim2 *size, Pos2 *pos, Pos2 *delta,
                    bool *player_moved, bool *map_changed);
