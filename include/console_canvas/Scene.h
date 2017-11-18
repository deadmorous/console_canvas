#ifndef SCENE_H
#define SCENE_H

#include "console_canvas/Shape.h"
#include <vector>
#include <memory>

namespace ctm {

// TODO AN

class Scene :
    public Persistent
{
public:
    std::vector<std::shared_ptr<Shape>> shapes() const;
    void addShape(const std::shared_ptr<Shape>& shape);
    void paint(Canvas& c) const;
    Box boundingBox() const;
    void write(std::ostream& s) const override;
    void read(std::istream& s) override;
};

} // namespace ctm

#endif // SCENE_H
