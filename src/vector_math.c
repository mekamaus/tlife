#include "vector_math.h"

bool change_pos(Pos2 *pos, const Pos2 *target) {
  if (pos->x != target->x || pos->y != target->y) {
    *pos = *target;
    return true;
  }
  return false;
}

void adjust_pos(Pos2 *pos, const Pos2 *delta) {
  pos->x += delta->x;
  pos->y += delta->y;
}
