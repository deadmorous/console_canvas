#include "console_canvas/SimpleFillStyle.h"
#include "console_canvas/Canvas.h"
#include <iostream>
namespace ctm {

SimpleFillStyle::SimpleFillStyle(): WithColor(Color('0'))
{
    this->m_fillStyleChild= this; //dirty
}

SimpleFillStyle::SimpleFillStyle(const Color& color) :
    WithColor(color)
{
    this->m_fillStyleChild=this;//dirty
}

void SimpleFillStyle::strokePixel(Canvas& c, const Point& p)
{
    try
    {
        c.setPixel(p, color());
    }
    catch(const std::exception& e) {
        using namespace std;
        cerr << "ERROR: " << e.what() << endl;

    }
}

void SimpleFillStyle::write(std::ostream& s) const
{
    s << color()<<'\n';
}

void SimpleFillStyle::read(std::istream& s)
{
    std::string tempstr;
    std::getline(s,   tempstr);
    Color c(tempstr.at(0));

    setColor(c);
}

} // namespace ctm
