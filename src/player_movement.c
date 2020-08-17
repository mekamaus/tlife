#include "player_movement.h"
#include "player_target.h"

const Pos2 MOVE_RIGHT = {1, 0};
const Pos2 MOVE_LEFT = {-1, 0};
const Pos2 MOVE_UP = {0, -1};
const Pos2 MOVE_DOWN = {0, 1};
const Pos2 NO_MOVEMENT = {0, 0};

bool change_pos(Pos2 *pos, const Pos2 *target);

void adjust_pos(Pos2 *pos, const Pos2 *delta);

const Pos2 *delta_from_movement_control(Control control);

void move_player(const Map map, const Dim2 *map_size, Pos2 *pos, Pos2 *delta,
                 Control control) {
  if (!change_pos(delta, delta_from_movement_control(control)) &&
      !get_target_block(map, map_size, pos, delta)) {
    adjust_pos(pos, delta);
  }
}

bool change_pos(Pos2 *pos, const Pos2 *target) {
  if (pos->x != target->x || pos->y != target->y) {
    *pos = *target;
    return true;
  }
  return false;
}

void adjust_pos(Pos2 *pos, const Pos2 *delta) {
  pos->x += delta->x;
  pos->y += delta->y;
}

const Pos2 *delta_from_movement_control(Control control) {
  if (control == CONTROL_LEFT) {
    return &MOVE_LEFT;
  }
  if (control == CONTROL_DOWN) {
    return &MOVE_DOWN;
  }
  if (control == CONTROL_UP) {
    return &MOVE_UP;
  }
  if (control == CONTROL_RIGHT) {
    return &MOVE_RIGHT;
  }
  return &NO_MOVEMENT;
}
