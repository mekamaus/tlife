#include "player.h"

#define SCREEN_CELL char *
#define CHAR char *
#define SCREEN char *

const SCREEN_CELL EMPTY_CELL = "\033[38;5;255m\033[48;5;000m  \b\b  ";

const int COLOR_LENGTH = 3;
const int COLORS_LENGTH = 22;
const int FG_COLOR_INDEX = 7;
const int BG_COLOR_INDEX = 18;
const int CHAR_LENGTH = 3;
const int CHARS_PER_CELL = 2;
const int CELL_LENGTH = COLORS_LENGTH + CHAR_LENGTH * CHARS_PER_CELL;

void _set_shape_half(SCREEN screen, int index, CHAR ch) {
  for (int i = 0; i < CHAR_LENGTH; ++i) {
    screen[index + i] = ch[i];
  }
}

void _set_shape(SCREEN screen, int index, SHAPE shape) {
  _set_shape_half(screen, index + COLORS_LENGTH, shape);
  _set_shape_half(screen, index + COLORS_LENGTH + CHAR_LENGTH,
                  shape + CHAR_LENGTH);
}

void _set_color(SCREEN screen, int index, int color_index, int color) {
  for (int i = 0; i < COLOR_LENGTH; ++i) {
    screen[index + color_index + COLOR_LENGTH - i - 1] =
        (char)('0' + color % 10);
    color /= 10;
  }
}

void _set_fg_color(SCREEN screen, int index, int color) {
  _set_color(screen, index, FG_COLOR_INDEX, color);
}

void _set_bg_color(SCREEN screen, int index, int color) {
  _set_color(screen, index, BG_COLOR_INDEX, color);
}

void set_screen_cell(SCREEN screen, int rows, int columns, int i, int j,
                     int fg_color, int bg_color, SHAPE shape) {
  int row_length = CELL_LENGTH * columns + 1;
  int cell_start = row_length * i + CELL_LENGTH * j;
  _set_fg_color(screen, cell_start, fg_color);
  _set_bg_color(screen, cell_start, bg_color);
  _set_shape(screen, cell_start, shape);
}

SCREEN create_screen(int rows, int columns) {
  int row_length = CELL_LENGTH * columns + 1;

  SCREEN screen = malloc(rows * row_length);

  for (int i = 0; i < rows; ++i) {
    int row_start = row_length * i;
    for (int j = 0; j < columns; ++j) {
      int cell_start = row_start + CELL_LENGTH * j;
      for (int k = 0; k < CELL_LENGTH; ++k) {
        screen[cell_start + k] = EMPTY_CELL[k];
      }
    }
    screen[row_start + row_length - 1] = (i == rows - 1) ? '\0' : '\n';
  }

  return screen;
}

void resize_screen(SCREEN *screen, int rows, int columns) {
  free(*screen);
  *screen = create_screen(rows, columns);
}

void render_screen_map(SCREEN screen, int screen_rows, int screen_columns,
                       MAP map, int map_rows, int map_columns, int offset_r,
                       int offset_c, int player_r, int player_c, int player_dr,
                       int player_dc) {
  for (int screen_r = 0; screen_r < screen_rows; ++screen_r) {
    for (int screen_c = 0; screen_c < screen_columns; ++screen_c) {
      int cell_r = screen_r - offset_r;
      int cell_c = screen_c - offset_c;

      int fg_color;
      int bg_color;
      SHAPE shape;

      get_map_cell(map, map_rows, map_columns, cell_r, cell_c, player_r,
                   player_c, player_dr, player_dc, &fg_color, &bg_color,
                   &shape);

      set_screen_cell(screen, screen_rows, screen_columns, screen_r, screen_c,
                      fg_color, bg_color, shape);
    }
  }
}
