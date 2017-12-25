#ifndef SCENE_H
#define SCENE_H
#include "console_canvas/Canvas.h"
#include "console_canvas/Shape.h"


#include "console_canvas/Box.h"


#include "console_canvas/shapes/Boolean.h"
#include "console_canvas/shapes/Polygon.h"
#include "console_canvas/shapes/Circle.h"
#include "console_canvas/shapes/Rectangle.h"
#include "console_canvas/shapes/Triangle.h"

#include <vector>
#include <memory>

namespace ctm {

// TODO AN

class Scene :
        public Persistent
{
public:
    //!
    //! \brief
    //!
    Scene();
    //!
    //! \brief addShape
    //! \param shape
    //!
    void addShape(const std::shared_ptr<Shape>& shape);

    //! \brief ctm::Scene::paint
    //! \param c
    //!
    void paint(Canvas& c) const;

    //! \brief ctm::Scene::boundingBox
    //! \return
    Box boundingBox() const;

    //! \brief ctm::Scene::shapes
    //! \return
    std::vector<std::shared_ptr<Shape>> shapes() const;

    //! \brief ctm::Scene::write
    //! \param s
    void write(std::ostream& s) const override;


    //! \brief ctm::Scene::read
    //! \param s
    void read(std::istream& s) override;


private:
    std::vector<std::shared_ptr<Shape>> m_shapes;
};

} // namespace ctm






#endif // SCENE_H
