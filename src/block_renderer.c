#include "block_renderer.h"
#include "color.h"

// const Shape *get_target_shape(int dr, int dc);
// const Shape *get_target_shape_left(int dr, int dc);
// const Shape *get_target_shape_right(int dr, int dc);

void render_block(Cell *cell, Block block) {
  // int inside = is_inside_map(rows, columns, cell_r, cell_c);
  // int target_inside =
  //    is_inside_map(rows, columns, player_r + player_dr, player_c +
  //    player_dc);

  // int inside_bg_color = DARK_GREEN;
  // int outside_bg_color = BLACK;

  // int actual_bg_color = inside ? inside_bg_color : outside_bg_color;

  // if (cell_r == player_r - 1 && cell_c == player_c) {
  //  set_fg_color(cell, LIGHT_OLIVE);
  //  set_bg_color(cell, empty ? actual_bg_color : LIGHT_GRAY);
  //  cell->shape = PLAYER_HEAD;
  //} else if (cell_r == player_r && cell_c == player_c) {
  //  set_fg_color(cell, PURPLE);
  //  set_bg_color(cell, actual_bg_color);
  //  cell->shape = player_dr > 0
  //                    ? PLAYER_BODY_FRONT
  //                    : player_dr < 0 ? PLAYER_BODY_BACK
  //                                    : player_dc < 0 ? PLAYER_BODY_LEFT
  //                                                    : PLAYER_BODY_RIGHT;
  //} else if (cell_r == player_r + player_dr && cell_c == player_c + player_dc)
  //{
  //  // Target
  //  set_fg_color(cell, target_inside ? WHITE : RED);
  //  set_bg_color(cell, empty ? actual_bg_color : LIGHT_GRAY);
  //  cell->shape = *get_target_shape(player_dr, player_dc);
  //} else if (player_dr == -1 && player_dc == 0 &&
  //           cell_r == player_r + player_dr &&
  //           cell_c == player_c + player_dc - 1) {
  //  // Target behind head, left
  //  set_fg_color(cell, target_inside ? WHITE : RED);
  //  set_bg_color(cell, empty ? actual_bg_color : LIGHT_GRAY);
  //  cell->shape = *get_target_shape_left(player_dr, player_dc);
  // } else
  // if (player_dr == -1 && player_dc == 0 && cell_r == player_r + player_dr &&
  //    cell_c == player_c + player_dc + 1) {
  //  // Target behind head, right
  //  set_fg_color(cell, target_inside ? WHITE : RED);
  //  set_bg_color(cell, empty ? actual_bg_color : LIGHT_GRAY);
  //  cell->shape = *get_target_shape_right(player_dr, player_dc);
  //} else

  set_fg_color(cell, LIGHT_GRAY);
  set_bg_color(cell, DARK_GREEN);
  cell->shape = block ? BLOCK : EMPTY;
}
