#include "bool.h"
#include "map.h"

/**
 * Returns whether the target is contained within the map contained by the
 * bounds 0, 0, map_size.x, map_size.y.
 */
bool map_contains_target(const Dim2 *map_size, const Pos2 *pos,
                         const Pos2 *delta);

/** Gets the block at the target. */
Block get_target_block(const Map map, const Dim2 *size, const Pos2 *pos,
                       const Pos2 *delta);

/** Sets the block at the target. */
void set_target_block(Map map, const Dim2 *size, const Pos2 *pos,
                      const Pos2 *delta, Block block);
