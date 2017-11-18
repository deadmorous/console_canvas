#ifndef CANVAS_H
#define CANVAS_H

#include "console_canvas/Box.h"
#include "console_canvas/Color.h"

namespace ctm {

// TODO KB

class Canvas :
    public WithSize
{
public:
    Canvas() : WithSize(Size(79, 23)) {}
    explicit Canvas(const Size& size) : WithSize(size) {}
    void clear(Color color = ' ');
    Color pixel(const Point& p) const;
    void setPixel(const Point& p, Color color);
};

template<class S>
S& operator<<(S& s, const Canvas& c)
{
    // TODO
    return s;
}

} // namespace ctm

#endif // CANVAS_H
