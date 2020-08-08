#pragma once

#include "color.h"
#include "map.h"
#include "shape.h"
#include <string.h>

extern const unsigned char COLOR_INDEX;

typedef struct EscapedColor {
  unsigned char data[11];
} EscapedColor;

typedef struct Cell {
  EscapedColor foreground;
  EscapedColor background;
  Shape shape;
} Cell;

extern const Cell EMPTY_CELL;
extern const Cell NEWLINE_CELL;
extern const Cell NULL_CELL;

void set_fg_color(Cell *cell, Color color);

void set_bg_color(Cell *cell, Color color);
