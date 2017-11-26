#ifndef SHAPES_RECTANGLE_H
#define SHAPES_RECTANGLE_H

#include "console_canvas/Shape.h"

namespace ctm {
namespace shapes {

// TODO AS

class CONSOLE_CANVAS_API Rectangle :
    public Shape,
    public FactoryMixin< Rectangle, Shape >
{
public:
    void paint(Canvas&) const override;
    Box boundingBox() const override;
    void write(std::ostream& s) const override;
    void read(std::istream& s) override;
};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_RECTANGLE_H
