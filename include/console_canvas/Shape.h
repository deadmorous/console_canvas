#ifndef SHAPE_H
#define SHAPE_H

#include "console_canvas/Persistent.h"
#include "console_canvas/Box.h"
#include "console_canvas/Factory.h"
#include "console_canvas/StrokeStyle.h"
#include "console_canvas/FillStyle.h"

namespace ctm {

class Canvas;

class CONSOLE_CANVAS_API Shape :
        public Persistent,
        public WithStrokeStyle,
        public WithFillStyle,
        public Factory<Shape>
{
public:
    virtual ~Shape() {}
    virtual void paint(Canvas&) const = 0;
    virtual Box boundingBox() const = 0;
    bool filled=false;
protected:

};

} // namespace ctm

#endif // SHAPE_H
