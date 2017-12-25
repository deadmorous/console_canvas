#include "console_canvas/shapes/Rectangle.h"
#include "console_canvas/FillStyle.h"
#include"console_canvas/SimpleFillStyle.h"
#include <vector>
#include <iostream>
namespace ctm {
namespace shapes {

//! \author
//! \brief Rectangle::RectanglePaintLine
//! \param p1
//! \param p2
//! \param c
//!

void Rectangle::RectanglePaintLine(Point p1, Point p2, Canvas &c) const
{


    std::vector<int> x;
    std::vector<int> y;
    //заполнение границ, в прямоугольнике в таком порядке используя два динамических массива
    //   _2___
    //4|       |3
    //  |____|
    //     1
    for(int i=0;i<= abs(p2.x()-p1.x());++i)
    {

        // заполнение векторов
        x.push_back(p1.x()+i);
        y.push_back(p1.y()); // фиксированная точка

        ctm::Point p (x[i], y[i]);
        fillStyle()->strokePixel(c,p);

    }
    // очищаем вектора
    x.clear();
    y.clear();


    // в остальных циклах все аналогично
    for(int i=0;i<= abs(p2.x()-p1.x());++i)
    {


        x.push_back(p1.x()+i);
        y.push_back(p2.y());

        ctm::Point p (x[i], y[i]);
        fillStyle()->strokePixel(c,p);


    }
    x.clear();
    y.clear();

    for(int i=0;i<= abs(p2.y()-p1.y());++i)
    {
        x.push_back(p2.x());
        y.push_back(p2.y()-i);

        ctm::Point p (x[i], y[i]);
        fillStyle()->strokePixel(c,p);
    }

    x.clear();
    y.clear();

    for(int i=0;i<= abs(p2.y()-p1.y());++i)
    {
        x.push_back(p1.x());
        y.push_back(p1.y()+i);
        ctm::Point p (x[i], y[i]);
        fillStyle()->strokePixel(c,p);
    }
    x.clear();
    y.clear();
}
//Отрисовка прямоугольника
//Механизм заливки у всех фигур одинаковый
void Rectangle::paint(Canvas& canvas_out) const
{
    //если он не залит(задается в тестах, определена в shape.h)
    if(this->filled==false)
    {
        // просто нарисуем контуры
        RectanglePaintLine(left_bottom_point, right_top_point, canvas_out);
    }
    //если он  залит
    if(this->filled==true)
    {
        // создать временный холст, делаем чтобы не затирать предыдущие
        Canvas *c=new Canvas(canvas_out.size()) ;
        //   нарисуем контуры
        RectanglePaintLine(left_bottom_point, right_top_point, *c);

        // структура маркера

        struct counter
        {
            bool active;// когда активен
            int fillrange;// длина заливки
            ctm::Point start_marker; // сам маркер, говори где начало
        };

        // создадим переменные для пробега по вектору холста
        std::vector<counter> count_vector;
        char thisPixel;
        char previousPixel;

        for(int j=0 ;j<c->size().height();++j)
        {
            for(int i=0 ;i<c->size().width();++i)
            {
                thisPixel=c->pixel(Point(i+1,j)); //пробег по вектору холста  чтение следующего пикселя
                previousPixel=c->pixel(Point(i,j)); //пробег по вектору холста настоящего пикселя

                //если настоящий равен фону и следующий -своему цвету, то ставим маркер
                if(  ( previousPixel==c->backGround_color()  &&   thisPixel== this->fillStyle()->m_fillStyleChild->color()  ) )
                {
                    //инициализируем структуру маркера
                    struct counter count1={false,0,ctm::Point(0,0)};
                    count1.active=true;

                    count1.start_marker=ctm::Point(i,j);
                    count_vector.push_back(count1);
                }
                //если настоящий равен своему цвету  и следующий фону, то прекращаем счетчик расстояния маркера()
                if( count_vector.size()!=0  && (  previousPixel==  this->fillStyle()->m_fillStyleChild->color() &&  thisPixel==c->backGround_color() ) )
                {
                    count_vector.back().active=false;
                }

                // реализация счетчика расстояния от одного символа до другого в одной строке
                if(count_vector.size()!=0&&count_vector.back().active==true)
                {
                    count_vector.back().fillrange++;
                }

            }
        }

        //заполнение отладочным символом 0
        for(int k=0;k<count_vector.size();++k)
        {
            for(int i=0;i<count_vector.at(k).fillrange;++i)
            {
                c->setPixel(Point(count_vector.at(k).start_marker.x()+i,count_vector.at(k).start_marker.y()),Color('0'));
            }
        }
        //очистка вектора
        count_vector.clear();

        Point start;
        Point end;
        //нахождение нулей и их заполнение заливкой
        //что то типа фильтра, чтобы не возникало ошибок
        std::vector<Point> null_Points;
        for(int j=0 ;j<c->size().height();++j)
        {
            for(int i=0 ;i<c->size().width();++i)
            {
                thisPixel=c->pixel(Point(i,j));


                if(  ( thisPixel=='0'   ) )
                {
                    null_Points.push_back(ctm::Point(i,j));
                }

            }
            if(null_Points.size()!=0)
            {
                start= null_Points.front();
                end= null_Points.back();

                for (int k=0;k<abs(end.x()-start.x())+1;++k)
                {
                    c->setPixel(Point(start.x()+k,start.y()),Color('*'));
                }
                null_Points.clear();
            }

        }

        null_Points.clear();
        char thisPixel_c1;
        char thisPixel_c2;

        //заполнение отладочным символом 9
        for(int j=0 ;j<canvas_out.size().height();++j)
        {
            for(int i=0 ;i<canvas_out.size().width();++i)
            {
                thisPixel_c1= c->pixel(Point(i,j));
                thisPixel_c2=canvas_out.pixel(Point(i,j));

                if(thisPixel_c1==c->backGround_color() &&  thisPixel_c2==canvas_out.backGround_color())
                {
                    canvas_out.setPixel(Point(i,j),Color('9'));

                }

            }
        }
  //заполнение своим символом
        for(int j=0 ;j<canvas_out.size().height();++j)
        {
            for(int i=0 ;i<canvas_out.size().width();++i)
            {

                thisPixel_c1= canvas_out.pixel(Point(i,j));
                if(thisPixel_c1==canvas_out.backGround_color())
                {
                    canvas_out.setPixel(Point(i,j),this->fillStyle()->m_fillStyleChild->color());

                }


            }
        }


  //замена отладочного символа на фон
        char temp_nine;
        for(int j=0 ;j<canvas_out.size().height();++j)
        {
            for(int i=0 ;i<canvas_out.size().width();++i)
            {

                temp_nine= canvas_out.pixel(Point(i,j));
                if(temp_nine=='9')
                {
                    canvas_out.setPixel(Point(i,j),canvas_out.backGround_color());

                }


            }
        }
// удаление холста
        delete c;
    }
}

//здесь выбираются самые большие размеры фигур
// за точку отсчета принята левая нижняя точка
Box Rectangle::boundingBox() const
{
    //std::cout<<"RectBB"<<std::endl;
    Box b;
    b.setOrigin(ctm::Point(left_bottom_point.x(),left_bottom_point.y()) );
    b.setWidth(right_top_point.x()-left_bottom_point.x());
    b.setHeight(right_top_point.y()-left_bottom_point.y());
    return b;
}



} // namespace shapes
} // namespace ctm
