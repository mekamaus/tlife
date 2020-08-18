#include "player.h"
#include "control_delta.h"
#include "player_building.h"
#include "player_target.h"
#include "vector_math.h"
#include <stdlib.h>

bool control_player(Map map, const Dim2 *map_size, Pos2 *pos, Pos2 *delta,
                    bool *stride, Control control) {
  // Building
  if (is_building_control(control)) {
    Block block = control == 'a' ? 1 : 0;
    return build_map(map, map_size, pos, delta, block);
  }

  // Movement
  const Pos2 *new_delta = delta_from_movement_control(control);
  if (is_step_control(control)) {
    *stride = false;
    if (change_pos(delta, new_delta)) {
      return true;
    }

    if (!get_target_block(map, map_size, pos, delta)) {
      adjust_pos(pos, delta);
      return true;
    }
  }

  if (is_stop_control(control)) {
    *stride = false;
  }

  if (is_stride_control(control)) {
    *stride = true;
    if (change_pos(delta, new_delta)) {
      return true;
    }
  }

  if (!*stride) {
    return false;
  }

  if (!get_target_block(map, map_size, pos, delta)) {
    adjust_pos(pos, delta);
    return true;
  }

  *stride = false;
  return false;
}
