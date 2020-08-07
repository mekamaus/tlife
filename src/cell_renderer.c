#include "cell_renderer.h"

void set_fg_color(Cell *cell, Color color);
void set_bg_color(Cell *cell, Color color);
const Shape *get_target_shape(int dr, int dc);
const Shape *get_target_shape_left(int dr, int dc);
const Shape *get_target_shape_right(int dr, int dc);

void render_cell(Map map, Dim rows, Dim columns, Dim cell_r, Dim cell_c,
                 Pos player_r, Pos player_c, Pos player_dr, Pos player_dc,
                 Cell *cell) {
  int empty = is_map_cell_empty(map, rows, columns, cell_r, cell_c);
  int inside = is_inside_map(rows, columns, cell_r, cell_c);
  int target_inside =
      is_inside_map(rows, columns, player_r + player_dr, player_c + player_dc);

  int inside_bg_color = DARK_GREEN;
  int outside_bg_color = BLACK;

  int actual_bg_color = inside ? inside_bg_color : outside_bg_color;

  if (cell_r == player_r - 1 && cell_c == player_c) {
    set_fg_color(cell, LIGHT_OLIVE);
    set_bg_color(cell, empty ? actual_bg_color : LIGHT_GRAY);
    cell->shape = PLAYER_HEAD;
  } else if (cell_r == player_r && cell_c == player_c) {
    set_fg_color(cell, PURPLE);
    set_bg_color(cell, actual_bg_color);
    cell->shape = player_dr > 0
                      ? PLAYER_BODY_FRONT
                      : player_dr < 0 ? PLAYER_BODY_BACK
                                      : player_dc < 0 ? PLAYER_BODY_LEFT
                                                      : PLAYER_BODY_RIGHT;
  } else if (cell_r == player_r + player_dr && cell_c == player_c + player_dc) {
    // Target
    set_fg_color(cell, target_inside ? WHITE : RED);
    set_bg_color(cell, empty ? actual_bg_color : LIGHT_GRAY);
    cell->shape = *get_target_shape(player_dr, player_dc);
  } else if (player_dr == -1 && player_dc == 0 &&
             cell_r == player_r + player_dr &&
             cell_c == player_c + player_dc - 1) {
    // Target behind head, left
    set_fg_color(cell, target_inside ? WHITE : RED);
    set_bg_color(cell, empty ? actual_bg_color : LIGHT_GRAY);
    cell->shape = *get_target_shape_left(player_dr, player_dc);
  } else if (player_dr == -1 && player_dc == 0 &&
             cell_r == player_r + player_dr &&
             cell_c == player_c + player_dc + 1) {
    // Target behind head, right
    set_fg_color(cell, target_inside ? WHITE : RED);
    set_bg_color(cell, empty ? actual_bg_color : LIGHT_GRAY);
    cell->shape = *get_target_shape_right(player_dr, player_dc);
  } else if (empty) {
    set_fg_color(cell, LIGHT_GRAY);
    set_bg_color(cell, actual_bg_color);
    cell->shape = EMPTY;
  } else {
    set_fg_color(cell, LIGHT_GRAY);
    set_bg_color(cell, actual_bg_color);
    cell->shape = BLOCK;
  }
}

void set_color(EscapedColor *escaped_color, Color color) {
  unsigned char color_string[3] = {};
  color_string[0] = '0' + color / 100;
  color_string[1] = '0' + (color / 10) % 10;
  color_string[2] = '0' + color % 10;

  memcpy(escaped_color->data + COLOR_INDEX, color_string, 3);
}

void set_fg_color(Cell *cell, Color color) {
  set_color(&cell->foreground, color);
}

void set_bg_color(Cell *cell, Color color) {
  set_color(&cell->background, color);
}

const Shape *get_target_shape(int dr, int dc) { return &EMPTY_TARGET; }

const Shape *get_target_shape_left(int dr, int dc) {
  return &EMPTY_TARGET_LEFT;
}

const Shape *get_target_shape_right(int dr, int dc) {
  return &EMPTY_TARGET_RIGHT;
}
