#pragma once

#include "filename.h"
#include "map.h"
#include "screen.h"
#include "vector.h"

// Loops the game until it is ready to terminate.
void loop_game(const Filename player_file, Pos2 *player_pos, Pos2 *player_delta,
               const Filename map_file, Map map, Dim2 *map_size, Screen *screen,
               Dim2 *screen_size);
