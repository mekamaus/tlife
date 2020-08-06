#include "color.h"
#include "file.h"

#define MAP int *
#define MAP_CELL int
#define DIM unsigned int
#define POS int
#define SHAPE char *

SHAPE PLAYER_HEAD = "";
SHAPE PLAYER_BODY_FRONT = "▜▛";
SHAPE PLAYER_BODY_BACK = "▜▛";
SHAPE PLAYER_BODY_LEFT = "▜▍";
SHAPE PLAYER_BODY_RIGHT = "▐▛";

SHAPE EMPTY_TARGET = "";
SHAPE EMPTY_TARGET_LEFT = " \b ";
SHAPE EMPTY_TARGET_RIGHT = " \b ";

SHAPE BLOCK = "██";
SHAPE EMPTY = "  \b\b  ";

SHAPE get_target_shape(int dr, int dc) { return EMPTY_TARGET; }
SHAPE get_target_shape_left(int dr, int dc) { return EMPTY_TARGET_LEFT; }
SHAPE get_target_shape_right(int dr, int dc) { return EMPTY_TARGET_RIGHT; }

void read_map(FILENAME filename, MAP map) {
  if (access(filename, F_OK) == -1) {
    return;
  }

  FILE *f = fopen(filename, "rb+");
  fread(map, sizeof(MAP_CELL), 400, f);
  fclose(f);
}

void write_map(FILENAME filename, MAP map) {
  FILE *f = fopen(filename, "wb+");
  fwrite(map, sizeof(MAP_CELL), 400, f);
  fclose(f);
}

int is_map_cell_empty(MAP map, DIM rows, DIM columns, DIM r, DIM c) {
  return r < 0 || r >= rows || c < 0 || c >= columns || !map[columns * r + c];
}

int is_inside_map(DIM rows, DIM columns, POS r, POS c) {
  return r >= 0 && r < rows && c >= 0 && c < columns;
}

void get_map_cell(MAP map, DIM rows, DIM columns, DIM cell_r, DIM cell_c,
                  POS player_r, POS player_c, POS player_dr, POS player_dc,
                  COLOR *fg_color, COLOR *bg_color, SHAPE *shape) {
  int empty = is_map_cell_empty(map, rows, columns, cell_r, cell_c);
  int inside = is_inside_map(rows, columns, cell_r, cell_c);
  int target_inside =
      is_inside_map(rows, columns, player_r + player_dr, player_c + player_dc);

  int inside_bg_color = DARK_GREEN;
  int outside_bg_color = BLACK;

  int actual_bg_color = inside ? inside_bg_color : outside_bg_color;

  if (cell_r == player_r - 1 && cell_c == player_c) {
    *fg_color = LIGHT_OLIVE;
    *bg_color = empty ? actual_bg_color : LIGHT_GRAY;
    *shape = PLAYER_HEAD;
  } else if (cell_r == player_r && cell_c == player_c) {
    *fg_color = PURPLE;
    *bg_color = actual_bg_color;
    *shape = player_dr > 0 ? PLAYER_BODY_FRONT
                           : player_dr < 0 ? PLAYER_BODY_BACK
                                           : player_dc < 0 ? PLAYER_BODY_LEFT
                                                           : PLAYER_BODY_RIGHT;
  } else if (cell_r == player_r + player_dr && cell_c == player_c + player_dc) {
    // Target
    *fg_color = target_inside ? WHITE : RED;
    *bg_color = empty ? actual_bg_color : LIGHT_GRAY;
    *shape = get_target_shape(player_dr, player_dc);
  } else if (player_dr == -1 && player_dc == 0 &&
             cell_r == player_r + player_dr &&
             cell_c == player_c + player_dc - 1) {
    // Target behind head, left
    *fg_color = target_inside ? WHITE : RED;
    *bg_color = empty ? actual_bg_color : LIGHT_GRAY;
    *shape = get_target_shape_left(player_dr, player_dc);
  } else if (player_dr == -1 && player_dc == 0 &&
             cell_r == player_r + player_dr &&
             cell_c == player_c + player_dc + 1) {
    // Target behind head, right
    *fg_color = target_inside ? WHITE : RED;
    *bg_color = empty ? actual_bg_color : LIGHT_GRAY;
    *shape = get_target_shape_right(player_dr, player_dc);
  } else if (empty) {
    *fg_color = LIGHT_GRAY;
    *bg_color = actual_bg_color;
    *shape = EMPTY;
  } else {
    *fg_color = LIGHT_GRAY;
    *bg_color = actual_bg_color;
    *shape = BLOCK;
  }
}

void set_map_cell(MAP map, int rows, int columns, int r, int c, int value) {
  if (r < 0 || r >= rows || c < 0 || c >= columns) {
    return;
  }

  map[columns * r + c] = value;
}
