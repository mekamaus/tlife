#include "player_building.h"
#include "player_target.h"

bool build_map(Map map, const Dim2 *map_size, const Pos2 *pos,
               const Pos2 *delta, Block block) {
  bool changed = get_target_block(map, map_size, pos, delta) != block;
  set_target_block(map, map_size, pos, delta, block);
  return changed;
}
