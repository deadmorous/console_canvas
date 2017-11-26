#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

#include "console_canvas/Shape.h"

namespace ctm {
namespace shapes {

// TODO LP

class CONSOLE_CANVAS_API Circle :
    public Shape,
    public FactoryMixin< Circle, Shape >
{
public:
    void paint(Canvas&) const override;
    Box boundingBox() const override;
    void write(std::ostream& s) const override;
    void read(std::istream& s) override;
};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_CIRCLE_H
