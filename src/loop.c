#include "loop.h"
#include "bool.h"
#include "frame.h"
#include <unistd.h>

void loop_game(const Filename player_file, Pos2 *player_pos, Pos2 *player_delta,
               const Filename map_file, Map map, Dim2 *map_size, Screen *screen,
               Dim2 *screen_size) {
  Pos2 offset;
  bool should_exit = false;
  bool stride = false;

  while (!should_exit) {
    if (update_frame(player_file, player_pos, player_delta, map_file, map,
                     map_size, screen, screen_size, &offset, &stride,
                     &should_exit)) {
      display_frame(*screen, screen_size, &offset, map, map_size, player_pos,
                    player_delta);
    }
    usleep(50000);
  }
}
