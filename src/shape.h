#pragma once

#include "char.h"

typedef struct Shape {
  Char a;
  Char b;
} Shape;

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
