#include "gtest/gtest.h"
#include "console_canvas/Canvas.h"

using namespace ctm;

namespace {

TEST(CanvasTest, ConstructorsTest)
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
}

TEST(CanvasTest, pixelTest)
{
	Canvas canvas(Size(56, 78)); 
	canvas.clear(); // Очищаем канвас, цвет всех пикселей == ' '
	Color pclr = canvas.pixel(Point(2, 3)); // Поулчаем цвет случайной точки
	EXPECT_EQ(pclr, ' '); // Сравниваем
}

TEST(CanvasTest, setPixelTest)
{
	Canvas canvas(Size(56, 78));
	Color pclr = 'r'; // Задаем красный цвет
	canvas.setPixel(Point(2, 3), pclr); // Задаем пикселю карсный цвет
	EXPECT_EQ(canvas.pixel(Point(2, 3)), pclr); // Получаем цвет пикселя и сравниваем его с исходным
}

TEST(CanvasTest, clearTest)
{
	Canvas canvas(Size(56, 78));
	canvas.clear();
	for (int i = 0; i < canvas.size().width(); i++)
		for (int j = 0; j < canvas.size().height(); j++)
			EXPECT_EQ(canvas.pixel(Point(i, j)), ' ');
}

} // anonymous namespace
