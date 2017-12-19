#include "console_canvas/shapes/Polygon.h"
#include <iostream>
#include <math.h>
namespace ctm {
namespace shapes {
# define EPSILON 0.95f

void Polygon::paintLine(Point p1, Point p2, Canvas &c) const
{
    float phi= atan2(p2.x()-p1.x(),p2.y()-p1.y());


    std::vector<int> x;
    std::vector<int> y;

    if(abs(p2.x()-p1.x())<c.getCanvas_size().width())
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
    else if(abs(p2.x()-p1.x())>c.getCanvas_size().width())
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


     b.setOrigin(ctm::Point( points[0].x(),points[0].y()));

     b.setWidth(abs((points[points.size()-1].x()-points[0].x())));
     b.setHeight(abs((points[points.size()-1].y()-points[0].y())));
    return b;
}

} // namespace shapes
} // namespace ctm

