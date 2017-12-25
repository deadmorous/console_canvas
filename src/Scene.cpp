#include "console_canvas/Scene.h"


#include <iostream>
#include <iterator>
#include <vector>

//Конструктор сцены.
ctm::Scene::Scene()
{

}

//Get-метод
std::vector<std::shared_ptr<ctm::Shape> > ctm::Scene::shapes() const
{
    return m_shapes;
}


//Добавление в контейнер фигуры.
void ctm::Scene::addShape(const std::shared_ptr<ctm::Shape> &shape)
{
    m_shapes.push_back(shape);
}


//Функция рисования на холсте.
void ctm::Scene::paint(Canvas& c) const
{
    //Возвращение массива указателей фигур.
    std::vector<std::shared_ptr<Shape>> temp_shapes=shapes();
    //Отрисовка по порядку, у каждой фигуры определен виртуальный метод отрисовки.
    for(size_t i=0;i<temp_shapes.size();++i)
    {
        temp_shapes.at(i)->paint(c);
    }

    // Получение массива символов холста
    std::vector<char> temp=c.Matrix_color();
    //Получение размера холста, сделано для простоты обращения
    Size temp_size=c.size();

    //Получение начала и конца , сделано для простоты обращения
    //авто переменная имеет вид std::vector<char>::iterator;

    auto itStartLine= temp.begin();
    auto itEndLine=temp.begin();

    //Чтобы отразить коодинатную ось по оси y, используеся алгоритм обратного перебора
    std::reverse(std::begin(temp), std::end(temp));

    //вывод массива в консоль
    for(int i=0;i<temp_size.height();++i)
    {

        std::advance(itEndLine, temp_size.width());//смещение итератора конца символов в массиве на число ширины холста. Аналог арифметики указателей.
        std::reverse_copy (itStartLine,itEndLine, std::ostream_iterator<char>(std::cout, "")); //Обратное копирование в поток
        std::advance(itStartLine, temp_size.width()); // повторное смещение итератора начала к концу

        std::cout<<'\n';
    }

}
//выводит размер всех фигур на сцене
ctm::Box ctm::Scene::boundingBox() const
{
    std::vector<std::shared_ptr<Shape>> temp_shapes=shapes();
    for(size_t i=0;i<temp_shapes.size();++i)
    {
        Box temp_box= temp_shapes.at(i)->boundingBox();
        std::cout<<temp_box<<std::endl;
    }
}
//Запись каждой фигуры по-своему
void ctm::Scene::write(std::ostream &s) const
{
    std::vector<std::shared_ptr<Shape>> temp_shapes=shapes();
    for(size_t i=0;i<temp_shapes.size();++i)
    {
        temp_shapes.at(i)->write(s);
    }
}


//Чтение каждой фигуры по-своему
void ctm::Scene::read(std::istream &s)
{
    std::string tempRead; // в первой строке каждой фигуры в файле записи описан вид фигуры(необходимо для чтения определенными классами)


    while(!s.eof())// пока не будет достигнут конец файлы
    {
        std::getline(s, tempRead); //получение первой строки

        // если имя равно boolean то в heap памяти выделяется место под создание этого класса и создается умный указатель
        //потом этот класс заполняется значениями из текстового файла
        // и фигура вида boolean добавляется в контейнер scene
        // все остальные фигуры читаются также
        if(tempRead.c_str()==std::string("Boolean"))
        {
            auto c1 = std::make_shared<ctm::shapes::Boolean>();
            c1->read(s);
            this->addShape(c1);
        }
        if(tempRead.c_str()==std::string("Circle"))
        {
            auto c1 = std::make_shared<ctm::shapes::Circle>();
            c1->read(s);
            this->addShape(c1);
        }
        if(tempRead.c_str()==std::string("Polygon"))
        {
            auto c1 = std::make_shared<ctm::shapes::Polygon>();
            c1->read(s);
            this->addShape(c1);
        }
        if(tempRead.c_str()==std::string("Rectangle"))
        {
            auto c1 = std::make_shared<ctm::shapes::Rectangle>();
            c1->read(s);
            this->addShape(c1);
        }
        if(tempRead.c_str()==std::string("Triangle"))
        {
            auto c1 = std::make_shared<ctm::shapes::Triangle>();
            c1->read(s);
            this->addShape(c1);
        }
    }

}
