#pragma once

#include "controls.h"
#include "map.h"

void read_player(Filename filename, int *r, int *c, int *dr, int *dc);

void write_player(Filename filename, int r, int c, int dr, int dc);

void control_player(Map map, int rows, int columns, int *r, int *c, int *dr,
                    int *dc, int *player_moved, int *map_changed);
