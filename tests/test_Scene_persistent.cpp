#include <iostream>

#include "console_canvas/Box.h"
#include "console_canvas/Shape.h"
#include "console_canvas/Scene.h"

#include "console_canvas/shapes/Polygon.h"
#include "console_canvas/shapes/Circle.h"
#include "console_canvas/shapes/Rectangle.h"
#include "console_canvas/FillStyle.h"
#include "console_canvas/SimpleFillStyle.h"
#include "console_canvas/SimpleStrokeStyle.h"
#include <algorithm>


#include <sstream>
#include <iterator>
#include <vector>
#include <string>

#include <istream>
#include <ostream>

#include <fstream>
#include "gtest/gtest.h"

using namespace ctm;
using namespace std;
namespace one{

TEST(SceneTest, rectangle_circle_persistent)
{
    //figures initialization
    auto circle = std::make_shared<ctm::shapes::Circle>();
    Point p(5,15);
    circle->setCenter(p );
    circle->setRadius( 3);

    circle->setFillStyle(std::make_shared<SimpleFillStyle>('t'));
    circle->filled=true;

    auto rect = std::make_shared<ctm::shapes::Rectangle>();
    rect->left_bottom_point=ctm::Point(15,2);
    rect->right_top_point=ctm::Point(20,20);
    rect->setFillStyle(std::make_shared<SimpleFillStyle>('g'));
    rect->filled=true;
    std::ofstream saveStream("save_shapes.txt");


    //containers initialization

    ctm::Scene MainScene;
    Canvas main_canvas(ctm::Size(50,30));

    //!add shapes to Scene
    MainScene.addShape(circle);
    MainScene.addShape(rect);

    //!save shapes from Scene
    MainScene.write(saveStream);

    //!paint shapes from Scene
    MainScene.paint(main_canvas);


    cout<<"bounding boxes \n";
    MainScene.boundingBox();

    saveStream.close();
    cout<<"load stream \n";
    std::ifstream loadStream("save_shapes.txt");
    cout<<"next \n";
    MainScene.read(loadStream);

    cout<<"clear canvas color to + \n";
    main_canvas.clear(Color('+'));
    cout<< "loaded  \n";
    MainScene.paint(main_canvas);

    loadStream.close();

    EXPECT_EQ(50,main_canvas.size().width());
}



} // anonymous namespace
