#ifndef CANVAS_H
#define CANVAS_H

#include "console_canvas/Box.h"
#include "console_canvas/Color.h"

#include <vector>

namespace ctm {

// TODO KB

class Canvas :
        public WithSize
{
private:
    std::vector<char> matrix_color;
    Color m_backGround_color;
public:
    Canvas();
    ~Canvas();
    explicit Canvas(const Size& size);
    void clear(Color color = ' ');
    Color pixel(const Point& p) const;
    void setPixel(const Point& p, Color color);
    Color backGround_color() const;
    std::vector<char> Matrix_color();
};

template<class S>
S& operator<<(S& s, const Canvas& c)
{
    // TODO
    return s;
}

} // namespace ctm

#endif // CANVAS_H
