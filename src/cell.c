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

void set_data_color(unsigned char *data, Color color) {
  data[0] = '0' + color / 100;
  data[1] = '0' + (color / 10) % 10;
  data[2] = '0' + color % 10;
}

Color get_data_color(const unsigned char *data) {
  return (data[0] - '0') * 100 + (data[1] - '0') * 10 + (data[2] - '0');
}

void set_color(EscapedColor *escaped_color, Color color) {
  set_data_color(escaped_color->data + COLOR_INDEX, color);
}

Color get_color(const EscapedColor *escaped_color) {
  return get_data_color(escaped_color->data + COLOR_INDEX);
}

void set_fg_color(Cell *cell, Color color) {
  set_color(&cell->foreground, color);
}

void set_bg_color(Cell *cell, Color color) {
  set_color(&cell->background, color);
}

Color get_fg_color(const Cell *cell) { return get_color(&cell->foreground); }

Color get_bg_color(const Cell *cell) { return get_color(&cell->background); }
