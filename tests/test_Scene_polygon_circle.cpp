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

TEST(SceneTest, polygon_circle_persistent)
{
    //инициализация фигур
    auto Polygon = std::make_shared<ctm::shapes::Polygon>();
   Polygon->points.push_back(ctm::Point(0,0));
  Polygon->points.push_back(ctm::Point(7,15));
   Polygon->points.push_back(ctm::Point(16,20));
   Polygon->setFillStyle(std::make_shared<SimpleFillStyle>('t'));
  Polygon->filled=true;

  auto circle = std::make_shared<ctm::shapes::Circle>();
     Point p(15,15);
     circle->setCenter(p );
     circle->setRadius( 4);
     circle->setFillStyle(std::make_shared<SimpleFillStyle>('t'));
     circle->filled=true;
    std::ofstream saveStream("save_polygon_circle.txt");


    //Сцена
    ctm::Scene MainScene;
    //Холст
    Canvas main_canvas(ctm::Size(50,30));

     // Чтобы все отрисовать, надо добавить всё в сцену
    MainScene.addShape(Polygon);
    MainScene.addShape(circle);

     //Сохраняем сцену
    MainScene.write(saveStream);

    //Отрисовываем все фигуры на сцене
    MainScene.paint(main_canvas);


    cout<<"bounding boxes \n";
    MainScene.boundingBox(); // вывод наибольших размеров фигур

    saveStream.close(); //закрыть поток
    cout<<"load stream \n";
    std::ifstream loadStream("save_polygon_circle.txt");
    cout<<"next \n";
    MainScene.read(loadStream); //Чтение из файла(создание экземпляров классов по значениям из файла)

    cout<<"clear canvas color to + \n";
    main_canvas.clear(Color('+')); //Очистка холста
    cout<< "loaded  \n";
    // Повторная отрисовка сцены
    MainScene.paint(main_canvas);
     //закрыть поток
    loadStream.close();
    // google test ожидает ширину холста
    EXPECT_EQ(50,main_canvas.size().width());
}



} // anonymous namespace
