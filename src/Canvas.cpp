#include "console_canvas/Canvas.h"

namespace ctm {

// TODO KB

Canvas::Canvas()
    : WithSize(Size(79, 23))
{
    // Резервируем память для всех пикселей холста
    matrix_color.resize(size().height() * size().width());
    clear();
}

Canvas::Canvas(const Size& size)
    : WithSize(size)
{
    // Резервируем память для всех пикселей холста
    matrix_color.resize(size.height() * size.width());
    clear();
}

void Canvas::clear(Color color)
{
    // Перебираем все пиксели холста и меняем их цвет на тот, который был передан в функции
    std::fill(matrix_color.begin(), matrix_color.end(), color);
}

Color Canvas::pixel(const Point& p) const
{
    if (p.x() < size().width() && p.y() < size().height())
        return matrix_color[p.x()*size().width() + p.y()];
    else
        return '-';
}

void Canvas::setPixel(const Point& p, Color color)
{
    if (p.x() < size().width() && p.y() < size().height())
        matrix_color[p.x()*size().width() + p.y()] = color;
}

} // namespace ctm
