#ifndef SHAPES_RECTANGLE_H
#define SHAPES_RECTANGLE_H

#include "console_canvas/Shape.h"

namespace ctm {
namespace shapes {

// TODO AS

class CONSOLE_CANVAS_API Boolean :
    public Shape,
    public FactoryMixin< Boolean, Shape >
{
};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_RECTANGLE_H
