#include "vector.h"

template <typename T> Vector2<T> Vector2<T>::operator/(T dividend) const {
  return Vector2<T>(x / dividend, y / dividend);
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T> &other) const {
  return Vector2<T>(x - other.x, y - other.y);
}

template <typename T>
bool operator==(const Vector2<T> &lhs, const Vector2<T> &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

template <typename T>
bool operator!=(const Vector2<T> &lhs, const Vector2<T> &rhs) {
  return lhs.x != rhs.x || lhs.y != rhs.y;
}

template <typename T>
Vector2<T> operator+(const Vector2<T> &lhs, const Vector2<T> &rhs) {
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Vector2<T> &rhs) {
  out.write((char *)&rhs, sizeof(Vector2<T>));
}

template <typename T>
std::istream &operator>>(std::istream &in, const Vector2<T> &rhs) {
  in.read((char *)&rhs, sizeof(Vector2<T>));
}
