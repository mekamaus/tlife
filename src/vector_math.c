#include "vector_math.h"

#define CHANGE_XY(set_var, target_var)                                         \
  if (set_var->x != target_var->x || set_var->y != target_var->y) {            \
    *set_var = *target_var;                                                    \
    return true;                                                               \
  }                                                                            \
  return false;

#define ADJUST_XY(set_var, delta_var)                                          \
  set_var->x += delta_var->x;                                                  \
  set_var->y += delta_var->y;

bool change_pos(Pos2 *pos, const Pos2 *target) { CHANGE_XY(pos, target); }

bool change_dim(Dim2 *dim, const Dim2 *target) { CHANGE_XY(dim, target); }

void adjust_pos(Pos2 *pos, const Pos2 *delta) { ADJUST_XY(pos, delta); }
