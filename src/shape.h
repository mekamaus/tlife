#pragma once

class Shape {
public:
  Shape(unsigned char a, unsigned char b, unsigned char c, unsigned char d,
        unsigned char e, unsigned char f)
      : chars_{a, b, c, d, e, f} {}

  operator const unsigned char *() const { return chars_; }

private:
  unsigned char chars_[6];
};

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
