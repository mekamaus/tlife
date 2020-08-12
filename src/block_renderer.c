#include "block_renderer.h"
#include "color.h"

void render_block(Cell *cell, Block block) {
  set_fg_color(cell, LIGHT_GRAY);
  set_bg_color(cell, DARK_GREEN);
  cell->shape = block ? BLOCK : EMPTY;
}
