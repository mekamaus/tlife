#include "cell.h"

const unsigned char COLOR_INDEX = 7;

const Cell EMPTY_CELL = {
    {{'\033', '[', '3', '8', ';', '5', ';', '2', '5', '5', 'm'}},
    {{'\033', '[', '4', '8', ';', '5', ';', '0', '0', '0', 'm'}},
    {{{' ', '\b', ' '}}, {{' ', '\b', ' '}}},
};

const Cell NEWLINE_CELL = {
    {{'\033', '[', '3', '8', ';', '5', ';', '2', '5', '5', 'm'}},
    {{'\033', '[', '4', '8', ';', '5', ';', '0', '0', '0', 'm'}},
    {{{'\r', '\r', '\r'}}, {{'\r', '\r', '\n'}}},
};

const Cell NULL_CELL = {
    {{'\033', '[', '3', '8', ';', '5', ';', '2', '5', '5', 'm'}},
    {{'\033', '[', '4', '8', ';', '5', ';', '0', '0', '0', 'm'}},
    {{{'\r', '\r', '\r'}}, {{'\r', '\r', '\0'}}},
};

void set_color(EscapedColor *escaped_color, Color color) {
  unsigned char color_string[3] = {};
  color_string[0] = '0' + color / 100;
  color_string[1] = '0' + (color / 10) % 10;
  color_string[2] = '0' + color % 10;

  memcpy(escaped_color->data + COLOR_INDEX, color_string, 3);
}

void set_fg_color(Cell *cell, Color color) {
  set_color(&cell->foreground, color);
}

void set_bg_color(Cell *cell, Color color) {
  set_color(&cell->background, color);
}
