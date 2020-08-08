#include "map_renderer.h"
#include "block_renderer.h"

void render_map(
    // Screen
    Screen screen, const Dim2 *screen_size,
    // Map
    const Map map, const Dim2 *map_size,
    // Offset
    const Pos2 *offset) {
  Dim2 map_pos = {0, 0};
  for (; map_pos.y < offset->y + map_size->y; ++map_pos.y) {
    for (; map_pos.x < offset->x + map_size->x; ++map_pos.x) {
      Pos2 screen_pos = {
          map_pos.x + offset->x,
          map_pos.y + offset->y,
      };
      if (screen_pos.x >= 0 && screen_pos.x < screen_size->x &&
          screen_pos.y >= 0 && screen_pos.y < screen_size->y) {
        render_block(screen + (screen_size->x + 1) * screen_pos.y +
                         screen_pos.x,
                     map[map_size->x * map_pos.y + map_pos.x]);
      }
    }
  }
}
