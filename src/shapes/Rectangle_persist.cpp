#include "console_canvas/shapes/Rectangle.h"
#include "console_canvas/cxx_exception.h"

#include"console_canvas/SimpleFillStyle.h"

#include "console_canvas/FillStyle.h"
#include <iostream>
#include <memory>
namespace ctm {
namespace shapes {

/*!
 * \brief Функция записи
 * \author EG
 * \param s -поток вывода
 */

void Rectangle::write(std::ostream& s) const
{
    s<<std::string("Rectangle")<<std::endl;
    s<<this->left_bottom_point.x()<<std::endl;
    s<<this->left_bottom_point.y()<<std::endl;
    s<<this->right_top_point.x()<<std::endl;
    s<<this->right_top_point.y()<<std::endl;


    //работа со стилями
    s<<filled<<std::endl;
    this->fillStyle()->m_fillStyleChild->write(s);// сохранение стиля заливки



}

/*!
 * \brief Функция чтения
 * \param s -поток вывода
 */


void Rectangle::read(std::istream& s)
{

    std::string X0;
    std::string Y0;
    std::string X1;
    std::string Y1;

    std::getline(s,  X0);
    std::getline(s,  Y0);
    std::getline(s,  X1);
    std::getline(s,  Y1);


    left_bottom_point.setX(std::stoi(X0 ));
    left_bottom_point.setY(std::stoi( Y0 ));

    right_top_point.setX(std::stoi( X1 ));
    right_top_point.setY(std::stoi( Y1 ));


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
