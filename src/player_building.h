#include "bool.h"
#include "map.h"

/**
 * Alters the map at the target block. Returns whether the block changed as a
 * result.
 */
bool build_map(Map map, const Dim2 *size, const Pos2 *pos, const Pos2 *delta,
               Block block);
