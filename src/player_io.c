#include "player_io.h"
#include <stdio.h>
#include <unistd.h>

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
