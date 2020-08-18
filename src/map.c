#include "map.h"

// Gets the index of the block in the map at a position.
Dim get_map_index(const Dim2 *size, const Dim2 *pos);

Block get_map_block(const Map map, const Dim2 *size, const Dim2 *pos) {
  return map[get_map_index(size, pos)];
}

void set_map_block(Map map, const Dim2 *size, const Dim2 *pos, Block value) {
  map[get_map_index(size, pos)] = value;
}

// Gets the index of the block in the map at a position.
Dim get_map_index(const Dim2 *size, const Dim2 *pos) {
  return size->x * pos->y + pos->x;
}
