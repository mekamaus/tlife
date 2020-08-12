#include "screen.h"
#include "stdlib.h"
#include "vector.h"

Dim get_screen_index(const Dim2 *size, const Dim2 *pos) {
  return (size->x + 1) * pos->y + pos->x;
}
