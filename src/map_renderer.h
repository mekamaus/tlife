#pragma once

#include "map.h"
#include "screen.h"
#include "vector.h"

// Renders a map onto a screen.
// TODO: make this only for the map, and make the player renderer separate.
void render_map(
    // Screen
    Screen screen, const Dim2 *screen_size,
    // Map
    const Map map, const Dim2 *map_size,
    // Offset
    const Pos2 *offset);
