#include "console_canvas/shapes/Boolean.h"
#include "console_canvas/cxx_exception.h"

namespace ctm {
namespace shapes {

void Boolean::write(std::ostream& s) const
{
    s<<std::string("Boolean")<<std::endl;
    std::vector<std::shared_ptr<Shape>> temp_shapes=shapes();
    for(size_t i=0;i<temp_shapes.size();++i)
    {
        temp_shapes.at(i)->write(s);
    }
    s<<std::string("EndBoolean")<<std::endl;
}



void Boolean::read(std::istream& s)
{
    std::string tempRead;


    while(!s.eof())
    {
        std::getline(s, tempRead);
        if(tempRead.c_str()==std::string("EndBoolean"))
        {
            break;
        }

        if(tempRead.c_str()==std::string("Circle"))
        {
            auto c1 = std::make_shared<ctm::shapes::Circle>();
            c1->read(s);
            this->addShape(c1);
        }
        if(tempRead.c_str()==std::string("Polygon"))
        {
            auto c1 = std::make_shared<ctm::shapes::Polygon>();
            c1->read(s);
            this->addShape(c1);
        }
        if(tempRead.c_str()==std::string("Rectangle"))
        {
            auto c1 = std::make_shared<ctm::shapes::Rectangle>();
            c1->read(s);
            this->addShape(c1);
        }
        if(tempRead.c_str()==std::string("Triangle"))
        {
            auto c1 = std::make_shared<ctm::shapes::Triangle>();
            c1->read(s);
            this->addShape(c1);
        }
    }
    //std::cout<<"loaded Boolean"<<std::endl;


    if (s.fail())
        throw ctm::exception("Invalid input Boolean");
}





} // namespace shapes
} // namespace ctm
