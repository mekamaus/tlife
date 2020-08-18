#include "init.h"
#include "bool.h"
#include "constants.h"
#include "control.h"
#include "map_io.h"
#include "player_io.h"
#include "terminal.h"

void init_game(const Filename player_file, Pos2 *player_pos, Pos2 *player_delta,
               const Filename map_file, Map map, Dim2 *map_size, Screen *screen,
               const Dim2 *screen_size) {
  set_cursor_visibility(false);
  read_player(player_file, player_pos, player_delta);
  read_map(map_file, map, map_size);
  start_controls();
  *screen = create_empty_screen(screen_size);
}
