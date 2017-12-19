#include "console_canvas/SimpleFillStyle.h"
#include "console_canvas/Canvas.h"

namespace ctm {

SimpleFillStyle::SimpleFillStyle()
{
}

SimpleFillStyle::SimpleFillStyle(const Color& color) :
    WithColor(color)
{
}

void SimpleFillStyle::strokePixel(Canvas& c, const Point& p)
{
    c.setPixel(p, color());
}

void SimpleFillStyle::write(std::ostream& s) const
{
    s << " " << color();
}

void SimpleFillStyle::read(std::istream& s)
{
    Color c;
    s >> c;
    setColor(c);
}

} // namespace ctm
