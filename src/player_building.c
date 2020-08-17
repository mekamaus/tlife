#include "player_building.h"
#include "player_target.h"

bool build_map(Map map, const Dim2 *map_size, const Pos2 *pos,
               const Pos2 *delta, Control control) {
  if (!map_contains_target(map_size, pos, delta)) {
    return false;
  }

  if (control == CONTROL_DESTROY) {
    if (get_target_block(map, map_size, pos, delta)) {
      set_target_block(map, map_size, pos, delta, 0);
      return true;
    }
    return false;
  }

  if (control == CONTROL_BUILD) {
    if (!get_target_block(map, map_size, pos, delta)) {
      set_target_block(map, map_size, pos, delta, 1);
      return true;
    }
    return false;
  }

  return false;
}
