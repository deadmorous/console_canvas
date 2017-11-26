#ifndef SHAPES_POLYGON_H
#define SHAPES_POLYGON_H

#include "console_canvas/Shape.h"

namespace ctm {
namespace shapes {

// TODO LP

class CONSOLE_CANVAS_API Polygon :
    public Shape,
    public FactoryMixin< Polygon, Shape >
{
public:
    void paint(Canvas&) const override;
    Box boundingBox() const override;
    void write(std::ostream& s) const override;
    void read(std::istream& s) override;
};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_POLYGON_H
