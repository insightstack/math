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

#include "polygon.h"
#include <cassert>

namespace stack {
namespace math {
namespace geom {
REGISTER_GEOMETRY_DATA_TYPE(Polygon)

template <typename T, size_t N> Polygon<T, N>::Polygon() {
    _vertices.resize(N);
}

template <typename T, size_t N>
Polygon<T, N>::Polygon(std::initializer_list<Point<T, N>> vertices) {
    _vertices.insert(_vertices.end(), vertices.begin(), vertices.end());
}

template <typename T, size_t N>
void Polygon<T, N>::add_points(std::vector<Point<T, N>> vertices) {
    _vertices.insert(_vertices.end(), vertices.begin(), vertices.end());
}

template <typename T, size_t N>
Point<T, N> &Polygon<T, N>::operator[](size_t index) {
    assert(index < _vertices.size());
    return _vertices[index];
}

template <typename T, size_t N>
const Point<T, N> &Polygon<T, N>::operator[](size_t index) const {
    assert(index < _vertices.size());
    return _vertices[index];
}

template <typename T, size_t N>
std::vector<Point<T, N>> Polygon<T, N>::vertices() {
    return _vertices;
}

template <typename T, size_t N> bool Polygon<T, N>::contains(Point<T, N>) {
    return false;
}

template <typename T, size_t N> Rectangle<T, N> Polygon<T, N>::bounding_box() {
    Point<T, N> min = _vertices[0];
    Point<T, N> max = _vertices[0];
    for (Point<T, N> point : _vertices) {
        for (size_t i = 0; i < N; ++i) {
            min[i] = std::min(min[i], point[i]);
            max[i] = std::max(max[i], point[i]);
        }
    }

    return {min, max - min};
}
} // namespace geom
} // namespace math
} // namespace stack