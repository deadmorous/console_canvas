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

TEST(SceneTest, all_figures_persistent)
{

 std::ofstream saveStream("save_all.txt");
    //инициализация фигур
    auto Polygon = std::make_shared<ctm::shapes::Polygon>();
   Polygon->points.push_back(ctm::Point(0,0));
  Polygon->points.push_back(ctm::Point(6,7));
   Polygon->points.push_back(ctm::Point(0,20));
   Polygon->setFillStyle(std::make_shared<SimpleFillStyle>('t'));
  Polygon->filled=false;

  auto circle = std::make_shared<ctm::shapes::Circle>();
     Point p(15,15);
     circle->setCenter(p );
     circle->setRadius( 4);
     circle->setFillStyle(std::make_shared<SimpleFillStyle>('t'));
     circle->filled=true;


    auto triangle = std::make_shared<ctm::shapes::Triangle>();
        triangle->points.push_back(ctm::Point(0,0));
        triangle->points.push_back(ctm::Point(7,15));
        triangle->points.push_back(ctm::Point(16,20));
        triangle->setFillStyle(std::make_shared<SimpleFillStyle>('t'));
        triangle->filled=true;


       auto rect = std::make_shared<ctm::shapes::Rectangle>();
       rect->left_bottom_point=ctm::Point(1,1);
       rect->right_top_point=ctm::Point(17,17);
       rect->setFillStyle(std::make_shared<SimpleFillStyle>('g'));
       rect->filled=true;

       //инициализация boolean надо отдать 2 фигуры
       auto boolean = std::make_shared<ctm::shapes::Boolean>();
       boolean->addShape(rect);
       boolean->addShape(circle);



    //Сцена
    ctm::Scene MainScene;
    //Холст
    Canvas main_canvas(ctm::Size(50,30));

     // Чтобы все отрисовать, надо добавить всё в сцену
    MainScene.addShape(Polygon);
    MainScene.addShape(triangle);
    MainScene.addShape(boolean);
     //Сохраняем сцену
    MainScene.write(saveStream);

    //Отрисовываем все фигуры на сцене
    MainScene.paint(main_canvas);


    cout<<"bounding boxes \n";
    MainScene.boundingBox(); // вывод наибольших размеров фигур

    saveStream.close(); //закрыть поток
    cout<<"load stream \n";
    std::ifstream loadStream("save_all.txt");
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
