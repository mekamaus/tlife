#include "game.h"
#include "constants.h"
#include "destroy.h"
#include "init.h"
#include "loop.h"
#include "map.h"

void run_game() {
  Pos2 player_pos = START_PLAYER_POS;
  Pos2 player_delta = START_PLAYER_DELTA;

  Dim2 screen_size = {1, 1};
  Screen screen;

  Dim2 map_size = MAP_SIZE;
  Block map[MAP_SIZE.x * MAP_SIZE.y];
  Dim2 pos;
  for (pos.y = 0; pos.y < MAP_SIZE.y; ++pos.y) {
    for (pos.x = 0; pos.x < MAP_SIZE.x; ++pos.x) {
      set_map_block(map, &MAP_SIZE, &pos, 0);
    }
  }

  init_game(PLAYER_FILE, &player_pos, &player_delta, MAP_FILE, map, &map_size,
            &screen, &screen_size);

  loop_game(PLAYER_FILE, &player_pos, &player_delta, MAP_FILE, map, &map_size,
            &screen, &screen_size);

  destroy_game(screen);
}
