#include "console_canvas/shapes/Triangle.h"
#include "console_canvas/shapes/Polygon.h"
#include "console_canvas/FillStyle.h"
#include"console_canvas/SimpleFillStyle.h"
#include <math.h>
#include <iostream>
namespace ctm {
namespace shapes {
//!
//! \brief Triangle::paint
//! \author AS
//!

void Triangle::paintLine(Point p1, Point p2, Canvas &c) const
{
    float phi= atan2(p2.x()-p1.x(),p2.y()-p1.y());


    std::vector<int> x;
    std::vector<int> y;

    if(abs(p2.x()-p1.x())<c.size().width())
    {
        if(sin(phi)>0 )
        {
            for(int i=0;i<abs(p2.x()-p1.x() );++i)
            {

                x.push_back(p1.x()+i);
                int fy=  int( (float(x[i]-p1.x()))*(float(p2.y()-p1.y())) /float(p2.x()-p1.x()) ) +p1.y();
                y.push_back(fy);
            }
        }
        if(sin(phi)<0 )
        {
            for(int i=0;i<abs(p2.x()-p1.x() );++i)
            {

                x.push_back(p1.x()-i);
                int fy=  int( (float(x[i]-p1.x()))*(float(p2.y()-p1.y())) /float(p2.x()-p1.x()) ) +p1.y();
                y.push_back(fy);
            }
        }
        if(sin(phi)==0 )
        {
            for(int i=0;i<abs(p2.x()-p1.x() );++i)
            {

                x.push_back(p1.x()+i);
                int fy=   p1.y();
                y.push_back(fy);
            }
        }


    }
    else if(abs(p2.x()-p1.x())>c.size().width())
    {

    }

    for(int i=0;i<x.size();++i)
    {
        ctm::Point p (x[i], y[i]);
         FillStyle *temp=this->fillStyle().get();
         temp->strokePixel(c,p);

    }

}



void Triangle::paint(Canvas& canvas_out) const
{


        //если он не залит(задается в тестах, определена в shape.h)
        if(this->filled==false)
        {
            // просто нарисуем контуры
            Point first;
            Point end;


                first=points[0];
                end=points[1];

                paintLine(first,end,canvas_out);
                first=end;

                first=points[1];
                end=points[2];

                paintLine(first,end,canvas_out);
                first=end;

                first=points[2];
                end=points[0];

                paintLine(first,end,canvas_out);
                first=end;
        }
        //если он  залит
        if(this->filled==true)
        {
            // создать временный холст, делаем чтобы не затирать предыдущие
            Canvas *c=new Canvas(canvas_out.size()) ;
            //   нарисуем контуры

            Point first1;
            Point end1;


                first1=points[0];
                end1=points[1];

                paintLine(first1,end1,*c);
                first1=end1;

                first1=points[1];
                end1=points[2];

                paintLine(first1,end1,*c);
                first1=end1;

                first1=points[2];
                end1=points[0];

                paintLine(first1,end1,*c);
                first1=end1;









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



Box Triangle::boundingBox() const
{
    Box b;
   // std::cout<<"TriangleBB"<<std::endl;

    int max_x=0;
    int max_y=0;

    int min_x=0;
    int min_y=0;

    for (int i=0;i<points.size();++i)
    {
        if(points.at(i).x()<max_x)
        {

        }
        else if(points.at(i).x()>max_x)
        {
            max_x=points.at(i).x();

        }
        if(points.at(i).y()<max_y)
        {

        }
        else if(points.at(i).y()>max_y)
        {
            max_y=points.at(i).y();

        }
    }



    for (int i=0;i<points.size();++i)
    {
        if(points.at(i).x()<min_x)
        {
            min_x=points.at(i).x();
        }
        else if(points.at(i).x()>min_x)
        {


        }
        if(points.at(i).y()<min_y)
        {
            min_y=points.at(i).y();

        }
        else if(points.at(i).y()>min_y)
        {

        }
    }


    b.setOrigin(ctm::Point( points[0].x(),points[0].y()));

    b.setWidth(abs(max_x-min_x));
    b.setHeight(abs(max_y-min_y));
    return b;
}




} // namespace shapes
} // namespace ctm
