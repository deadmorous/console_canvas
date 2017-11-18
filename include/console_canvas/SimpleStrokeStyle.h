#ifndef SIMPLESTROKESTYLE_H
#define SIMPLESTROKESTYLE_H

#include "console_canvas/StrokeStyle.h"
#include "console_canvas/Color.h"

namespace ctm {

class CONSOLE_CANVAS_API SimpleStrokeStyle :
    public StrokeStyle,
    public FactoryMixin<SimpleStrokeStyle, StrokeStyle>,
    public WithColor,
    public WithWidth
{
public:
    void strokePixel(Canvas& c, const Point& p, int distFromStart = 0) override;
    void write(std::ostream& s) const override;
    void read(std::istream& s) override;
};

} // namespace ctm

#endif // SIMPLESTROKESTYLE_H
