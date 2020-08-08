#include "map.h"
#include "vector.h"

const Block OUTSIDE_BLOCK = 1;

bool is_inside_map(const Dim2 *size, const Pos2 *pos);

bool is_map_block_empty(Map map, const Dim2 *size, const Pos2 *pos) {
  return !is_inside_map(size, pos) || !map[size->x * pos->y + pos->x];
}

Block get_map_block(Map map, const Dim2 *size, const Pos2 *pos) {
  return is_inside_map(size, pos) ? map[size->x * pos->y + pos->x]
                                  : OUTSIDE_BLOCK;
}

void set_map_block(Map map, const Dim2 *size, const Pos2 *pos, Block value) {
  if (is_inside_map(size, pos)) {
    map[size->x * pos->y + pos->x] = value;
  }
}

bool is_inside_map(const Dim2 *size, const Pos2 *pos) {
  return pos->x >= 0 && pos->x < size->x && pos->y >= 0 && pos->y < size->y;
}
