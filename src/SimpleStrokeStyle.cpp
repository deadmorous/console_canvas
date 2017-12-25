#include "console_canvas/SimpleStrokeStyle.h"
#include "console_canvas/Canvas.h"

namespace ctm {

SimpleStrokeStyle::SimpleStrokeStyle()
{
        this->m_stokeStyleChild=this;//dirty
}

SimpleStrokeStyle::SimpleStrokeStyle(const Color& color, int width) :
    WithColor(color),
    WithWidth(width)
{
    this->m_stokeStyleChild=this;//dirty
}

void SimpleStrokeStyle::strokePixel(Canvas& c, const Point& p, int  distFromStart )
{
    // TODO: Use width!

  for(int i=distFromStart;i<c.size().width();++i)
    {
    c.setPixel(Point(p.x()+i,p.y()), color());
    }
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
