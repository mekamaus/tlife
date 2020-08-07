#include "screen_renderer.h"

void render_screen(Screen screen, Dim screen_rows, Dim screen_columns, Map map,
                   Dim map_rows, Dim map_columns, Pos offset_r, Pos offset_c,
                   Pos player_r, Pos player_c, Pos player_dr, Pos player_dc) {
  for (int screen_r = 0; screen_r < screen_rows; ++screen_r) {
    for (int screen_c = 0; screen_c < screen_columns; ++screen_c) {
      int cell_r = screen_r - offset_r;
      int cell_c = screen_c - offset_c;

      render_cell(map, map_rows, map_columns, cell_r, cell_c, player_r,
                  player_c, player_dr, player_dc,
                  screen + (screen_columns + 1) * screen_r + screen_c);
    }
  }
}
