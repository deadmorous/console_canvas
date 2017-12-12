#include "gtest/gtest.h"
#include "console_canvas/Canvas.h"

using namespace ctm;

namespace {

TEST(CanvasTest, Constructors)
{
    Canvas defaultConstructedCanvas;
    auto size = defaultConstructedCanvas.size();
    EXPECT_EQ(size.width(), 79);
    EXPECT_EQ(size.height(), 23);
    Canvas canvas(Size(56, 78));
    size = canvas.size();
    EXPECT_EQ(size.width(), 56);
    EXPECT_EQ(size.height(), 78);
}

} // anonymous namespace
