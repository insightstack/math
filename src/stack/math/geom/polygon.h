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

#ifndef STACK_MATH_GEOM_POLYGON_H
#define STACK_MATH_GEOM_POLYGON_H

#include "point.h"
#include "rectangle.h"
#include <initializer_list>
#include <vector>

namespace stack {
namespace math {
namespace geom {

template <typename T, size_t N> class Polygon {

    size_t _dimension;

    std::vector<Point<T, N>> _vertices;

public:
    Polygon();

    Polygon(std::initializer_list<Point<T, N>>);

    ~Polygon() = default;

    void add_points(std::vector<Point<T, N>>);

    Point<T, N> &operator[](size_t index);

    const Point<T, N> &operator[](size_t index) const;

    std::vector<Point<T, N>> vertices();

    bool contains(Point<T, N>);

    /**
     * Get bounding box
     * @return
     */
    Rectangle<T, N> bounding_box();
};

template <typename T> using Polygon2D = Polygon<T, 2>;

template <typename T> using Polygon3D = Polygon<T, 3>;
} // namespace geom
} // namespace math
} // namespace stack

#endif // STACK_MATH_GEOM_POLYGON_H
