#include "vector_range.h"

template <typename T>
typename Vector2Range<T>::Iterator Vector2Range<T>::Iterator::operator++() {
  Vector2Range<T>::Iterator i = *this;
  i.Increment();
  return i;
}

template <typename T>
typename Vector2Range<T>::Iterator
Vector2Range<T>::Iterator::operator++(int dummy) {
  Increment();
  return *this;
}

template <typename T> const Vector2<T> &Vector2Range<T>::Iterator::operator*() {
  return pos_;
}

template <typename T>
const Vector2<T> *Vector2Range<T>::Iterator::operator->() {
  return &pos_;
}

template <typename T>
bool Vector2Range<T>::Iterator::operator==(
    const Vector2Range<T>::Iterator &other) {
  return start_ == other.start_ && end_ == other.end_ && pos_ == other.pos_;
}

template <typename T> void Vector2Range<T>::Iterator::Increment() {
  ++pos_.x;
  if (pos_.x == end_->x) {
    pos_.x = start_->x;
    ++pos_.y;
  }
}

template <typename T>
bool Vector2Range<T>::Iterator::operator!=(
    const Vector2Range<T>::Iterator &other) {
  return start_ != other.start || end_ != other.end_ || pos_ != other.pos_;
}

template <typename T>
typename Vector2Range<T>::Iterator Vector2Range<T>::begin() const {
  return Vector2Range<T>::Iterator(start_, start_, end_);
}

template <typename T>
typename Vector2Range<T>::Iterator Vector2Range<T>::end() const {
  return Vector2Range<T>::Iterator({start_->x, end_->y}, start_, end_);
}

template <typename T> const Vector2Range<T> &range(const Vector2<T> &end) {
  return Vector2Range<T>(Vector2<T>(0, 0), end);
}

template <typename T>
const Vector2Range<T> &range(const Vector2<T> &start, const Vector2<T> &end) {
  return Vector2Range<T>(start, end);
}
