#include "player.h"
#include "player_building.h"
#include "player_movement.h"

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
