#include "console_canvas/shapes/Circle.h"
#include "console_canvas/cxx_exception.h"
#include <iostream>

namespace ctm {
namespace shapes {

void Circle::write(std::ostream& s) const
{
    ASSERT(false); // TODO EG
}

void Circle::read(std::istream& s)
{
    Point center;
    int radius;
    s >> /*center >> */ radius;
    if (s.fail())
        throw ctm::exception("Invalid input");
    ASSERT(false); // TODO EG
}

} // namespace shapes
} // namespace ctm
