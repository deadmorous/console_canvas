#include "console_canvas/Point.h"

#include "gtest/gtest.h"

using namespace ctm;

namespace {

TEST(PointTest, Constructors)
{
    Point defaultConstructedPoint;
    EXPECT_EQ(0, defaultConstructedPoint.x());
    EXPECT_EQ(0, defaultConstructedPoint.y());
    Point pt(12, 34);
    EXPECT_EQ(12, pt.x());
    EXPECT_EQ(34, pt.y());
}

TEST(PointTest, Copying)
{
    Point pt(12, 34);
    Point ptCopy = pt;
    EXPECT_EQ(12, ptCopy.x());
    EXPECT_EQ(34, ptCopy.y());
    Point pt2(56, 78);
    pt = pt2;
    EXPECT_EQ(56, pt.x());
    EXPECT_EQ(78, pt.y());
}

TEST(PointTest, Comparison)
{
    Point pt1(12, 34);
    Point pt2(12, 34);
    Point pt3(13, 34);
    Point pt4(12, 35);
    Point pt5(13, 35);
    EXPECT_TRUE(pt1 == pt2);
    EXPECT_TRUE(pt1 != pt3);
    EXPECT_TRUE(pt1 != pt4);
    EXPECT_TRUE(pt1 != pt5);
    EXPECT_FALSE(pt1 != pt2);
    EXPECT_FALSE(pt1 == pt3);
    EXPECT_FALSE(pt1 == pt4);
    EXPECT_FALSE(pt1 == pt5);
}

TEST(PointTest, GettersAndSetters)
{
    Point pt;
    pt.setX(123);
    EXPECT_EQ(123, pt.x());
    EXPECT_EQ(0, pt.y());
    pt.setY(456);
    EXPECT_EQ(123, pt.x());
    EXPECT_EQ(456, pt.y());
}

TEST(PointTest, Arithmetics)
{
    Point pt1(1, 2), pt2(5,7);
    auto d = pt2 - pt1;
    EXPECT_EQ(4, d.width());
    EXPECT_EQ(5, d.height());
}

} // anonymous namespace
