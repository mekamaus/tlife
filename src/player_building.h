#include "bool.h"
#include "control.h"
#include "map.h"

// Alters the map at the target based on the control.
bool build_map(Map map, const Dim2 *size, const Pos2 *pos, const Pos2 *delta,
               Control control);
