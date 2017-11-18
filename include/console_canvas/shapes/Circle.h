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
};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_CIRCLE_H
