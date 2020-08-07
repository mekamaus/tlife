#include "cell.h"
#include "map.h"
#include "scalar.h"

// Renders the cell at a location on a map with player properties.
void render_cell(Map map, Dim rows, Dim columns, Dim cell_r, Dim cell_c,
                 Pos player_r, Pos player_c, Pos player_dr, Pos player_dc,
                 Cell *cell);
