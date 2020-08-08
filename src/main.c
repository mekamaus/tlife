#include "block.h"
#include "controls.h"
#include "map_io.h"
#include "map_renderer.h"
#include "player.h"
#include "player_renderer.h"
#include "scalar.h"
#include "screen.h"
#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

const char HIDE_CURSOR_COMMAND[] = "tput civis";

// Gets the window size in screen cells; returns true if window size changed,
// false otherwise.
bool get_window_size(Dim2 *size) {
  struct winsize ws;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
  if (ws.ws_col / 2 != size->x || ws.ws_row != size->y) {
    size->x = ws.ws_col / 2;
    size->y = ws.ws_row;
    return true;
  }
  return false;
}

int main() {
  system(HIDE_CURSOR_COMMAND);

  bool redraw = false;

  const Filename player_file = "/tmp/player";
  const Filename map_file = "/tmp/map";

  Pos2 player_pos = {0, -1};
  Pos2 player_delta = {0, 1};

  read_player(player_file, &player_pos, &player_delta);

  Dim2 screen_size = {0, 0};
  Screen screen = malloc(sizeof(Cell));
  screen[0] = NULL_CELL;

  Dim2 map_size = {20, 20};
  Block map[400] = {0};

  read_map(map_file, map, &map_size);

  start_controls();

  while (true) {
    if (get_window_size(&screen_size)) {
      // printf("resizing window to %d %d\n", screen_size.x, screen_size.y);
      free(screen);
      screen = malloc(sizeof(Cell) * (screen_size.x + 1) * screen_size.y);

      for (int y = 0; y < screen_size.y; ++y) {
        for (int x = 0; x <= screen_size.x; ++x) {
          screen[(screen_size.x + 1) * y + x] =
              x < screen_size.x
                  ? EMPTY_CELL
                  : y < screen_size.y - 1 ? NEWLINE_CELL : NULL_CELL;
        }
      }

      redraw = true;
    }
    if (redraw) {
      redraw = false;

      Pos2 offset = {
          screen_size.x / 2 - player_pos.x,
          screen_size.y / 2 - player_pos.y,
      };

      render_map(
          // screen
          screen, &screen_size,
          // map
          map, &map_size,
          // offset
          &offset);

      // render_player(
      //    // screen
      //    screen, &screen_size,
      //    // player
      //    &player_pos, &player_delta,
      //    // offset
      //    &offset);

      printf("\e[0;0H%s", (char *)screen);
      // printf("asdf\n");
      // printf("%d %d\n", player_pos.x, player_pos.y);
      // printf("1: %c\n", screen[0].background.data[1]);
      // printf("2: %c\n", screen[0].background.data[2]);
      // printf("3: %c\n", screen[0].background.data[3]);
      // printf("4: %c\n", screen[0].background.data[4]);
    }

    bool player_moved = false;
    bool map_changed = false;
    control_player(
        // map
        map, &map_size,
        // player position, delta
        &player_pos, &player_delta,
        // updated properties
        &player_moved, &map_changed);

    if (player_moved) {
      write_player(player_file, &player_pos, &player_delta);
    }

    if (map_changed) {
      write_map(map_file, map, &map_size);
    }

    redraw = redraw || player_moved || map_changed;

    // resized = resize_window(&rows, &columns);
  }

  free(screen);

  return 0;
}
