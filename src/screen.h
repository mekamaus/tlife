#pragma once

#include <stdlib.h>
#include <string.h>

#include "cell.h"
#include "cell_renderer.h"
#include "player.h"

typedef Cell *Screen;

extern const int COLOR_LENGTH;
extern const int COLORS_LENGTH;

Screen create_screen(int rows, int columns);

void resize_screen(Screen *screen, int rows, int columns);
