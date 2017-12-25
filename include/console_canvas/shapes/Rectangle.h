#ifndef SHAPES_RECTANGLE_H
#define SHAPES_RECTANGLE_H
#include "console_canvas/Canvas.h"
#include "console_canvas/Shape.h"
#include "console_canvas/Point.h"
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

    ctm::Point left_bottom_point;
    ctm::Point right_top_point;
private:
    void RectanglePaintLine(Point p1, Point p2, Canvas &c) const;

};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_RECTANGLE_H
