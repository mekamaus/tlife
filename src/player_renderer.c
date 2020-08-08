#include "player_renderer.h"
#include "shape.h"

// Gets the shape of the player's action target.
const Shape *get_target_shape(int dr, int dc);

// Gets the left side of the shape of the player's action target, when split.
const Shape *get_target_shape_left(int dr, int dc);

// Gets the right side of the shape of the player's action target, when split.
const Shape *get_target_shape_right(int dr, int dc);

void render_player(
    // screen
    Screen screen, const Dim2 *screen_size,
    // player
    const Pos2 *pos, const Pos2 *delta,
    // offset
    const Pos2 *offset) {
  Pos2 screen_pos = {
      pos->x + offset->x,
      pos->y + offset->y,
  };
  Cell *body_cell = screen + screen_size->x * screen_pos.y + screen_pos.x;
  set_fg_color(body_cell, PURPLE);
  body_cell->shape =
      delta->y > 0
          ? PLAYER_BODY_FRONT
          : delta->y < 0 ? PLAYER_BODY_BACK
                         : delta->x < 0 ? PLAYER_BODY_LEFT : PLAYER_BODY_RIGHT;

  Cell *head_cell = screen + screen_size->x * (screen_pos.y - 1) + screen_pos.x;
  set_fg_color(head_cell, LIGHT_OLIVE);
  head_cell->shape = PLAYER_HEAD;

  Cell *target_cell = screen + screen_size->x * (screen_pos.y + delta->y) +
                      (screen_pos.x + delta->x);
  set_fg_color(target_cell, WHITE);
  target_cell->shape = EMPTY_TARGET;
}

const Shape *get_target_shape(int dr, int dc) { return &EMPTY_TARGET; }

const Shape *get_target_shape_left(int dr, int dc) {
  return &EMPTY_TARGET_LEFT;
}

const Shape *get_target_shape_right(int dr, int dc) {
  return &EMPTY_TARGET_RIGHT;
}
