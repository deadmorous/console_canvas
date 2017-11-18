#include "console_canvas/SimpleStrokeStyle.h"
#include "console_canvas/Canvas.h"

namespace ctm {

void SimpleStrokeStyle::strokePixel(Canvas& c, const Point& p, int /*distFromStart*/)
{
    c.setPixel(p, color());
}

void SimpleStrokeStyle::write(std::ostream& s) const
{
    s << " " << color();
}

void SimpleStrokeStyle::read(std::istream& s)
{
    Color c;
    s >> c;
    setColor(c);
}

} // namespace ctm
