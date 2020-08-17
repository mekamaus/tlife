#include "frame.h"
#include "map_io.h"
#include "map_visual.h"
#include "player.h"
#include "player_io.h"
#include "player_visual.h"
#include "terminal.h"
#include "window.h"

bool update_frame(const Filename player_file, Pos2 *player_pos,
                  Pos2 *player_delta, const Filename map_file, Map map,
                  Dim2 *map_size, Screen *screen, Dim2 *screen_size,
                  Pos2 *offset, bool *exit) {
  bool player_moved = false;
  bool map_changed = false;

  Control control = get_control();
  if (control == CONTROL_EXIT) {
    *exit = true;
    return false;
  }

  control_player(map, map_size, player_pos, player_delta, &player_moved,
                 &map_changed, control);

  bool window_resized = get_window_size(screen_size);

  if (player_moved) {
    write_player(player_file, player_pos, player_delta);
  }

  if (map_changed) {
    write_map(map_file, map, map_size);
  }

  if (window_resized) {
    destroy_screen(*screen);
    *screen = create_empty_screen(screen_size);
  }

  offset->x = (Pos)screen_size->x / 2 - player_pos->x;
  offset->y = (Pos)screen_size->y / 2 - player_pos->y;

  return player_moved || map_changed || window_resized;
}

void display_frame(const Screen screen, const Dim2 *screen_size,
                   const Pos2 *offset, const Map map, const Dim2 *map_size,
                   const Pos2 *player_pos, const Pos2 *player_delta) {
  render_map(screen, screen_size, offset, map, map_size);
  render_player(screen, screen_size, offset, player_pos, player_delta);
  draw_screen(screen);
}
