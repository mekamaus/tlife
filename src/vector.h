#pragma once

#include "scalar.h"
#include <iostream>
#include <type_traits>

/** Two-dimensional dimension vector (non-negative elements). */
template <typename T> class Vector2 {
public:
  static_assert((std::is_same<Dim, T>::value || std::is_same<Pos, T>::value),
                "Vector2 type parameter must be of Pos or Dim type");
  Vector2() : x(0), y(0) {}
  Vector2(T x, T y) : x(x), y(y) {}
  Vector2(const Vector2<Dim> &dim) : x(dim.x), y(dim.y) {}

  Vector2<T> operator/(T dividend) const;
  Vector2<T> operator-(const Vector2<T> &other) const;

  T x;
  T y;
};

typedef Vector2<Dim> Dim2;
typedef Vector2<Pos> Pos2;

template <typename T>
bool operator==(const Vector2<T> &lhs, const Vector2<T> &rhs);

template <typename T>
bool operator!=(const Vector2<T> &lhs, const Vector2<T> &rhs);

template <typename T>
Vector2<T> operator+(const Vector2<T> &lhs, const Vector2<T> &rhs);

template <typename T>
std::ostream &operator<<(std::ostream &out, const Vector2<T> &rhs);

template <typename T>
std::istream &operator>>(std::istream &in, const Vector2<T> &rhs);
