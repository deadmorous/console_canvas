#ifndef SIMPLEFILLSTYLE_H
#define SIMPLEFILLSTYLE_H

#include "console_canvas/FillStyle.h"
#include "console_canvas/Color.h"

namespace ctm {

class CONSOLE_CANVAS_API SimpleFillStyle :
    public FillStyle,
    public FactoryMixin<SimpleFillStyle, FillStyle>,
    public WithColor
{
public:
    SimpleFillStyle();
    explicit SimpleFillStyle(const Color& color);
    void strokePixel(Canvas& c, const Point& p) override;
    void write(std::ostream& s) const override;
    void read(std::istream& s) override;
};

} // namespace ctm

#endif // SIMPLEFILLSTYLE_H
