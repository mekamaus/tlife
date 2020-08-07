#pragma once

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

// 
extern const Shape PLAYER_HEAD;

// ▜▛
extern const Shape PLAYER_BODY_FRONT;

// ▜▛
extern const Shape PLAYER_BODY_BACK;

// ▜▍
extern const Shape PLAYER_BODY_LEFT;

// ▐▛
extern const Shape PLAYER_BODY_RIGHT;

// 
extern const Shape EMPTY_TARGET;

// " "
extern const Shape EMPTY_TARGET_LEFT;

// " "
extern const Shape EMPTY_TARGET_RIGHT;

// ██
extern const Shape BLOCK;

// "  "
extern const Shape EMPTY;

// Gets the shape of the player's action target.
extern const Shape *get_target_shape(int dr, int dc);

// Gets the left side of the shape of the player's action target, when split.
extern const Shape *get_target_shape_left(int dr, int dc);

// Gets the right side of the shape of the player's action target, when split.
extern const Shape *get_target_shape_right(int dr, int dc);
