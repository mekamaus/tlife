#pragma once

#include "vector.h"
#include <iterator>

template <typename T> class Vector2Range {
public:
  Vector2Range(const Vector2<T> &start, const Vector2<T> &end)
      : start_(&start), end_(&end) {}

  class Iterator {
  public:
    Iterator(const Vector2<T> &pos, const Vector2<T> &start,
             const Vector2<T> &end)
        : pos_(pos), start_(&start), end_(&end) {}
    Iterator(const Iterator &other)
        : pos_(other.pos.x, other.pos.y), start_(other.start_),
          end_(other.end_) {}
    Iterator operator++();
    Iterator operator++(int dummy);
    const Vector2<T> &operator*();
    const Vector2<T> *operator->();
    bool operator==(const Iterator &other);
    bool operator!=(const Iterator &other);

  private:
    void Increment();

    const Vector2<T> *start_;
    const Vector2<T> *end_;
    Vector2<T> pos_;
  };

  Iterator begin() const;
  Iterator end() const;

private:
  const Vector2<T> *start_;
  const Vector2<T> *end_;
};

template <typename T> const Vector2Range<T> &range(const Vector2<T> &end);

template <typename T>
const Vector2Range<T> &range(const Vector2<T> &start, const Vector2<T> &end);
