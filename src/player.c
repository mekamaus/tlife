#include "player.h"
#include "player_movement.h"
#include "player_target.h"
#include "unistd.h"
#include "vector.h"

// Changes a position to match a target. Returns whether the position was
// changed.
bool change_pos(Pos2 *pos, const Pos2 *target);

// Adjusts a position by a delta.
void adjust_pos(Pos2 *pos, const Pos2 *delta);

// Alters the map at the target based on the control.
bool build_map(Map map, const Dim2 *size, const Pos2 *pos, const Pos2 *delta,
               Control control);

void control_player(Map map, const Dim2 *map_size, Pos2 *pos, Pos2 *delta,
                    bool *player_moved, bool *map_changed, Control control) {
  *player_moved = false;
  *map_changed = false;

  if (is_movement_control(control)) {
    move_player(map, map_size, pos, delta, control);
    *player_moved = true;
  } else if (is_building_control(control)) {
    *map_changed = build_map(map, map_size, pos, delta, control);
  }
}

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
