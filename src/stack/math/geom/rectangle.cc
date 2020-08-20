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

#include "rectangle.h"

namespace stack {
namespace math {
namespace geom {
REGISTER_GEOMETRY_DATA_TYPE(Rectangle)

template <typename T, size_t N>
Rectangle<T, N>::Rectangle(Point<T, N> origin, Size<T, N> size)
    : _origin(std::move(origin)), _size(std::move(size)) {}

template <typename T, size_t N>
Rectangle<T, N> &Rectangle<T, N>::operator=(const Rectangle<T, N> &rect) {
    _origin = rect._origin;
    _size = rect._size;
    return *this;
}

template <typename T, size_t N> Point<T, N> Rectangle<T, N>::origin() {
    return _origin;
}

template <typename T, size_t N> Size<T, N> Rectangle<T, N>::size() {
    return _size;
}

template <typename T, size_t N>
bool Rectangle<T, N>::contains(Point<T, N> point) {
    bool contained = true;
    for (size_t i = 0; i < N; ++i) {
        contained = _origin[i] <= point[i] && point[i] <= _origin[i] + _size[i];
        if (!contained) {
            break;
        }
    }
    return contained;
}

template <typename T, size_t N> T Rectangle<T, N>::area() {
    T area = 1;
    for (size_t i = 0; i < N; ++i) {
        area = area * _size[i];
    }
    return area;
}

} // namespace geom
} // namespace math
} // namespace stack