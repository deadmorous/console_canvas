#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H
#include "console_canvas/Canvas.h"
#include "console_canvas/Shape.h"
#include "console_canvas/Color.h"
namespace ctm {
namespace shapes {

// TODO LP

class CONSOLE_CANVAS_API Circle :
    public Shape,
    public FactoryMixin< Circle, Shape >
{
public:
    void paint(Canvas& c) const override;
    Box boundingBox() const override;
    void write(std::ostream& s) const override;
    void read(std::istream& s) override;
    Point center;
    size_t radius;

};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_CIRCLE_H
