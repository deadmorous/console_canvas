#ifndef SHAPES_POLYGON_H
#define SHAPES_POLYGON_H

#include "console_canvas/Shape.h"

namespace ctm {
namespace shapes {

// TODO LP

class CONSOLE_CANVAS_API Boolean :
    public Shape,
    public FactoryMixin< Boolean, Shape >
{
};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_POLYGON_H
