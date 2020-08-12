#pragma once

#include "cell.h"
#include "vector.h"

typedef Cell *Screen;

Dim get_screen_index(const Dim2 *size, const Dim2 *pos);
