// Copyright (c) 2020 InsightStack Project contributors
// Licensed under the MIT License:
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "point.h"
#include <cassert>
#include <cstdlib>
#include <cstring>

namespace stack {
namespace math {
namespace geom {
REGISTER_GEOMETRY_DATA_TYPE(Point)

template <typename T, size_t N> Point<T, N>::Point() : _dimension(N) {
    _coordinates = std::make_unique<T[]>(N);
}

template <typename T, size_t N> Point<T, N>::Point(const Point<T, N> &point) {
    _dimension = point._dimension;
    _coordinates = std::make_unique<T[]>(N);
    std::memcpy((void *)_coordinates.get(), (void *)point._coordinates.get(),
                sizeof(T) * _dimension);
}

template <typename T, size_t N>
Point<T, N>::Point(std::initializer_list<T> coords) {
    assert(coords.size() == N);
    _dimension = coords.size();
    _coordinates = std::make_unique<T[]>(N);
    std::memcpy((void *)_coordinates.get(), (void *)coords.begin(),
                sizeof(T) * _dimension);
}

template <typename T, size_t N> Point<T, N>::~Point() {}

template <typename T, size_t N> T &Point<T, N>::operator[](size_t index) {
    assert(index < _dimension);
    return _coordinates[index];
}

template <typename T, size_t N>
const T &Point<T, N>::operator[](size_t index) const {
    assert(index < _dimension);
    return _coordinates[index];
}

template <typename T, size_t N> size_t Point<T, N>::dimension() {
    return _dimension;
}

template <typename T, size_t N>
bool Point<T, N>::operator==(const Point<T, N> &point) {
    bool equals = true;
    for (size_t i = 0; i < N; ++i) {
        equals = point[i] == _coordinates[i];
        if (!equals) {
            break;
        }
    }
    return equals;
}

template <typename T, size_t N>
Point<T, N> &Point<T, N>::operator=(const Point<T, N> &point) {
    assert(_dimension == point._dimension);
    std::memcpy((void *)_coordinates.get(), (void *)point._coordinates.get(),
                sizeof(T) * _dimension);
    return *this;
}

template <typename T, size_t N>
Point<T, N> &Point<T, N>::operator=(std::initializer_list<T> &coords) {
    assert(coords.size() == N);
    _dimension = coords.size();
    std::memcpy((void *)_coordinates.get(), (void *)coords.begin(),
                sizeof(T) * _dimension);
    return *this;
}

template <typename T, size_t N>
Point<T, N> Point<T, N>::operator+(const Point<T, N> &b) {
    Point<T, N> point;
    for (size_t i = 0; i < N; ++i) {
        point[i] = _coordinates[i] + b[i];
    }
    return point;
}

template <typename T, size_t N>
Point<T, N> Point<T, N>::operator-(const Point<T, N> &b) {
    Point<T, N> point;
    for (size_t i = 0; i < N; ++i) {
        point[i] = _coordinates[i] - b[i];
    }
    return point;
}

template <typename T, size_t N>
Point<T, N> Point<T, N>::operator*(const T &value) {
    Point<T, N> point;
    for (size_t i = 0; i < N; ++i) {
        point[i] = _coordinates[i] * value;
    }
    return point;
}

template <typename T, size_t N>
Point<T, N> Point<T, N>::operator/(const T &value) {
    Point<T, N> point;
    for (size_t i = 0; i < N; ++i) {
        point[i] = _coordinates[i] / value;
    }
    return point;
}

template <typename T, size_t N> T Point<T, N>::x() { return _coordinates[0]; }

template <typename T, size_t N> T Point<T, N>::y() { return _coordinates[1]; }

template <typename T, size_t N> T Point<T, N>::z() { return _coordinates[2]; }
} // namespace geom
} // namespace math
} // namespace stack