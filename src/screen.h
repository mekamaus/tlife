#pragma once

#include "cell.h"
#include "vector.h"

typedef Cell *Screen;

Cell *get_screen_cell(const Screen screen, const Dim2 *size, const Dim2 *pos);

Screen create_empty_screen(const Dim2 *size);

void destroy_screen(Screen screen);

/** Gets the number of bytes in a screen with the given size. */
Dim get_screen_bytes(const Dim2 *size);
