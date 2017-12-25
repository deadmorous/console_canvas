#ifndef SHAPES_TRIANGLE_H
#define SHAPES_TRIANGLE_H

#include "console_canvas/Shape.h"

namespace ctm {
namespace shapes {

// TODO AS

class CONSOLE_CANVAS_API Triangle :
    public Shape,
    public FactoryMixin< Triangle, Shape >
{
public:
    void paint(Canvas&) const override;
    Box boundingBox() const override;
    void write(std::ostream& s) const override;
    void read(std::istream& s) override;

    std::vector<ctm::Point> points;
private:
     void paintLine(ctm::Point p1,ctm::Point p2,Canvas& c)const;
};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_TRIANGLE_H
