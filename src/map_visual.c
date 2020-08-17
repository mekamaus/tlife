#include "map_visual.h"
#include "block_visual.h"

void render_map(
    // Screen
    Screen screen, const Dim2 *screen_size, const Pos2 *offset,
    // Map
    const Map map, const Dim2 *map_size) {
  Dim2 map_pos;
  for (map_pos.y = offset->y < 0 ? -offset->y : 0;
       map_pos.y < map_size->y && map_pos.y + offset->y < screen_size->y;
       ++map_pos.y) {
    for (map_pos.x = offset->x < 0 ? -offset->x : 0;
         map_pos.x < map_size->x && map_pos.x + offset->x < screen_size->x;
         ++map_pos.x) {
      Dim2 screen_pos = {
          map_pos.x + offset->x,
          map_pos.y + offset->y,
      };
      Cell *cell = get_screen_cell(screen, screen_size, &screen_pos);
      Block block = get_map_block(map, map_size, &map_pos);
      render_block(cell, block);
    }
  }
}
