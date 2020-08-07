#pragma once

#include "screen.h"

void render_screen(Screen screen, Dim screen_rows, Dim screen_columns, Map map,
                   Dim map_rows, Dim map_columns, Pos offset_r, Pos offset_c,
                   Pos player_r, Pos player_c, Pos player_dr, Pos player_dc);
