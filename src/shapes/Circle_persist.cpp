#include "console_canvas/shapes/Circle.h"
#include "console_canvas/SimpleFillStyle.h"
#include "console_canvas/cxx_exception.h"
#include <iostream>

namespace ctm {
namespace shapes {

void Circle::write(std::ostream& s) const
{
    s<<std::string("Circle")<<std::endl;
    s<<this->center->x()<<std::endl;
    s<<this->center->y()<<std::endl;
    s<<this->radius<<std::endl;

    //работа со стилями
    s<<filled<<std::endl;

    this->fillStyle()->m_fillStyleChild->write(s);// сохранение стиля заливки
}

void Circle::read(std::istream& s)
{

    std::string centerX;
    std::string centerY;
    std::string radius_temp;
    std::getline(s,  centerX);
    std::getline(s,  centerY);
    std::getline(s, radius_temp);

    Point p(std::stoi( centerX ),std::stoi( centerY ) ) ;

    setCenter(   p      );
    setRadius( 3);




    //this->center->setX(std::stoi( centerX ));
    //this->center->setY(std::stoi( centerY ));
    this->radius=std::stoi( radius_temp );


    //  std::cout<<"loaded circle"<<std::endl;

    //std::cout<<p<<std::endl;
    // std::cout<<this->radius<<std::endl;

    //работа со стилями
    std::string fillstyle1;
    std::getline(s,   fillstyle1);
    this->filled=std::stoi( fillstyle1.c_str());


    this->setFillStyle(std::make_shared<SimpleFillStyle>('0'));
    // просто делаем умный указатель выделяем память на SimpleFillStyle
    // чтобы не поймать segfault
    this->fillStyle()->m_fillStyleChild->read(s);// чтение

    if (s.fail())
        throw ctm::exception("Invalid input Circle");
}



} // namespace shapes
} // namespace ctm
