#include "screen.h"
#include "stdlib.h"
#include "vector.h"

Dim get_screen_index(const Dim2 *size, const Dim2 *pos);

Cell *get_screen_cell(const Screen screen, const Dim2 *size, const Dim2 *pos) {
  return &screen[get_screen_index(size, pos)];
}

Screen create_empty_screen(const Dim2 *size) {
  Screen screen = (Screen)malloc(sizeof(Cell) * (size->x + 1) * size->y);

  Dim2 pos;
  for (pos.y = 0; pos.y < size->y; ++pos.y) {
    for (pos.x = 0; pos.x <= size->x; ++pos.x) {
      screen[get_screen_index(size, &pos)] =
          pos.x < size->x ? EMPTY_CELL
                          : pos.y < size->y - 1 ? NEWLINE_CELL : NULL_CELL;
    }
  }

  return screen;
}

void destroy_screen(Screen screen) { free(screen); }

Dim get_screen_index(const Dim2 *size, const Dim2 *pos) {
  return (size->x + 1) * pos->y + pos->x;
}

Dim get_screen_bytes(const Dim2 *size) {
  return (size->x + 1) * sizeof(Cell) * size->y;
}
