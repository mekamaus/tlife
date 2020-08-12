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
#include <time.h>
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
      free(screen);
      screen = malloc(sizeof(Cell) * (screen_size.x + 1) * screen_size.y);

      Dim2 pos;
      for (pos.y = 0; pos.y < screen_size.y; ++pos.y) {
        for (pos.x = 0; pos.x <= screen_size.x; ++pos.x) {
          screen[get_screen_index(&screen_size, &pos)] =
              pos.x < screen_size.x
                  ? EMPTY_CELL
                  : pos.y < screen_size.y - 1 ? NEWLINE_CELL : NULL_CELL;
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
          screen, &screen_size, &offset,
          // map
          map, &map_size);

      render_player(
          // screen
          screen, &screen_size, &offset,
          // player
          &player_pos, &player_delta);

      printf("\e[0;0H%s", (char *)screen);
    }

    bool player_moved = false;
    bool map_changed = false;

    // printf("control player %ld\n", time(NULL));
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
  }

  free(screen);

  return 0;
}
