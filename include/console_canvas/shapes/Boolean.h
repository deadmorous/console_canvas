#ifndef SHAPES_BOOLEAN_H
#define SHAPES_BOOLEAN_H

#include "console_canvas/Shape.h"

namespace ctm {
namespace shapes {

// TODO AN

class CONSOLE_CANVAS_API Boolean :
    public Shape,
    public FactoryMixin< Boolean, Shape >
{
};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_BOOLEAN_H
