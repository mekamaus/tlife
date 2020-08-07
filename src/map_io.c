#include "map_io.h"

void read_map(Filename filename, Map map, Dim rows, Dim columns) {
  if (access(filename, F_OK) == -1) {
    return;
  }

  FILE *f = fopen(filename, "rb+");
  fread(map, sizeof(Block), 2 * rows * columns, f);
  fclose(f);
}

void write_map(Filename filename, Map map, Dim rows, Dim columns) {
  FILE *f = fopen(filename, "wb+");
  fwrite(map, sizeof(Block), 2 * rows * columns, f);
  fclose(f);
}
