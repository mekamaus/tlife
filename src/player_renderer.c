#include "player_renderer.h"
#include "shape.h"

#define OFFSET_SCREEN_POSITION(result_var, offset_var)                         \
  Dim2 result_var;                                                             \
  offset_position(&result_var, pos, offset, offset_var);

void offset_position(Dim2 *result, const Pos2 *source,
                     const Pos2 *screen_offset, const Pos2 *offset) {
  result->x = source->x + screen_offset->x + offset->x;
  result->y = source->y + screen_offset->y + offset->y;
}

const Pos2 BODY_OFFSET = {0, 0};
const Pos2 HEAD_OFFSET = {0, -1};

void render_player(
    // screen
    Screen screen, const Dim2 *screen_size, const Pos2 *offset,
    // player
    const Pos2 *pos, const Pos2 *delta) {
  OFFSET_SCREEN_POSITION(body_screen_position, &BODY_OFFSET);
  OFFSET_SCREEN_POSITION(head_screen_position, &HEAD_OFFSET);
  OFFSET_SCREEN_POSITION(target_screen_position, delta);

  Cell *body_cell =
      screen + get_screen_index(screen_size, &body_screen_position);
  Cell *head_cell =
      screen + get_screen_index(screen_size, &head_screen_position);
  Cell *target_cell =
      screen + get_screen_index(screen_size, &target_screen_position);

  set_fg_color(body_cell, PURPLE);
  body_cell->shape =
      delta->y > 0
          ? PLAYER_BODY_FRONT
          : delta->y < 0 ? PLAYER_BODY_BACK
                         : delta->x < 0 ? PLAYER_BODY_LEFT : PLAYER_BODY_RIGHT;

  set_fg_color(head_cell, LIGHT_OLIVE);
  head_cell->shape = PLAYER_HEAD;

  set_fg_color(target_cell, WHITE);
  target_cell->shape = EMPTY_TARGET;
}
