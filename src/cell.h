#pragma once

#include "color.h"
#include "shape.h"
#include "terminal.h"
#include <ostream>
#include <vector>

namespace {

typedef unsigned char byte;

/**
 * Bytes representing ground, e.g. '38' for foreground, '48' for background.
 */
class Ground {
  static byte GetGroundFirstByte(bool foreground) {
    return foreground ? '3' : '4';
  }

public:
  Ground(bool foreground) : ground_{GetGroundFirstByte(foreground), '8'} {}

private:
  byte ground_[2];
};

/** Color encoded as bytes, using digit characters, e.g. '123'. */
class ColorBytes {
public:
  ColorBytes(Color color)
      : bytes_{
            byte('0' + color / 100),
            byte((color / 10) % 10),
            byte(color % 10),
        } {}

  ColorBytes &operator<<(Color color);

private:
  byte bytes_[3];
};

/** Terminal color setting, represented as an escape sequence. */
class ColorSequence {
public:
  ColorSequence(Color color, bool foreground)
      : escape_{'\033', '['}, ground_(foreground), delimiter1_(';'), mode_('5'),
        delimiter2_(';'), color_(color), end_('m') {}
  ColorSequence &operator=(const ColorSequence &) = delete;

  /** Starting escape sequence: '\033[' */
  byte escape_[2];

  /** '38' for foreground; '48' for background. */
  Ground ground_;

  /** Delimiting ';'. */
  byte delimiter1_;

  /** This is '5' for 256 color (useful for our purposes). */
  byte mode_;

  /** Delimiting ';'. */
  byte delimiter2_;

  /** Color encoded as bytes. */
  ColorBytes color_;

  /** Ending character: 'm'. */
  byte end_;

  ColorSequence &operator<<(Color color);
};

} // namespace

/**
 * Screen cell, represented as a sequence of bytes that can be printed to the
 * screen to display a colored shape.
 */
class Cell {
public:
  Cell(Color fg, Color bg, char const shape[7])
      : foreground_(fg, true), background_(bg, false),
        shape_(shape[0], shape[1], shape[2], shape[3], shape[4], shape[5]) {}
  // TODO: may have to un-delete this, since vector.reserve() uses the copy
  // constructor
  Cell &operator=(const Cell &) = delete;

  Cell &operator<<(Color color);
  Cell &operator<<(const Shape &shape);

private:
  /** Foreground color as escape sequence. */
  ColorSequence foreground_;

  /** Background color as escape sequence. */
  ColorSequence background_;

  /** Shape as a byte sequence of visual characters. */
  Shape shape_;
};

Terminal &operator<<(Terminal &out, const std::vector<Cell> &cells);
