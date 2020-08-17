#include "player_target.h"

bool map_contains_target(const Dim2 *map_size, const Pos2 *pos,
                         const Pos2 *delta) {
  return pos->x + delta->x >= 0 && pos->x + delta->x < map_size->x &&
         pos->y + delta->y >= 0 && pos->y + delta->y < map_size->y;
}

Block get_target_block(const Map map, const Dim2 *size, const Pos2 *pos,
                       const Pos2 *delta) {
  Dim2 target = {
      pos->x + delta->x,
      pos->y + delta->y,
  };
  if (!map_contains_target(size, pos, delta)) {
    return 0;
  }

  return get_map_block(map, size, &target);
}

void set_target_block(Map map, const Dim2 *size, const Pos2 *pos,
                      const Pos2 *delta, Block block) {
  if (!map_contains_target(size, pos, delta)) {
    return;
  }

  Dim2 target = {
      pos->x + delta->x,
      pos->y + delta->y,
  };

  set_map_block(map, size, &target, block);
}
