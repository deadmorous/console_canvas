#include "console_canvas/shapes/Polygon.h"

#include <iostream>
#include <math.h>
namespace ctm {
namespace shapes {


void Polygon::paintLine(Point p1, Point p2, Canvas &c) const
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


    }
    else if(abs(p2.x()-p1.x())>c.size().width())
    {

    }

    for(int i=0;i<x.size();++i)
    {
        ctm::Point p (x[i], y[i]);
        c.setPixel(p,ctm::Color('*') );
    }

}



void Polygon::paint(Canvas& c) const
{
    Point first;
    Point end;

    for(int i=0;i<points.size();++i)
    {
        first=points[i];
        end=points[i+1];

        paintLine(first,end,c);
        first=end;
    }

}



Box Polygon::boundingBox() const
{
    Box b;
   // std::cout<<"polygonBB"<<std::endl;

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
