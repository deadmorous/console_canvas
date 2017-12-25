#include "console_canvas/shapes/Polygon.h"
#include "console_canvas/cxx_exception.h"
#include "console_canvas/FillStyle.h"
#include"console_canvas/SimpleFillStyle.h"
#include <iostream>
namespace ctm {
namespace shapes {

/*!
 * \brief Функция записи
 * \param s -поток вывода
 */

void Polygon::write(std::ostream& s) const
{
    s<<std::string("Polygon")<<std::endl;

    std::string tempSize = std::to_string(points.size());
    s<<tempSize<<std::endl;
    for(int i=0;i<points.size();++i)
    {
        s<<this->points[i].x()<<std::endl;
        s<<this->points[i].y()<<std::endl;
    }

    //работа со стилями
    s<<filled<<std::endl;
    this->fillStyle()->m_fillStyleChild->write(s);// сохранение стиля заливки


}

/*!
 * \brief Функция чтения
 * \param s -поток вывода
 */


void Polygon::read(std::istream& s)
{

    std::string X;
    std::string Y;
    std::string temp_size;

    std::vector<ctm::Point> temp_points;
    std::getline(s,  temp_size);
    for(int i=0;i<(std::stoi( temp_size ));++i)
    {
        std::getline(s,  X);
        std::getline(s,  Y);
        points.push_back(ctm::Point(std::stoi( X ),std::stoi( Y )));
    }
    //points=temp_points;


  //  std::cout<<"loaded Polygon"<<std::endl;
    for(int i=0;i<points.size();++i)
    {
        //std::cout<<points[i]<<std::endl;
    }

    //работа со стилями
    std::string fillstyle1;
    std::getline(s,   fillstyle1);
    this->filled=std::stoi( fillstyle1.c_str());


    this->setFillStyle(std::make_shared<SimpleFillStyle>('0'));
    // просто делаем умный указатель выделяем память на SimpleFillStyle
    // чтобы не поймать segfault
    this->fillStyle()->m_fillStyleChild->read(s);// чтение


    if (s.fail())
        throw ctm::exception("Invalid input Polygon");

}



} // namespace shapes
} // namespace ctm
