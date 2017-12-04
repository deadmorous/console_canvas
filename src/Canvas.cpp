#include "console_canvas/Canvas.h"

namespace ctm {

// TODO KB

Canvas::Canvas()
    : WithSize(Size(79, 23))
{
    // Резервируем память для всех пикселей холста
    matrix_color.resize(this->size().height() * this->size().width());
}

Canvas::Canvas(const Size& size)
    : WithSize(size)
{
    // Резервируем память для всех пикселей холста
    matrix_color.resize(size.height() * size.width());
}

void Canvas::clear(Color color)
{
    // Перебираем все пиксели холста и меняем их цвет на тот, который был передан в функции
    for (char & point_color : matrix_color)
        point_color = color;
}

Color Canvas::pixel(const Point& p) const
{
    return matrix_color[(p.x() - 1) * this->size().width() + p.y()];
}

void Canvas::setPixel(const Point& p, Color color)
{
    matrix_color[(p.x() - 1) * this->size().width() + p.y()] = color;
}

} // namespace ctm
