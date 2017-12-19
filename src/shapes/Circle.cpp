#include "console_canvas/shapes/Circle.h"
#include <ostream>


namespace ctm {
namespace shapes {


void Circle::paint(Canvas& c) const
{
    int x0 = center.x();
    int y0 = center.y();

    int x = radius;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
        //! Функция изменения одномерного массива, находится в холсте
        c.setPixel(ctm::Point(x0+x,y0 + y),ctm::Color('*'));
        c.setPixel(ctm::Point(x0 + y, y0 + x),ctm::Color('*'));
        c.setPixel(ctm::Point(x0 - y, y0 + x),ctm::Color('*'));
        c.setPixel(ctm::Point(x0 - x, y0 + y),ctm::Color('*'));
        c.setPixel(ctm::Point(x0 - x, y0 - y),ctm::Color('*'));
        c.setPixel(ctm::Point(x0 - y, y0 - x),ctm::Color('*'));
        c.setPixel(ctm::Point(x0 + y, y0 - x),ctm::Color('*'));
        c.setPixel(ctm::Point(x0 + x, y0 - y),ctm::Color('*'));

        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}


Box Circle::boundingBox() const
{
    Box b;
    b.setOrigin(center);
    b.setWidth(abs((center.x()+radius)-(center.x()-radius)));
    b.setHeight(abs((center.y()+radius)-(center.y()-radius)));
    return b;
}

} // namespace shapes
} // namespace ctm




