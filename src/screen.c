#include "screen.h"
#include "stdlib.h"
#include "vector.h"

Screen create_screen(const Dim2 *size) {
  Screen screen = (Cell *)malloc(sizeof(Cell) * (size->x + 1) * size->y);

  Dim2 pos = {0, 0};
  for (; pos.y < size->y; ++pos.y) {
    for (; pos.x <= size->x; ++pos.x) {
      screen[(size->x + 1) * pos.y + pos.x] =
          pos.x < size->x ? EMPTY_CELL
                          : pos.y < size->y - 1 ? NEWLINE_CELL : NULL_CELL;
    }
  }

  return screen;
}
