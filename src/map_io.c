#include "map_io.h"

void read_map(Filename filename, Map map, const Dim2 *size) {
  if (access(filename, F_OK) == -1) {
    return;
  }

  FILE *f = fopen(filename, "rb+");
  fread(map, sizeof(Block), 2 * size->x * size->y, f);
  fclose(f);
}

void write_map(Filename filename, Map map, const Dim2 *size) {
  FILE *f = fopen(filename, "wb+");
  fwrite(map, sizeof(Block), 2 * size->x * size->y, f);
  fclose(f);
}
