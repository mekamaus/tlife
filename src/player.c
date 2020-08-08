#include "player.h"
#include "unistd.h"
#include "vector.h"

void read_player(const Filename filename, Pos2 *pos, Pos2 *delta) {
  if (access(filename, F_OK) == -1) {
    return;
  }

  FILE *f = fopen(filename, "rb+");
  fread(pos, sizeof(Pos2), 1, f);
  fread(delta, sizeof(Pos2), 1, f);
  fclose(f);
}

void write_player(const Filename filename, const Pos2 *pos, const Pos2 *delta) {
  FILE *f = fopen(filename, "wb+");
  fwrite(pos, sizeof(Pos2), 1, f);
  fwrite(delta, sizeof(Pos2), 1, f);
  fclose(f);
}

void control_player(Map map, const Dim2 *size, Pos2 *pos, Pos2 *delta,
                    bool *player_moved, bool *map_changed) {
  Pos2 target = {
      pos->x + delta->x,
      pos->y + delta->y,
  };
  char key = readkey();
  int rotate_only = 0;
  *player_moved = 0;
  *map_changed = 0;
  if (key == 'h') {
    if (delta->x != -1 || delta->y != 0) {
      delta->x = -1;
      delta->y = 0;
      rotate_only = 1;
    }
    *player_moved = 1;
  } else if (key == 'j') {
    if (delta->x != 0 || delta->y != 1) {
      delta->x = 0;
      delta->y = 1;
      rotate_only = 1;
    }
    *player_moved = 1;
  } else if (key == 'k') {
    if (delta->x != 0 || delta->y != -1) {
      delta->x = 0;
      delta->y = -1;
      rotate_only = 1;
    }
    *player_moved = 1;
  } else if (key == 'l') {
    if (delta->x != 1 || delta->y != 0) {
      delta->x = 1;
      delta->y = 0;
      rotate_only = 1;
    }
    *player_moved = 1;
  } else if (key == 'x') {
    set_map_block(map, size, &target, 0);
    *map_changed = 1;
  } else if (key == 'a') {
    set_map_block(map, size, &target, 1);
    *map_changed = 1;
  } else {
    return;
  }

  if (*player_moved && !rotate_only && is_map_block_empty(map, size, &target)) {
    pos->x += delta->x;
    pos->y += delta->y;
  }
}
