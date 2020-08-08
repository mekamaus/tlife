#pragma once

#include "cell.h"
#include "vector.h"

typedef Cell *Screen;

Screen create_screen(const Dim2 *size);
