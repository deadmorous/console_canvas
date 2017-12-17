#include "gtest/gtest.h"
#include "console_canvas/Canvas.h"

using namespace ctm;

namespace {

TEST(CanvasTest, Constructors)
{
    // Констркутор по умолчанию
    Canvas defaultConstructedCanvas;
    auto size = defaultConstructedCanvas.size();
    EXPECT_EQ(size.width(), 79);
    EXPECT_EQ(size.height(), 23);

    // Конструктор с параметрами
    Canvas canvas(Size(56, 78));
    size = canvas.size();
    EXPECT_EQ(size.width(), 56);
    EXPECT_EQ(size.height(), 78);

    // Установить пиксель
    Color pclr = 'r';
    canvas.setPixel(Point(2, 3), pclr);
    EXPECT_EQ(canvas.pixel(Point(2, 3)), pclr);

    // Вернуть цвет пикселя
    pclr = canvas.pixel(Point(2, 3));
    EXPECT_EQ(pclr, ' ');

    // Очистить
    canvas.clear();
    for (int i = 0; i < canvas.size().width(); i++)
        for(int j = 0; j < canvas.size().height(); j++)
            EXPECT_EQ(canvas.pixel(Point(i, j)), ' ');
}

} // anonymous namespace
