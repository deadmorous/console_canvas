#include "console_canvas/shapes/Boolean.h"
#include "console_canvas/Canvas.h"
#include "console_canvas/SimpleFillStyle.h"
#include <iostream>
#include <math.h>
namespace ctm {
namespace shapes {

//!
//! \brief Boolean::paint
//! \author AN
//! \param c




void Boolean::paint(Canvas&c) const
{

//создание временных холстов
    Canvas *c1=new Canvas(c.size()) ;
    Canvas *c2=new Canvas(c.size()) ;
//орисовка в них
    m_shapes[0]->paint(*c1);
    m_shapes[1]->paint(*c2);


    //оставлено для проверки, показывает линии фигур и что пересекает друг друга
    //можно убрать,
     m_shapes[0]->filled=false;
     m_shapes[1]->filled=false;
    m_shapes[0]->paint(c);
    m_shapes[1]->paint(c);
//

    //функция сравнения
     compare_or(*c1,*c2,c,m_shapes[0]->fillStyle()->m_fillStyleChild->color(),  m_shapes[1]->fillStyle()->m_fillStyleChild->color());
     //удаление временных холстов (иначе утечка памяти в 3000 байтов)
     delete c1;
     delete c2;
}

// функция логического или
Canvas Boolean::compare_or(Canvas&c1,Canvas&c2,Canvas&c_out,Color color1,Color color2) const
{

    char thisPixel_c1;
    char thisPixel_c2;


    for(int j=0 ;j<c_out. size().height() ;++j)
    {
        for(int i=0 ;i<c_out. size().width() ;++i)
        {
            thisPixel_c1=c1.pixel(Point(i,j));
            thisPixel_c2=c2.pixel(Point(i,j));

            if(  (thisPixel_c1==color1) && (thisPixel_c2==color2))
            {
                c_out.setPixel(Point(i,j),color1 );
            }



        }
    }



    return c_out;
}
//выводит размер всех фигур на сцене
//здесь выбираются самые большие размеры фигур
// за точку отсчета принято (0,0), так как все холсты одного размера
Box Boolean::boundingBox() const
{
    std::cout<<"BooleanBB contains this shapes:"<<std::endl;
    Box b;
    b.setOrigin(ctm::Point(0,0));

    Box  b2=m_shapes[0]->boundingBox();
    Box  b3= m_shapes[1]->boundingBox();

    if(b2.size().width()<b3.size().width())
    {
        b.setWidth(b3.size().width());
    }
    else if(b2.size().width()>b3.size().width())
    {
        b.setWidth(b2.size().width());
    }

    if(b2.size().height()<b3.size().height())
    {
        b.setHeight (b3.size().height() );
    }
    else if(b2.size().height()>b3.size().height())
    {
        b.setHeight  (b2.size().height() );
    }
    return b;
}

//  Boolean работает как контейнер 2 фигур, чтобы им пользоваться надо добавить 2 фигуры
void Boolean::addShape(const std::shared_ptr<Shape> &shape)
{
    m_shapes.push_back(shape);
}

// get-метод , возвращает массив указателей фигур
std::vector<std::shared_ptr<Shape> > Boolean::shapes() const
{
    return m_shapes;
}

} // namespace shapes
} // namespace ctm
