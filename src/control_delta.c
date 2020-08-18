#include "control_delta.h"
#include "constants.h"

const Pos2 MOVE_RIGHT = {1, 0};
const Pos2 MOVE_LEFT = {-1, 0};
const Pos2 MOVE_UP = {0, -1};
const Pos2 MOVE_DOWN = {0, 1};
const Pos2 NO_MOVEMENT = {0, 0};

const Pos2 *delta_from_movement_control(Control control) {
  if (control == CONTROL_STEP_LEFT || control == CONTROL_STRIDE_LEFT) {
    return &MOVE_LEFT;
  }
  if (control == CONTROL_STEP_DOWN || control == CONTROL_STRIDE_DOWN) {
    return &MOVE_DOWN;
  }
  if (control == CONTROL_STEP_UP || control == CONTROL_STRIDE_UP) {
    return &MOVE_UP;
  }
  if (control == CONTROL_STEP_RIGHT || control == CONTROL_STRIDE_RIGHT) {
    return &MOVE_RIGHT;
  }
  return &NO_MOVEMENT;
}
