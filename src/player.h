#include "controls.h"
#include "map.h"

void read_player(FILENAME filename, int *r, int *c, int *dr, int *dc) {
  if (access(filename, F_OK) == -1) {
    return;
  }

  FILE *f = fopen(filename, "rb+");
  fread(r, sizeof(int), 1, f);
  fread(c, sizeof(int), 1, f);
  fread(dr, sizeof(int), 1, f);
  fread(dc, sizeof(int), 1, f);
  fclose(f);
}

void write_player(FILENAME filename, int r, int c, int dr, int dc) {
  FILE *f = fopen(filename, "wb+");
  fwrite(&r, sizeof(int), 1, f);
  fwrite(&c, sizeof(int), 1, f);
  fwrite(&dr, sizeof(int), 1, f);
  fwrite(&dc, sizeof(int), 1, f);
  fclose(f);
}

void control_player(MAP map, int rows, int columns, int *r, int *c, int *dr,
                    int *dc, int *player_moved, int *map_changed) {
  char key = readkey();
  int rotate_only = 0;
  *player_moved = 0;
  *map_changed = 0;
  if (key == 'h') {
    if (*dr != 0 || *dc != -1) {
      *dr = 0;
      *dc = -1;
      rotate_only = 1;
    }
    *player_moved = 1;
  } else if (key == 'j') {
    if (*dr != 1 || *dc != 0) {
      *dr = 1;
      *dc = 0;
      rotate_only = 1;
    }
    *player_moved = 1;
  } else if (key == 'k') {
    if (*dr != -1 || *dc != 0) {
      *dr = -1;
      *dc = 0;
      rotate_only = 1;
    }
    *player_moved = 1;
  } else if (key == 'l') {
    if (*dr != 0 || *dc != 1) {
      *dr = 0;
      *dc = 1;
      rotate_only = 1;
    }
    *player_moved = 1;
  } else if (key == 'x') {
    set_map_cell(map, rows, columns, *r + *dr, *c + *dc, 0);
    *map_changed = 1;
  } else if (key == 'a') {
    set_map_cell(map, rows, columns, *r + *dr, *c + *dc, 1);
    *map_changed = 1;
  } else {
    return;
  }

  if (*player_moved && !rotate_only &&
      is_map_cell_empty(map, rows, columns, *r + *dr, *c + *dc)) {
    *r += *dr;
    *c += *dc;
  }
}
