#ifndef STROKESTYLE_H
#define STROKESTYLE_H

#include "console_canvas/Color.h"
#include "console_canvas/Factory.h"
#include "console_canvas/Point.h"
#include "console_canvas/Persistent.h"

namespace ctm {

class Canvas;

class CONSOLE_CANVAS_API StrokeStyle :
    public Factory<StrokeStyle>,
    public Persistent
{
public:
    virtual ~StrokeStyle() {}
    virtual void strokePixel(Canvas& c, const Point& p, int distFromStart = 0) = 0;
};

} // namespace ctm

#endif // STROKESTYLE_H
