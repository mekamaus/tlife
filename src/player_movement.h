#include "control.h"
#include "map.h"
#include "vector.h"

// Moves a player on the map based on the control.
void move_player(const Map map, const Dim2 *map_size, Pos2 *pos, Pos2 *delta,
                 Control control);
