#include "game.h"
#include "constants.h"
#include "frame.h"

// Prepares game state for loop.
void init_game(const Filename player_file, Pos2 *player_pos, Pos2 *player_delta,
               const Filename map_file, Map map, Dim2 *map_size, Screen *screen,
               const Dim2 *screen_size);

// Loops the game until it is ready to terminate.
void loop_game(const Filename player_file, Pos2 *player_pos, Pos2 *player_delta,
               const Filename map_file, Map map, Dim2 *map_size, Screen *screen,
               Dim2 *screen_size);

// Tears down game resources.
void destroy_game(Screen screen);

void run_game() {
  Pos2 player_pos = START_PLAYER_POS;
  Pos2 player_delta = START_PLAYER_DELTA;

  Dim2 screen_size = {1, 1};
  Screen screen;

  Dim2 map_size = MAP_SIZE;
  Block map[MAP_SIZE.x * MAP_SIZE.y];

  init_game(PLAYER_FILE, &player_pos, &player_delta, MAP_FILE, map, &map_size,
            &screen, &screen_size);

  loop_game(PLAYER_FILE, &player_pos, &player_delta, MAP_FILE, map, &map_size,
            &screen, &screen_size);

  destroy_game(screen);
}

void init_game(const Filename player_file, Pos2 *player_pos, Pos2 *player_delta,
               const Filename map_file, Map map, Dim2 *map_size, Screen *screen,
               const Dim2 *screen_size) {
  hide_cursor();
  read_player(player_file, player_pos, player_delta);
  read_map(map_file, map, map_size);
  start_controls();
  *screen = create_empty_screen(screen_size);
}

void loop_game(const Filename player_file, Pos2 *player_pos, Pos2 *player_delta,
               const Filename map_file, Map map, Dim2 *map_size, Screen *screen,
               Dim2 *screen_size) {
  Pos2 offset;
  bool exit = false;
  while (!exit) {
    if (update_frame(player_file, player_pos, player_delta, map_file, map,
                     map_size, screen, screen_size, &offset, &exit)) {
      display_frame(*screen, screen_size, &offset, map, map_size, player_pos,
                    player_delta);
    }
  }
}

void destroy_game(Screen screen) { destroy_screen(screen); }
