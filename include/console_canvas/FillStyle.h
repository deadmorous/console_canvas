#ifndef FILLSTYLE_H
#define FILLSTYLE_H

#include "console_canvas/Color.h"
#include "console_canvas/Factory.h"
#include "console_canvas/Point.h"
#include "console_canvas/Persistent.h"

#include <iostream>
namespace ctm {
class SimpleFillStyle;
class Canvas;

class CONSOLE_CANVAS_API FillStyle :


        public Factory<FillStyle>,
        public Persistent
{
public:
    virtual ~FillStyle( )  {}
    virtual void strokePixel(Canvas& c, const Point& p){}

 SimpleFillStyle  *m_fillStyleChild; //dirty

};

CTM_DEF_PROP_CLASS(
        WithFillStyle,
        std::shared_ptr<FillStyle>,
        std::shared_ptr<FillStyle>,
        fillStyle,
        setFillStyle)

} // namespace ctm

#endif // FILLSTYLE_H
