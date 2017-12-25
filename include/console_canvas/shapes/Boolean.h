#ifndef SHAPES_BOOLEAN_H
#define SHAPES_BOOLEAN_H

#include "console_canvas/Shape.h"

#include "console_canvas/Scene.h"


#include <iostream>
#include <iterator>
#include <vector>

namespace ctm {
namespace shapes {

// TODO AN

class CONSOLE_CANVAS_API Boolean :
        public Shape,
        public FactoryMixin< Boolean, Shape >
{
public:
    void paint(Canvas&) const override;
    Box boundingBox() const override;
    void write(std::ostream& s) const override;
    void read(std::istream& s) override;



    std::vector<std::shared_ptr<Shape>> shapes() const;
    void addShape(const std::shared_ptr<Shape>& shape);

    Canvas compare_or(Canvas&c1,Canvas&c2,Canvas&c_out,Color color1,Color color2) const;


private:

    std::vector<std::shared_ptr<Shape>> m_shapes;



};

} // namespace shapes
} // namespace ctm

#endif // SHAPES_BOOLEAN_H
