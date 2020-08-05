#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define CELL char *
#define SHAPE char *
#define SHAPE_HALF char *
#define SCREEN char *
#define MAP int *

const char HIDE_CURSOR_COMMAND[] = "tput civis";

const int MAIN_MAP_ROWS = 20;
const int MAIN_MAP_COLUMNS = 20;
int MAIN_MAP[MAIN_MAP_ROWS * MAIN_MAP_COLUMNS] = {
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, //
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, //
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, //
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, //
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, //
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, //
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, //
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, //
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, //
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, //
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
};

char readkey() {
  FILE *fp = popen("read -n 1 -r -s key; echo $key", "r");
  if (fp == NULL) {
    exit(1);
  }
  char c = fgetc(fp);
  pclose(fp);

  return c;
}

int is_empty(MAP map, int rows, int columns, int r, int c) {
  return r < 0 || r >= rows || c < 0 || c >= columns || !map[columns * r + c];
}

const char BG = '4';
const char FG = '3';
const char REGULAR = '0';
const char BLACK = '0';
const char RED = '1';
const char GREEN = '2';
const char WHITE = '7';

const CELL EMPTY_CELL = "\033[38;5;255m\033[48;5;000m";

const int COLOR_LENGTH = 3;
const int COLORS_LENGTH = 22;
const int FG_COLOR_INDEX = 7;
const int BG_COLOR_INDEX = 18;
const int SHAPE_HALF_LENGTH = 3;
const int CHARS_PER_CELL = 2;
const int CELL_LENGTH = COLORS_LENGTH + CHARS_PER_CELL * SHAPE_HALF_LENGTH;

char BLOCK[7] = "██";
char EMPTY[7] = "  \b\b  ";

char AVATAR_BIG[2][7] = {
    "",
    "▜▛",
};

SHAPE AVATAR_BIG_HEAD = AVATAR_BIG[0];
SHAPE AVATAR_BIG_BODY = AVATAR_BIG[1];

// private methods

void set_shape_half(SCREEN screen, int index, SHAPE_HALF ch) {
  for (int i = 0; i < SHAPE_HALF_LENGTH; ++i) {
    screen[index + i] = ch[i];
  }
}

void set_shape(SCREEN screen, int index, SHAPE shape) {
  set_shape_half(screen, index + COLORS_LENGTH, shape);
  set_shape_half(screen, index + COLORS_LENGTH + SHAPE_HALF_LENGTH,
                 shape + SHAPE_HALF_LENGTH);
}

void set_color(SCREEN screen, int index, int color_index, int color) {
  for (int i = 0; i < COLOR_LENGTH; ++i) {
    screen[index + color_index + COLOR_LENGTH - i - 1] =
        (char)('0' + color % 10);
    color /= 10;
  }
}

void set_fg_color(SCREEN screen, int index, int color) {
  set_color(screen, index, FG_COLOR_INDEX, color);
}

void set_bg_color(SCREEN screen, int index, int color) {
  set_color(screen, index, BG_COLOR_INDEX, color);
}

// end private methods
//
char ARROW_DOWN[] = "";
char ARROW_DOWN_RIGHT[] = " ";
char ARROW_RIGHT[] = " ";
char ARROW_UP_RIGHT[] = " ";
char ARROW_UP[] = "";
char ARROW_UP_LEFT[] = " ";
char ARROW_LEFT[] = " ";
char ARROW_DOWN_LEFT[] = " ";
char NO_ARROW[] = "  \b\b  ";
char EMPTY_TARGET[] = "";
char EMPTY_TARGET_LEFT[] = " \b ";
char EMPTY_TARGET_RIGHT[] = " \b ";

SHAPE get_target_shape(int dr, int dc) { return EMPTY_TARGET; }
SHAPE get_target_shape_left(int dr, int dc) { return EMPTY_TARGET_LEFT; }
SHAPE get_target_shape_right(int dr, int dc) { return EMPTY_TARGET_RIGHT; }

