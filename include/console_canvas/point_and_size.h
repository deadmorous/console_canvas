#ifndef POINT_AND_SIZE_H
#define POINT_AND_SIZE_H

#include "def_prop_class.h"

namespace ctm
{

CTM_DEF_PROP_CLASS(WithX, int, int, x, setX)
CTM_DEF_PROP_CLASS(WithY, int, int, y, setY)

class Point : public WithX, public WithY
{
public:
    Point() {}
    Point(int x, int y) : WithX(x), WithY(y) {}
};

template< class S >
inline S& operator<<(S& s, const Point& p) {
    s << "(" << p.x() << "," << p.y() << ")";
    return s;
}

CTM_DEF_PROP_CLASS(WithOrigin, Point, const Point&, origin, setOrigin)

CTM_DEF_PROP_CLASS(WithWidth, int, int, width, setWidth)
CTM_DEF_PROP_CLASS(WithHeight, int, int, height, setHeight)



class Size : public WithWidth, public WithHeight
{
public:
    Size() {}
    Size(int width, int height) : WithWidth(width), WithHeight(height) {}
};

template< class S >
inline S& operator<<(S& s, const Size& sz) {
    s << sz.width() << "x" << sz.height();
    return s;
}

CTM_DEF_PROP_CLASS(WithSize, Size, const Size&, size, setSize)



inline Point operator+(const Point& a, const Size& b) {
    return Point(a.x() + b.width(), a.y() + b.height());
}

inline Point operator+(const Size& a, const Point& b) {
    return b + a;
}

inline Size operator+(const Size& a, const Size& b) {
    return Size(a.width() + b.width(), a.height() + b.height());
}

inline Point operator-(const Point& a, const Size& b) {
    return Point(a.x() - b.width(), a.y() - b.height());
}

inline Point operator-(const Size& a, const Point& b) {
    return Point(a.width() - b.x(), a.height() - b.y());
}

inline Size operator-(const Point& a, const Point& b) {
    return Size(a.x() - b.x(), a.y() - b.y());
}

inline Point operator-(const Point& a) {
    return Point(-a.x(), -a.y());
}

inline Size operator-(const Size& a) {
    return Size(-a.width(), -a.height());
}

} // namespace ctm

#endif // POINT_AND_SIZE_H
