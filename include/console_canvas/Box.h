#ifndef BOX_H
#define BOX_H

#include "point_and_size.h"

namespace ctm
{

class CONSOLE_CANVAS_API Box : public WithOrigin, public WithSize
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

    Box& operator<<(const Point& p)
    {
        using namespace std::placeholders;
        if (empty()) {
            setOrigin(p);
            setSize(Size(1, 1));
        }
        else {
            ensureInRange(p.x(),
                origin().x(),
                std::bind(std::mem_fn(&Box::setOriginX), this, _1),
                size().width(),
                std::bind(std::mem_fn(&Box::setWidth), this, _1));
            ensureInRange(p.y(),
                origin().y(),
                std::bind(std::mem_fn(&Box::setOriginY), this, _1),
                size().height(),
                std::bind(std::mem_fn(&Box::setHeight), this, _1));
            }
        return *this;
    }

    void setOriginX(int x) {
        auto o = origin();
        o.setX(x);
        setOrigin(o);
    }

    void setOriginY(int y) {
        auto o = origin();
        o.setY(y);
        setOrigin(o);
    }

    void setWidth(int width) {
        auto s = size();
        s.setWidth(width);
        setSize(s);
    }

    void setHeight(int height) {
        auto s = size();
        s.setHeight(height);
        setSize(s);
    }

private:
    static bool inRange(int x, int origin, int size) {
        return x >= origin && x < origin + size;
    }
    template<class OS, class SS>
    static void ensureInRange(int x, int o, OS os, int s, SS ss) {
        auto d = x - o;
        if (d < 0) {
            os(o + d);
            ss(s - d);
        }
        else if (d >= s) {
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

#endif // BOX_H
