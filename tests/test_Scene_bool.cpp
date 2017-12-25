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
namespace {

TEST(SceneTest, boolean)
{
    //инициализация фигур
    auto circle = std::make_shared<ctm::shapes::Circle>();
    Point p(15,15);
    circle->setCenter(p );
    circle->setRadius( 4);
    circle->setFillStyle(std::make_shared<SimpleFillStyle>('t'));
    circle->filled=true;

    auto rect = std::make_shared<ctm::shapes::Rectangle>();
    rect->left_bottom_point=ctm::Point(1,1);
    rect->right_top_point=ctm::Point(17,17);
    rect->setFillStyle(std::make_shared<SimpleFillStyle>('g'));
    rect->filled=true;

    //инициализация boolean надо отдать 2 фигуры
    auto boolean = std::make_shared<ctm::shapes::Boolean>();
    boolean->addShape(rect);
    boolean->addShape(circle);

    //поток сохранения
    std::ofstream saveStream("saves_bool.txt");

    //Сцена
    ctm::Scene MainScene1;
    //Холст
    Canvas main_canvas(ctm::Size(50,30));

    // Чтобы все отрисовать, надо добавить boolean в сцену
    MainScene1.addShape(boolean);


    //Сохраняем сцену
    MainScene1.write(saveStream);

    //Отрисовываем все фигуры на сцене
    MainScene1.paint(main_canvas);


    cout<<"bounding boxes \n";
    MainScene1.boundingBox(); // вывод наибольших размеров фигур
    //закрыть поток
    saveStream.close();
    cout<<"load stream \n";
    std::ifstream loadStream("saves_bool.txt");
    cout<<"next \n";
    MainScene1.read(loadStream);//Чтение из файла(создание экземпляров классов по значениям из файла)

    cout<<"clear canvas color to + \n";
    main_canvas.clear(Color('+'));//Очистка холста
    cout<< "loaded  \n";

    // Повторная отрисовка сцены
    MainScene1.paint(main_canvas);
    //закрыть поток
    loadStream.close();
    // google test ожидает ширину холста
    EXPECT_EQ(50,main_canvas.size().width());
}



} // anonymous namespace
