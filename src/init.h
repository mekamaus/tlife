#pragma once

#include "filename.h"
#include "screen.h"
#include "vector.h"

/** Prepares game state for loop. */
void init_game(const Filename player_file, Pos2 *player_pos, Pos2 *player_delta,
               const Filename map_file, Map map, Dim2 *map_size, Screen *screen,
               const Dim2 *screen_size);
