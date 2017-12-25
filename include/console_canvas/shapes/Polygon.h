#ifndef SHAPES_POLYGON_H
#define SHAPES_POLYGON_H
#include "console_canvas/Canvas.h"
#include "console_canvas/Shape.h"
#include "console_canvas/Point.h"

namespace ctm {
namespace shapes {

// TODO LP

class CONSOLE_CANVAS_API Polygon :
        public Shape,
        public FactoryMixin< Polygon, Shape >
{
public:
    void paint(Canvas& c) const override;


    Box boundingBox() const override;
    void write(std::ostream& s) const override;
    void read(std::istream& s) override;
    std::vector<ctm::Point> points;
private:
    void paintLine(ctm::Point p1,ctm::Point p2,Canvas& c)const;



};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_POLYGON_H
