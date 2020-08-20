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

#ifndef STACK_MATH_GEOM_POINT_H
#define STACK_MATH_GEOM_POINT_H

#define REGISTER_GEOMETRY_DIMENSION(__CLASS__, __TYPE__)                       \
    template class __CLASS__<__TYPE__, 2>;                                     \
    template class __CLASS__<__TYPE__, 3>;

#define REGISTER_GEOMETRY_DATA_TYPE(__CLASS__)                                 \
    REGISTER_GEOMETRY_DIMENSION(__CLASS__, int)                                \
    REGISTER_GEOMETRY_DIMENSION(__CLASS__, float)                              \
    REGISTER_GEOMETRY_DIMENSION(__CLASS__, double)

#include <initializer_list>
#include <memory>
#include <vector>

namespace stack {
namespace math {
namespace geom {

template <typename T, size_t N> class Point {
    /**
     * Point dimension
     */
    size_t _dimension;

    std::unique_ptr<T[]> _coordinates;

public:
    /**
     * Create an empty point of specified dimension
     * @param dim
     */
    Point();

    Point(const Point<T, N> &);

    /**
     * Create a point instance at the origin (all coordinates to 0)
     */
    Point(std::initializer_list<T>);

    ~Point();

    /**
     * Get a reference to the value of a coordinate
     * @param index
     * @return
     */
    T &operator[](size_t index);

    /**
     * Get a const reference to the value of a coordinate
     * @param index
     * @return
     */
    const T &operator[](size_t index) const;

    /**
     * Get the dimension of the point
     * @return
     */
    size_t dimension();

    T x();

    T y();

    T z();

    /**
     *
     * @param other
     * @return
     */

    bool operator==(const Point<T, N> &);

    Point<T, N> &operator=(const Point<T, N> &);

    Point<T, N> &operator=(std::initializer_list<T> &);

    Point<T, N> operator+(const Point<T, N> &);

    Point<T, N> operator-(const Point<T, N> &);

    Point<T, N> operator*(const T &);

    Point<T, N> operator/(const T &);
};

template <typename T, size_t N> using Size = Point<T, N>;

template <typename T> using Point2D = Point<T, 2>;

template <typename T> using Point3D = Point<T, 3>;

template <typename T> using Size2D = Size<T, 2>;

template <typename T> using Size3D = Size<T, 3>;
} // namespace geom
} // namespace math
} // namespace stack

#endif // STACK_MATH_GEOM_POINT_H
