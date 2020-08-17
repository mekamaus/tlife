#include "bool.h"
#include "file.h"
#include "screen.h"
#include "vector.h"

bool update_frame(const Filename player_file, Pos2 *player_pos,
                  Pos2 *player_delta, const Filename map_file, Map map,
                  Dim2 *map_size, Screen *screen, Dim2 *screen_size,
                  Pos2 *offset, bool *exit);

void display_frame(const Screen screen, const Dim2 *screen_size,
                   const Pos2 *offset, const Map map, const Dim2 *map_size,
                   const Pos2 *player_pos, const Pos2 *player_delta);