void get_map_cell(MAP map, int rows, int columns, int cell_r, int cell_c,
                  int player_r, int player_c, int player_dr, int player_dc,
                  int *fg_color, int *bg_color, SHAPE *shape) {
  int empty = is_empty(map, rows, columns, cell_r, cell_c);
  if (cell_r == player_r - 1 && cell_c == player_c) {
    *fg_color = 179;
    *bg_color = empty ? 22 : 243;
    *shape = AVATAR_BIG_HEAD;
  } else if (cell_r == player_r && cell_c == player_c) {
    *fg_color = 165;
    *bg_color = 22;
    *shape = AVATAR_BIG_BODY;
  } else if (cell_r == player_r + player_dr && cell_c == player_c + player_dc) {
    // Target
    *fg_color = 255;
    *bg_color = empty ? 22 : 243;
    *shape = get_target_shape(player_dr, player_dc);
  } else if (player_dr == -1 && player_dc == 0 &&
             cell_r == player_r + player_dr &&
             cell_c == player_c + player_dc - 1) {
    // Target behind head, left
    *fg_color = 255;
    *bg_color = empty ? 22 : 243;
    *shape = get_target_shape_left(player_dr, player_dc);
  } else if (player_dr == -1 && player_dc == 0 &&
             cell_r == player_r + player_dr &&
             cell_c == player_c + player_dc + 1) {
    // Target behind head, right
    *fg_color = 255;
    *bg_color = empty ? 22 : 243;
    *shape = get_target_shape_right(player_dr, player_dc);
  } else if (empty) {
    *fg_color = 243;
    *bg_color = 22;
    *shape = EMPTY;
  } else {
    *fg_color = 243;
    *bg_color = 22;
    *shape = BLOCK;
  }
}

void set_screen_cell(SCREEN screen, int rows, int columns, int i, int j,
                     int fg_color, int bg_color, SHAPE shape) {
  int row_length = CELL_LENGTH * columns + 1;
  int cell_start = row_length * i + CELL_LENGTH * j;
  set_fg_color(screen, cell_start, fg_color);
  set_bg_color(screen, cell_start, bg_color);
  set_shape(screen, cell_start, shape);
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

void set_map_cell(MAP map, int rows, int columns, int r, int c, int value) {
  if (r < 0 || r >= rows || c < 0 || c >= columns) {
    return;
  }

  map[columns * r + c] = value;
}

int control_player(MAP map, int rows, int columns, int *r, int *c, int *dr,
                   int *dc) {
  char key = readkey();
  int moving = 0;
  if (key == 'h') {
    *dr = 0;
    *dc = -1;
    moving = 1;
  } else if (key == 'j') {
    *dr = 1;
    *dc = 0;
    moving = 1;
  } else if (key == 'k') {
    *dr = -1;
    *dc = 0;
    moving = 1;
  } else if (key == 'l') {
    *dr = 0;
    *dc = 1;
    moving = 1;
  } else if (key == 'x') {
    set_map_cell(map, rows, columns, *r + *dr, *c + *dc, 0);
  } else if (key == 'a') {
    set_map_cell(map, rows, columns, *r + *dr, *c + *dc, 1);
  } else {
    return 0;
  }

  if (moving && is_empty(map, rows, columns, *r + *dr, *c + *dc)) {
    *r += *dr;
    *c += *dc;
  }

  return 1;
}

int resize_window(int *rows, int *columns) {
  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  if (size.ws_row != *rows || size.ws_col / 2 != *columns) {
    *rows = size.ws_row;
    *columns = size.ws_col / 2;
    return 1;
  }
  return 0;
}

int main() {
  system(HIDE_CURSOR_COMMAND);

  int player_r = 2;
  int player_c = 2;
  int player_dr = 0;
  int player_dc = 0;

  int changed = 1;

  int rows = 0;
  int columns = 0;
  int resized = resize_window(&rows, &columns);

  int row_length = CELL_LENGTH * columns + 1;

  SCREEN screen = NULL;

  while (1) {
    if (changed || resized) {
      resize_screen(&screen, rows, columns);

      int center_r = rows / 2;
      int center_c = columns / 2;

      int offset_r = center_r - player_r;
      int offset_c = center_c - player_c;

      render_screen_map(screen, rows, columns, MAIN_MAP, MAIN_MAP_ROWS,
                        MAIN_MAP_COLUMNS, offset_r, offset_c, player_r,
                        player_c, player_dr, player_dc);

      printf("\e[0;0H%s", screen);
    }

    changed = control_player(MAIN_MAP, MAIN_MAP_ROWS, MAIN_MAP_COLUMNS,
                             &player_r, &player_c, &player_dr, &player_dc);

    resized = resize_window(&rows, &columns);
  }

  free(screen);

  return 0;
}

// TODO: have two threads - one to read keys, one to do game loop
