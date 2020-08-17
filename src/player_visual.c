#include "player_visual.h"
#include "constants.h"
#include "shape.h"

#define GET_CELL(result_var, offset_var)                                       \
  Dim2 result_var##_screen_position;                                           \
  offset_position(&result_var##_screen_position, pos, offset, offset_var);     \
  Cell *result_var##_cell =                                                    \
      get_screen_cell(screen, screen_size, &result_var##_screen_position)

void offset_position(Dim2 *result, const Pos2 *source,
                     const Pos2 *screen_offset, const Pos2 *offset) {
  result->x = source->x + screen_offset->x + offset->x;
  result->y = source->y + screen_offset->y + offset->y;
}

void render_player(Screen screen, const Dim2 *screen_size, const Pos2 *offset,
                   const Pos2 *pos, const Pos2 *delta) {
  GET_CELL(body, &BODY_OFFSET);
  GET_CELL(head, &HEAD_OFFSET);
  GET_CELL(target, delta);

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
