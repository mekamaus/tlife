#include "map.h"

int is_map_cell_empty(Map map, Dim rows, Dim columns, Dim r, Dim c) {
  return r < 0 || r >= rows || c < 0 || c >= columns || !map[columns * r + c];
}

int is_inside_map(Dim rows, Dim columns, Pos r, Pos c) {
  return r >= 0 && r < rows && c >= 0 && c < columns;
}

Block get_map_block(Map map, Dim rows, Dim columns, Dim r, Dim c) {
  if (r < 0 || r >= rows || c < 0 || c >= columns) {
    return BLOCK_EMPTY;
  }

  return map[columns * r + c];
}

void set_map_block(Map map, Dim rows, Dim columns, Dim r, Dim c, Block value) {
  if (r < 0 || r >= rows || c < 0 || c >= columns) {
    return;
  }

  map[columns * r + c] = value;
}
