#ifndef POINT_H
#define POINT_H

#include "def_prop_class.h"

namespace ctm
{

CTM_DEF_NOTIFIED_PROP_CLASS(WithX, int, int, x, setX, onChangeX, offChangeX)
CTM_DEF_NOTIFIED_PROP_CLASS(WithY, int, int, y, setY, onChangeY, offChangeY)

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

CTM_DEF_NOTIFIED_PROP_CLASS(WithOrigin, Point, const Point&, origin, setOrigin, onChangeOrigin, offChangeOrigin)

CTM_DEF_NOTIFIED_PROP_CLASS(WithWidth, int, int, width, setWidth, onChangeWidth, offChangeWidth)
CTM_DEF_NOTIFIED_PROP_CLASS(WithHeight, int, int, height, setHeight, onChangeHeight, offChangeHeight)



class Size : public WithWidth, public WithHeight
{
public:
    Size() {}
    Size(int width, int height) : WithWidth(width), WithHeight(height) {}
};

template< class S >
inline S& operator<<(S& s, const Size& sz) {
    s << sz.width() << "x" << sz.height() << ")";
    return s;
}

CTM_DEF_NOTIFIED_PROP_CLASS(WithSize, Size, const Size&, size, setSize, onChangeSize, offChangeSize)



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

inline Size operator-(const Point& a, const Point& b) {
    return Size(a.x() - b.x(), a.y() - b.y());
}

inline Point operator-(const Point& a) {
    return Point(-a.x(), -a.y());
}



class Box : public WithOrigin, public WithSize
{
public:
    Box() {}
    Box(const Point& origin, const Size& size) : WithOrigin(origin), WithSize(size) {}
    bool contains(const Point& p) const {
        return inRange(p.x(), origin().x(), size().width()) && inRange(p.y(), origin().y(), size().height());
    }
    bool empty() const {
        return size().width() == 0   ||   size().height() == 0;
    }
    Box& operator<<(const Point& p) {
        if (empty()) {
            setOrigin(p);
            setSize(Size(1, 1));
        }
        else {
            ensureInRange(p.x(),
                [this](){ return origin().x(); },
                [this](int x) {
                    auto o = origin();
                    o.setX(x);
                    setOrigin(o);
                },
                [this](){ return size().width(); },
                [this](int w) {
                    auto s = size();
                    s.setWidth(w);
                    setSize(s);
                });
            ensureInRange(p.y(),
                [this](){ return origin().y(); },
                [this](int y) {
                    auto o = origin();
                    o.setY(y);
                    setOrigin(o);
                },
                [this](){ return size().height(); },
                [this](int h) {
                    auto s = size();
                    s.setHeight(h);
                    setSize(s);
                });
            }
        return *this;
        }

private:
    static bool inRange(int x, int origin, int size) {
        return x >= origin && x < origin + size;
    }
    template<class OG, class OS, class SG, class SS>
    static void ensureInRange(int x, OG og, OS os, SG sg, SS ss) {
        auto d = x - og();
        if (d < 0) {
            os(og() + d);
            ss(sg() - d);
        }
        else if (d >= sg()) {
            ss(d+1);
        }
    }
};

template< class S >
inline S& operator<<(S& s, const Box& b) {
    s << "[" << b.origin() << ", " << b.size() << "]";
    return s;
}

} // namespace ctm

#endif // POINT_H
