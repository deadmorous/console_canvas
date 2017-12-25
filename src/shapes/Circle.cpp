#include "console_canvas/shapes/Circle.h"
#include "console_canvas/SimpleFillStyle.h"
#include <ostream>
#include <iostream>
#include <memory.h>
namespace ctm {
namespace shapes {

/*! Функция заполнения массива окружностью
 * \anchor Полищук Леонид
 * \param [in] c − Холст
 *
 */



void Circle::drawCircle(Canvas& c) const
{
    int x0 = center->x();
    int y0 = center->y();

    int x = radius;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {

        FillStyle *temp=this->fillStyle().get();
        temp->strokePixel(c, ctm::Point(x0+x,y0 + y));

        temp->strokePixel(c, ctm::Point(x0 + y, y0 + x));
        temp->strokePixel(c, ctm::Point(x0 - y, y0 + x));
        temp->strokePixel(c, ctm::Point(x0 - x, y0 + y));
        temp->strokePixel(c, ctm::Point(x0 - x, y0 - y));
        temp->strokePixel(c, ctm::Point(x0 - y, y0 - x));
        temp->strokePixel(c, ctm::Point(x0 + y, y0 - x));
        temp->strokePixel(c, ctm::Point(x0 + x, y0 - y));

        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

void Circle::paint(Canvas& canvas_out) const
{
    if(this->filled==false)
    {
        this->drawCircle(canvas_out);
    }

    if(this->filled==true)
    {

        Canvas *c=new Canvas(canvas_out.size()) ;

        this->drawCircle(*c);


        struct counter
        {
            bool active;
            int fillrange;
            ctm::Point start_marker;
        };


        std::vector<counter> count_vector;
        char thisPixel;
        char previousPixel;

        for(int j=0 ;j<c->size().height();++j)
        {
            for(int i=0 ;i<c->size().width();++i)
            {
                thisPixel=c->pixel(Point(i+1,j));
                previousPixel=c->pixel(Point(i,j));


                if(  ( previousPixel==c->backGround_color()  &&   thisPixel== this->fillStyle()->m_fillStyleChild->color()  ) )
                {

                    struct counter count1={false,0,ctm::Point(0,0)};
                    count1.active=true;

                    count1.start_marker=ctm::Point(i,j);
                    count_vector.push_back(count1);
                }
                if( count_vector.size()!=0  && (  previousPixel==  this->fillStyle()->m_fillStyleChild->color() &&  thisPixel==c->backGround_color() ) )
                {
                    count_vector.back().active=false;
                }


                if(count_vector.size()!=0&&count_vector.back().active==true)
                {
                    count_vector.back().fillrange++;
                }

            }
        }


        for(int k=0;k<count_vector.size();++k)
        {
            for(int i=0;i<count_vector.at(k).fillrange;++i)
            {
                c->setPixel(Point(count_vector.at(k).start_marker.x()+i,count_vector.at(k).start_marker.y()),Color('0'));
            }
        }

count_vector.clear();

        Point start;
        Point end;

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

delete c;
    }
}


Box Circle::boundingBox() const
{
    //  std::cout<<"circleBB"<<std::endl;
    Box b;
    b.setOrigin(ctm::Point(center->x(),center->y()));
    b.setWidth(abs((center->x()+radius)-(center->x()-radius)));
    b.setHeight(abs((center->y()+radius)-(center->y()-radius)));

    return b;
}


Point *Circle::getcenter() const
{
    return this->center.get();
}

void Circle::setCenter(Point &p2)
{
    auto temp_point = std::make_shared<ctm::Point>();

    temp_point->setX( p2.x());
    temp_point->setY(p2.y());
    this->center=temp_point;
}

size_t Circle::getradius() const
{
    return radius;
}

void Circle::setRadius(int rad)
{
    radius=rad;
}




} // namespace shapes
} // namespace ctm
