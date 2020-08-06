#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "screen.h"

const char HIDE_CURSOR_COMMAND[] = "tput civis";

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

  int player_moved = 1;
  int map_changed = 0;

  int player_r = -1;
  int player_c = 0;
  int player_dr = 1;
  int player_dc = 0;

  FILENAME player_file = "/tmp/player";
  FILENAME map_file = "/tmp/map";

  read_player(player_file, &player_r, &player_c, &player_dr, &player_dc);

  int rows = 0;
  int columns = 0;
  int resized = resize_window(&rows, &columns);

  int row_length = CELL_LENGTH * columns + 1;

  SCREEN screen = NULL;

  const DIM map_rows = 20;
  const DIM map_columns = 20;
  int map[map_rows * map_columns] = {0};

  read_map(map_file, map);

  start_controls();

  while (1) {
    if (player_moved || map_changed || resized) {
      resize_screen(&screen, rows, columns);

      int center_r = rows / 2;
      int center_c = columns / 2;

      int offset_r = center_r - player_r;
      int offset_c = center_c - player_c;

      render_screen_map(
          // screen
          screen, rows, columns,
          // map
          map, map_rows, map_columns,
          // offset
          offset_r, offset_c,
          // player
          player_r, player_c, player_dr, player_dc);

      printf("\e[0;0H%s", screen);
    }

    if (player_moved) {
      write_player(player_file, player_r, player_c, player_dr, player_dc);
    }

    if (map_changed) {
      write_map(map_file, map);
    }

    control_player(
        // map
        map, map_rows, map_columns,
        // player position, direction
        &player_r, &player_c, &player_dr, &player_dc,
        // updated properties
        &player_moved, &map_changed);

    resized = resize_window(&rows, &columns);
  }

  free(screen);

  return 0;
}
