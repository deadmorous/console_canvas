#ifndef FILLSTYLE_H
#define FILLSTYLE_H

#include "console_canvas/Color.h"
#include "console_canvas/Factory.h"
#include "console_canvas/Point.h"
#include "console_canvas/Persistent.h"

namespace ctm {

class Canvas;

class CONSOLE_CANVAS_API FillStyle :
    public Factory<FillStyle>,
    public Persistent
{
public:
    virtual ~FillStyle() {}
    virtual void strokePixel(Canvas& c, const Point& p) = 0;
};

} // namespace ctm

#endif // FILLSTYLE_H
